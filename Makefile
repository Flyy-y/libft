# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/27 14:18:33 by cbreisch          #+#    #+#              #
#    Updated: 2019/01/15 19:51:18 by cbreisch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET		:= libft.a

DEBUG		:= FALSE
LIBRARY		:= TRUE

SRCDIR		:= srcs
INCDIR		:= includes
BUILDDIR	:= build
TARGETDIR	:= bins
SRCEXT		:= c
OBJEXT		:= o

CC			:= cc
CFLAGS		:= -Wall -Wextra
MAKEDEP		:=
LIB			:= libft/bin/libft.a
INC			:= -I$(INCDIR)
LINKER		:= ar
INDEXER		:= ranlib
RM			:= rm
MKDIR		:= mkdir

SOURCES     := $(shell du -a $(SRCDIR) | awk '{print $$2}' | grep '\.$(SRCEXT)')
OBJECTS     := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

COM_COLOR	= \033[0;94m
OBJ_COLOR	= \033[0;90m
TAR_COLOR	= \033[0;92m
OK_COLOR	= \033[0;32m
ERROR_COLOR	= \033[0;31m
WARN_COLOR	= \033[0;33m
NO_COLOR	= \033[m

OK_STRING	= "[OK]"
ERROR_STRING= "[ERROR]"
WARN_STRING	= "[WARNING]"
COM_STRING	= "Compiling"
LIN_STRING	= "Linking"
IND_STRING	= "Indexing"

ifeq ($(DEBUG), TRUE)
	CFLAGS += -g
endif

all: makedep directories $(TARGET) #Create dirs and build target

re: fclean all #Fullclean + build

directories: #Create directories
	@$(MKDIR) -p $(TARGETDIR)
	@$(MKDIR) -p $(BUILDDIR)

clean: #Delete build directory
	@$(RM) -rf $(BUILDDIR)

fclean: clean #Delete build and target directories
	@$(RM) -rf $(TARGETDIR) $(TARGET).dSYM
	@$(foreach dep,$(MAKEDEP),make -C $(dep) fclean;)

norm:
	@norminette $(SOURCES)

normcheck:
	@echo "$(shell norminette $(SOURCES) | grep -E '^(Error|Warning)')" Norme check OK

makedep:
	@$(foreach dep,$(MAKEDEP),make -C $(dep);)

ifeq ($(LIBRARY), FALSE)
$(TARGET): $(OBJECTS) #Build objects, then target
	@$(CC) -o $(TARGETDIR)/$(TARGET) $^ $(LIB) 2> $@.log; \
		RESULT=$$?; \
		if [ $$RESULT -ne 0 ]; then \
			printf "%-60b%b" "$(COM_COLOR)$(LIN_STRING)$(TAR_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
		elif [ -s $@.log ]; then \
			printf "%-60b%b" "$(COM_COLOR)$(LIN_STRING)$(TAR_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"; \
		else  \
			printf "%-60b%b" "$(COM_COLOR)$(LIN_STRING)$(TAR_COLOR) $@" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
		fi; \
		cat $@.log; \
		rm -f $@.log; \
		exit $$RESULT
else
$(TARGET): $(OBJECTS) #Build objects, then link target
	@$(LINKER) -rcs $(TARGETDIR)/$(TARGET) $^ 2> $@.log; \
		RESULT=$$?; \
		if [ $$RESULT -ne 0 ]; then \
			printf "%-60b%b" "$(COM_COLOR)$(LIN_STRING)$(TAR_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
		elif [ -s $@.log ]; then \
			printf "%-60b%b" "$(COM_COLOR)$(LIN_STRING)$(TAR_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"; \
		else  \
			printf "%-60b%b" "$(COM_COLOR)$(LIN_STRING)$(TAR_COLOR) $@" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
		fi; \
		cat $@.log; \
		rm -f $@.log; \
		exit $$RESULT
	@$(INDEXER) $(TARGETDIR)/$(TARGET) 2> $@.log; \
		RESULT=$$?; \
		if [ $$RESULT -ne 0 ]; then \
			printf "%-60b%b" "$(COM_COLOR)$(IND_STRING)$(TAR_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
		elif [ -s $@.log ]; then \
			printf "%-60b%b" "$(COM_COLOR)$(IND_STRING)$(TAR_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"; \
		else  \
			printf "%-60b%b" "$(COM_COLOR)$(IND_STRING)$(TAR_COLOR) $@" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
		fi; \
		cat $@.log; \
		rm -f $@.log; \
		exit $$RESULT
endif

#Compile objects
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@$(MKDIR) -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $< 2> $@.log; \
		RESULT=$$?; \
		if [ $$RESULT -ne 0 ]; then \
			printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
		elif [ -s $@.log ]; then \
			printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"; \
		else  \
			printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
		fi; \
		cat $@.log; \
		rm -f $@.log; \
		exit $$RESULT

nicemoulinette:
	@(read -p "Are you sure ? [y/N]: " sure && case "$$sure" in [yY]) true;; *) false;; esac)
	@mv $(SOURCES) .
	@mv $(shell du -a $(INCDIR) | awk '{print $$2}' | grep '\.h') .
	@$(RM) -rf $(SRCDIR)
	@$(RM) -rf $(INCDIR)

#Non-File Targets
.PHONY: all re clean fclean directories norm normcheck makedep nicemoulinette
