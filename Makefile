# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 17:36:34 by lvincent          #+#    #+#              #
#    Updated: 2023/05/27 23:16:46 by lvincent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m

RED = \033[0;31m

RED_B = \033[1;31m

YELLOW = \033[1;33m

BLUE = \033[0;34m

RESET = \033[0m

NAME = push_swap

SRC = utils1.c utils2.c init_stack.c main.c parsing.c parsing2.c sort_main.c

OBJ = $(SRC:.c=.o)

CC = clang

LIBFT = ./libft/libft.a

CFLAGS = -Werror -Wall -Wextra -g

all : libft $(NAME)

.c.o :
	@echo -e "$(GREEN)Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ)
	@echo -e "$(BLUE)Compiled object files for $(NAME)$(RESET)"
	@$(CC) $(OBJ) $(LIBFT) $(CFLAGS) -o $(NAME)
	@echo -e "$(YELLOW)Compiled $(NAME)$(RESET)"

libft :
	@make -C ./libft --no-print-directory

clean :
	@rm -f $(OBJ)
	@make clean -C ./libft -s
	@echo -e "$(RED)Removed object files from project and dependencies$(RESET)"

fclean :
	@rm -f $(OBJ)
	@echo -e "$(RED)Removed object files from project and dependencies$(RESET)"
	@rm -f $(NAME)
	@echo -e "$(RED_B)Removed $(NAME)$(RESET)"
	@make fclean -C ./libft -s

re : fclean all

.PHONY : all clean fclean re libft 