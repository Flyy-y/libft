# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/27 14:18:33 by cbreisch          #+#    #+#              #
#    Updated: 2018/12/06 18:29:14 by cbreisch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUG		= FALSE

SRCS 		:= $(shell du -a | awk '{print $$2}' | grep '\.c')
NAME		= libft.a
OBJS		= $(SRCS:.c=.o)
INCLUDES	= includes

CC			= cc
LINKER		= ar -rcs
INDEXER		= ranlib
CFLAGS		= -I$(INCLUDES) -W -Wall -Wextra -Werror
RM			= rm -rf

ifeq ($(DEBUG),TRUE)
		CFLAGS += -g
		NAME :=$(NAME).debug
endif

all	: $(NAME)

$(NAME)	:	$(OBJS)
		$(LINKER) -rcs $(NAME) $(OBJS)
		$(INDEXER) $(NAME)

clean	:
		$(RM) $(OBJS)

ifeq ($(DEBUG),TRUE)
fclean	:	clean
		$(RM) $(NAME) $(NAME).dSYM
else
fclean	:	clean
		$(RM) $(NAME)
endif

re		:	fclean all

.PHONY	:	clean