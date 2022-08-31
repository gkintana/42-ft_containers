# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/06 17:01:53 by gkintana          #+#    #+#              #
#    Updated: 2022/08/31 12:45:20 by gkintana         ###   ########.fr        #
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
OBJ_FT		=	ft_containers
OBJ_STD		=	std_containers

SRCS		=	main.cpp \
				vector_construction.cpp
OBJS_FT		=	$(addprefix $(OBJ_DIR)/$(OBJ_FT)/, $(SRCS:%cpp=%o))
OBJS_STD	=	$(addprefix $(OBJ_DIR)/$(OBJ_STD)/, $(SRCS:%cpp=%o))

CXX			=	c++
CPPFLAGS	=	-std=c++98 -g -Wall -Wextra -Werror
RM			=	rm -rf

DEFAULT		=	"\033[0m"
RED			=	"\033[0;31m"
GREEN		=	"\033[1;32m"
CYAN		=	"\033[3;36m"
PURPLE		=	"\033[0;35m"

$(OBJ_DIR)/$(OBJ_FT)/%.o : $(SRC_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR)/$(OBJ_FT)
			@printf $(CYAN)
			@printf "\033[A\033[2K\r"
			$(CXX) $(CPPFLAGS) -I$(INC_DIR1) -I$(INC_DIR2) -D$(DEF_FT) -c $< -o $@

$(OBJ_DIR)/$(OBJ_STD)/%.o : $(SRC_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR)/$(OBJ_STD)
			@printf $(CYAN)
			@printf "\033[A\033[2K\r"
			$(CXX) $(CPPFLAGS) -I$(INC_DIR1) -I$(INC_DIR2) -D$(DEF_STD) -c $< -o $@

all:		$(FT) $(STD)

$(FT):		$(OBJS_FT)
			@$(CXX) $(CPPFLAGS) $(OBJ_DIR)/$(OBJ_FT)/main.o -o $@
			@echo $(DEFAULT)$(GREEN)"ft_containers Ready\n"$(DEFAULT)

$(STD):		$(OBJS_STD)
			@$(CXX) $(CPPFLAGS) $(OBJ_DIR)/$(OBJ_STD)/main.o -o $@
			@echo $(DEFAULT)$(GREEN)"std_containers Ready"$(DEFAULT)

clean:
			@$(RM) $(OBJS_FT) $(OBJS_STD) $(OBJ_DIR)
			@echo $(RED)"Deleted object files"$(DEFAULT)

fclean:		clean
			@$(RM) $(FT) $(STD)
			@echo $(RED)"Deleted executable file"$(DEFAULT)

re:			fclean all

.PHONY:		all clean fclean re
