# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 09:52:48 by tatahere          #+#    #+#              #
#    Updated: 2025/02/06 18:18:06 by tatahere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT_DIR	=	./

BIN_DIR		=	$(ROOT_DIR)bin/
SRC_DIR		=	$(ROOT_DIR)src/

RF		=	rm -rf
C++		=	c++

CFLAGS	:=	-Wall -Wextra -Werror -std=c++98

CINC	=	-I./ -I./inc/
CFLAGS	+=	$(CINC)

CDEBUG	=	-g -fsanitize=address
CFLAGS	+=	$(CDEBUG)

NAME	=	test

OBJ		:=	tests.o		\
			Account.o	\

OBJ		:= $(addprefix $(BIN_DIR), $(OBJ))

VPATH	= $(ROOT_DIR)
VPATH	+= $(SRC_DIR)

all	:	$(BIN_DIR) $(NAME)

$(BIN_DIR)		:
	mkdir $(BIN_DIR)

$(NAME) : $(OBJ) Makefile
	$(C++) $(CFLAGS) $(OBJ) -o $(NAME)

$(BIN_DIR)%.o : %.cpp	Makefile $(HDR)
	$(C++) $(CFLAGS) -c $< -o $@

clean :
	$(RF) $(BIN_DIR)

fclean : clean
	$(RF) $(NAME)

re : fclean all

.PHONY:	all clean fclean re
