# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/27 14:18:33 by cbreisch          #+#    #+#              #
#    Updated: 2019/01/15 16:51:33 by cbreisch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET		:= libft

SRCDIR		:= srcs
INCDIR		:= includes
BUILDDIR	:= obj
TARGETDIR	:= bin
SRCEXT		:= c
OBJEXT		:= o
DEBUG		:= FALSE
LIBRARY		:= TRUE

#Flags, Libraries and Includes
CC			:= cc
CFLAGS		:= -Wall -Wextra
LIB			:= 
INC			:= -I$(INCDIR)
LINKER		:= ar
INDEXER		:= ranlib
RM			:= rm
MKDIR		:= mkdir

SOURCES     := $(shell du -a $(SRCDIR) | awk '{print $$2}' | grep '\.$(SRCEXT)')
OBJECTS     := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

ifeq ($(DEBUG), TRUE)
	CFLAGS += -g
endif

all: directories $(TARGET) #Create dirs and build target

re: fclean all #Fullclean + build

directories: #Create directories
	@$(MKDIR) -p $(TARGETDIR)
	@$(MKDIR) -p $(BUILDDIR)

clean: #Delete build directory
	@$(RM) -rf $(BUILDDIR)

fclean: clean #Delete build and target directories
	@$(RM) -rf $(TARGETDIR) $(TARGET).dSYM

norme:
	@echo $(shell norminette $(SOURCES) | grep -E '^(Error|Warning)')

ifeq ($(LIBRARY), FALSE)
$(TARGET): $(OBJECTS) #Build objects, then target
	$(CC) -o $(TARGETDIR)/$(TARGET) $^ $(LIB)
else
$(TARGET): $(OBJECTS) #Build objects, then link target
	$(LINKER) -rcs $(TARGETDIR)/$(TARGET) $^
	$(INDEXER) $(TARGETDIR)/$(TARGET)
endif

#Compile objects
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@$(MKDIR) -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

#Non-File Targets
.PHONY: all re clean fclean directories
