# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 09:52:48 by tatahere          #+#    #+#              #
#    Updated: 2025/02/08 12:58:12 by tatahere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT_DIR	=	./

BIN_DIR		=	$(ROOT_DIR)bin/
SRC_DIR		=	$(ROOT_DIR)src/

RM		=	rm -rf
CXX		=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -I./  -g -std=c++98 -MMD

NAME	=	megaphone

OBJ		:=	megaphone.o	\

OBJ		:=	$(addprefix $(BIN_DIR), $(OBJ))

DEP		:=	$(OBJ :.o=.d)

VPATH	= $(ROOT_DIR)
VPATH	+= $(SRC_DIR)

all	:	$(BIN_DIR) $(NAME)

$(BIN_DIR)		:
	mkdir $(BIN_DIR)

$(NAME) : $(OBJ) Makefile
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(BIN_DIR)%.o : %.cpp	Makefile 
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	$(RM) $(BIN_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

-include $(DEP)

.PHONY:	all clean fclean re
