# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/06 17:01:53 by gkintana          #+#    #+#              #
#    Updated: 2022/08/28 22:53:31 by gkintana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT			=	ft_containers
STD			=	std_containers

DEF_FT		=	NAMESPACE=ft
DEF_STD		=	NAMESPACE=std

INC_DIR1	=	include/containers
INC_DIR2	=	include/utilities
SRC_DIR		=	sources
OBJ_DIR		=	objects

SRCS		=	main.cpp

CXX			=	c++
CPPFLAGS	=	-std=c++98 -g -Wall -Wextra -Werror
RM			=	rm -rf

DEFAULT		=	"\033[0m"
RED			=	"\033[0;31m"
GREEN		=	"\033[1;32m"
CYAN		=	"\033[3;36m"
PURPLE		=	"\033[0;35m"

all:		$(FT) $(STD)

$(FT):
			@printf $(CYAN)
			@mkdir -p $(OBJ_DIR)
			$(CXX) $(CPPFLAGS) -c -I$(INC_DIR1) -I$(INC_DIR2) -D$(DEF_FT) $(SRC_DIR)/$(SRCS) -o $(OBJ_DIR)/$@.o
			@$(CXX) $(CPPFLAGS) $(OBJ_DIR)/$(FT).o -o $@
			@echo $(DEFAULT)$(GREEN)"ft_containers Ready"$(DEFAULT)

$(STD):
			@printf $(CYAN)
			@mkdir -p $(OBJ_DIR)
			$(CXX) $(CPPFLAGS) -c -I$(INC_DIR1) -I$(INC_DIR2) -D$(DEF_STD) $(SRC_DIR)/$(SRCS) -o $(OBJ_DIR)/$@.o
			@$(CXX) $(CPPFLAGS) $(OBJ_DIR)/$(STD).o -o $@
			@echo $(DEFAULT)$(GREEN)"std_containers Ready"$(DEFAULT)

clean:
			@$(RM) $(OBJS_FT) $(OBJS_STD) $(OBJ_DIR)
			@echo $(RED)"Deleted object files"$(DEFAULT)

fclean:		clean
			@$(RM) $(FT) $(STD)
			@echo $(RED)"Deleted executable file"$(DEFAULT)

re:			fclean all

.PHONY:		all clean fclean re
