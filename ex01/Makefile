# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 09:52:48 by tatahere          #+#    #+#              #
#    Updated: 2025/01/31 10:18:08 by tatahere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT_DIR	=	./

BIN_DIR		=	$(ROOT_DIR)bin/
SRC_DIR		=	$(ROOT_DIR)src/

RF		=	rm -rf
C++		=	c++

CFLAGS	=	-Wall -Wextra -Werror -I./  -g -std=c++98

NAME	=	megaphone


OBJ				:=	megaphone.cpp	\

VPATH	= $(ROOT_DIR)
VPATH	+= $(SRC_DIR)

all	:	$(BIN_DIR) $(NAME)

$(BIN_DIR)		:
	mkdir $(BIN_DIR)

$(NAME) : $(OBJ) Makefile
	$(C++) $(CFLAGS) $(OBJ) -o $(NAME)

$(BIN_DIR)%.o : %.c	Makefile $(HDR)
	$(C++) $(CFLAGS) -c $< -o $@

clean :
	$(RF) $(BIN_DIR)

fclean : clean
	$(RF) $(NAME)

re : fclean all

.PHONY:	all clean fclean re
