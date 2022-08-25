# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/06 17:01:53 by gkintana          #+#    #+#              #
#    Updated: 2022/08/25 11:29:59 by gkintana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT			=	ft_containers
STD			=	std_containers

INC_DIR		=	include
SRC_DIR		=	sources
OBJ_DIR		=	objects

SRCS		=	vector_tests.cpp

OBJS_FT		=	$(addprefix $(OBJ_DIR)/, $(SRCS:%cpp=%o))
OBJS_SRC	=	$(addprefix $(OBJ_DIR)/, $(SRCS:%cpp=%o))

CXX			=	c++
CPPFLAGS	=	-std=c++98 -g -Wall -Wextra -Werror
RM			=	rm -rf

DEFAULT		=	"\033[0m"
RED			=	"\033[0;31m"
GREEN		=	"\033[1;32m"
CYAN		=	"\033[3;36m"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
			mkdir -p $(OBJ_DIR)
			@printf $(CYAN)
			@printf "\033[A\033[2K\r"
			$(CXX) $(CPPFLAGS) -I$(INC_DIR) -D CONTAINER_TYPE=ft -c $< -o $@
			$(CXX) $(CPPFLAGS) -I$(INC_DIR) -D CONTAINER_TYPE=std -c $< -o $@

all:		$(FT) $(STD)

$(FT):		$(OBJS_FT)
			@$(CXX) $(CPPFLAGS) $(OBJS_FT) -o $@
			@echo $(DEFAULT)$(GREEN)"ft_containers Ready"$(DEFAULT)

$(STD):		$(OBJS_SRC)
			@$(CXX) $(CPPFLAGS) $(OBJS_SRC) -o $@
			@echo $(DEFAULT)$(GREEN)"std_containers Ready"$(DEFAULT)

clean:
			@$(RM) $(OBJS_FT) $(OBJS_STD)
			@echo $(RED)"Deleted object files"$(DEFAULT)

fclean:		clean
			@$(RM) $(FT) $(STD)
			@echo $(RED)"Deleted executable file"$(DEFAULT)

re:			fclean all

.PHONY:		all clean fclean re
