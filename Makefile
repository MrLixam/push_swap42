# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 17:36:34 by lvincent          #+#    #+#              #
#    Updated: 2023/05/27 14:08:00 by lvincent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = utils1.c utils2.c init_stack.c main.c parsing.c

OBJ = $(SRC:.c=.o)

CC = clang

LIBFT = ./libft/libft.a

CFLAGS = -Werror -Wall -Wextra -g

all : libft $(NAME)

.c.o :
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) $(CFLAGS) -o $(NAME)
	@echo "Compiled $(NAME)"

libft :
	@make -C ./libft --no-print-directory

clean :
	@rm -f $(OBJ)
	@make clean -C ./libft -s
	@echo "Removed object files from project and dependencies"

fclean : clean
	@rm -f $(NAME)
	@echo "Removed $(NAME)"
	@make fclean -C ./libft -s

re : fclean all

.PHONY : all clean fclean re libft