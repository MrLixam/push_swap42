# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 17:36:34 by lvincent          #+#    #+#              #
#    Updated: 2023/06/05 23:03:45 by lvincent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m

RED = \033[0;31m

RED_B = \033[1;31m

YELLOW = \033[1;33m

BLUE = \033[0;34m

RESET = \033[0m

NAME = push_swap

SRC = src/utils1.c src/utils2.c src/utils3.c src/init_stack.c src/main.c src/parsing.c src/parsing2.c src/sort_main.c src/complex_sort.c

SRC_B = 

OBJ = $(SRC:.c=.o)

CC = clang

LIBFT = ./libft/libft.a

CFLAGS = -Werror -Wall -Wextra -g

all : libft $(NAME)

.c.o :
	@echo "$(GREEN)Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ)
	@echo "$(BLUE)Compiled object files for $(NAME)$(RESET)"
	@$(CC) $(OBJ) $(LIBFT) $(CFLAGS) -o $(NAME)
	@echo "$(YELLOW)Compiled $(NAME)$(RESET)"

libft :
	@make -C ./libft --no-print-directory

clean :
	@rm -f $(OBJ)
	@make clean -C ./libft -s
	@echo "$(RED)Removed object files from project and dependencies$(RESET)"

fclean :
	@rm -f $(OBJ)
	@echo "$(RED)Removed object files from project and dependencies$(RESET)"
	@rm -f $(NAME)
	@echo "$(RED_B)Removed $(NAME)$(RESET)"
	@make fclean -C ./libft -s

re : fclean all

.PHONY : all clean fclean re libft 
