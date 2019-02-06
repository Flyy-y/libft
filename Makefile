# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/27 14:18:33 by cbreisch          #+#    #+#              #
#    Updated: 2019/02/06 20:29:54 by cbreisch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET		:= libft.a
LIBRARY		:= TRUE

SRCDIR		:= srcs
INCDIR		:= includes
BUILDDIR	:= build
TARGETDIR	:= bin
SRCEXT		:= c
OBJEXT		:= o

CC			:= clang
CFLAGS		:= -Wextra -Wall
MAKEDEP		:= 
LIB			:= 
INC			:= -I$(INCDIR) 
LINKER		:= ar -rcs
RM			:= rm -rf
MKDIR		:= mkdir -p

SOURCES     := $(shell du -a $(SRCDIR) | awk '{print $$2}' | grep '\.$(SRCEXT)')
OBJECTS     := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

CUR_COLOR	:= \033[0;93m
COM_COLOR	:= \033[0;94m
OBJ_COLOR	:= \033[0;90m
TAR_COLOR	:= \033[0;92m
OK_COLOR	:= \033[0;32m
ERROR_COLOR	:= \033[0;31m
WARN_COLOR	:= \033[0;33m
NO_COLOR	:= \033[m

OK_STRING	:= "[OK]"
ERROR_STRING:= "[ERROR]"
WARN_STRING	:= "[WARNING]"
COM_STRING	:= "Compiling"
LIN_STRING	:= "Linking"
IND_STRING	:= "Indexing"
DEL_STRING	:= "Deleted"

all: makedep directories $(TARGET) #Create dirs and build target

re: fclean all #Fullclean + build

fre: depclean fclean all

directories: #Create directories
	@$(MKDIR) -p $(TARGETDIR)
	@$(MKDIR) -p $(BUILDDIR)

clean: #Delete build directory
	@$(RM) $(OBJECTS) $(BUILDDIR) 2> /dev/null
	@printf "%-20b%-55b%b" "$(CUR_COLOR)$(TARGET) > " "$(COM_COLOR)$(DEL_STRING)$(TAR_COLOR) build files" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n";

fclean: clean #Delete build and target directories
	@$(RM) $(TARGETDIR)/$(TARGET) $(TARGETDIR)/$(TARGET).dSYM $(TARGETDIR)
	@printf "%-20b%-55b%b" "$(CUR_COLOR)$(TARGET) > " "$(COM_COLOR)$(DEL_STRING)$(TAR_COLOR) binary files" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n";

depclean:
	@$(foreach dep,$(MAKEDEP),make -C $(dep) fclean;)

norm:
	@norminette $(SOURCES)

normcheck:
	@echo "$(shell norminette $(SOURCES) | grep -E '^(Error|Warning)')" Norme check OK

makedep:
	@$(foreach dep,$(MAKEDEP),make -C $(dep);)

ifeq ($(LIBRARY), FALSE)
$(TARGET): $(OBJECTS) #Build objects, then target
	@$(CC) $(CFLAGS) $(INC) -o $(TARGETDIR)/$(TARGET) $^ $(LIB) 2> $@.log; \
		RESULT=$$?; \
		if [ $$RESULT -ne 0 ]; then \
			printf "%-20b%-55b%b" "$(CUR_COLOR)$(TARGET) > " "$(COM_COLOR)$(LIN_STRING)$(TAR_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
		elif [ -s $@.log ]; then \
			printf "%-20b%-55b%b" "$(CUR_COLOR)$(TARGET) > " "$(COM_COLOR)$(LIN_STRING)$(TAR_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"; \
		else  \
			printf "%-20b%-55b%b" "$(CUR_COLOR)$(TARGET) > " "$(COM_COLOR)$(LIN_STRING)$(TAR_COLOR) $@" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
		fi; \
		cat $@.log; \
		rm -f $@.log; \
		exit $$RESULT
else
$(TARGET): $(OBJECTS) #Build objects, then link target
	@$(LINKER) $(TARGETDIR)/$(TARGET) $^ 2> $@.log; \
		RESULT=$$?; \
		if [ $$RESULT -ne 0 ]; then \
			printf "%-20b%-55b%b" "$(CUR_COLOR)$(TARGET) > " "$(COM_COLOR)$(LIN_STRING)$(TAR_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
		elif [ -s $@.log ]; then \
			printf "%-20b%-55b%b" "$(CUR_COLOR)$(TARGET) > " "$(COM_COLOR)$(LIN_STRING)$(TAR_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"; \
		else  \
			printf "%-20b%-55b%b" "$(CUR_COLOR)$(TARGET) > " "$(COM_COLOR)$(LIN_STRING)$(TAR_COLOR) $@" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
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
			printf "%-20b%-55b%b" "$(CUR_COLOR)$(TARGET) > " "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
		elif [ -s $@.log ]; then \
			printf "%-20b%-55b%b" "$(CUR_COLOR)$(TARGET) > " "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"; \
		else  \
			printf "%-20b%-55b%b" "$(CUR_COLOR)$(TARGET) > " "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
		fi; \
		cat $@.log; \
		rm -f $@.log; \
		exit $$RESULT

nicemoulinette:
	@(read -p "Are you sure ? [y/N]: " sure && case "$$sure" in [yY]) true;; *) false;; esac)
	@mv $(SOURCES) .
	@mv $(shell du -a $(INCDIR) | awk '{print $$2}' | grep '\.h') .
	@$(RM) $(SRCDIR)
	@$(RM) $(INCDIR)

#Non-File Targets
.PHONY: all re clean fclean directories norm normcheck makedep nicemoulinette fre depclean

