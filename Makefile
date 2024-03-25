# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xortega <xortega@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 11:02:31 by xortega           #+#    #+#              #
#    Updated: 2024/03/21 11:35:10 by xortega          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	philo
SRC_PATH	:=	src
OBJ_DIR		:=	obj
SOURCES		:=	philo.c p_parse.c p_atoi.c p_sim.c p_time.c p_actions.c
OBJS		:=	$(SOURCES:%.c=$(OBJ_DIR)/%.o)
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -I./includes

all: $(NAME)

define ASCII                                              

                                                                                   
8 888888888o   8 8888        8  8 8888 8 8888         ,o888888o.     88   d888888o.   
8 8888    `88. 8 8888        8  8 8888 8 8888      . 8888     `88.   8  .`8888:' `88. 
8 8888     `88 8 8888        8  8 8888 8 8888     ,8 8888       `8b  !  8.`8888.   Y8 
8 8888     ,88 8 8888        8  8 8888 8 8888     88 8888        `8b    `8.`8888.     
8 8888.   ,88' 8 8888        8  8 8888 8 8888     88 8888         88     `8.`8888.    
8 888888888P'  8 8888        8  8 8888 8 8888     88 8888         88      `8.`8888.   
8 8888         8 8888888888888  8 8888 8 8888     88 8888        ,8P       `8.`8888.  
8 8888         8 8888        8  8 8888 8 8888     `8 8888       ,8P    8b   `8.`8888. 
8 8888         8 8888        8  8 8888 8 8888      ` 8888     ,88'     `8b.  ;8.`8888 
8 8888         8 8888        8  8 8888 8 888888888888 `8888888P'        `Y8888P ,88P' 


                           
                    '||               .|';  .|';          ||    
                     ||               ||    ||            ||    
                     ||''|, '||  ||` '||'  '||'  .|''|, ''||''  
                     ||  ||  ||  ||   ||    ||   ||..||   ||    
                    .||..|'  `|..'|. .||.  .||.  `|...    `|..' 🍝                                 

endef                                                                                                                                                                                                                                                                                          
export ASCII

$(NAME): $(OBJS)
	@clear
	@sleep 0.2;
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "\033[0;33;3m"
	@echo "$$ASCII"
	@printf "\033[0;32;3mPHILOSOFERS ✅\n\n"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_PATH)/%.c $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -fr $(OBJ_DIR)

fclean:
	@rm -fr $(OBJ_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re