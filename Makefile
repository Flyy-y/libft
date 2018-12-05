

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/27 14:18:33 by cbreisch          #+#    #+#              #
#    Updated: 2018/11/06 14:34:35 by cbreisch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS 		:= $(shell du -a . | awk '{print $$2}' | grep '\.c')
NAME		= libft.a #Output
OBJS		= $(SRCS:.c=.o) #.c > .o
CC			= cc #Compiler
LINKER		= ar #Linker
INDEXER		= ranlib
INCLUDES	= includes #Include directory
CFLAGS		= -I$(INCLUDES) -W -Wall -Wextra -Werror #Compilation's flags
RM			= rm -f #rm with FORCE

all	: $(NAME) #Compile then clean

$(NAME)	:	$(OBJS) #Compile
		$(LINKER) -rcs $(NAME) $(OBJS)
		$(INDEXER) $(NAME)

clean	: #Delete .o files
		$(RM) $(OBJS)

fclean	:	clean #Delete executable
		$(RM) $(NAME)

re		:	fclean all #Delete ex and recompile%%