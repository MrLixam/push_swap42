# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 15:46:24 by lvincent          #+#    #+#              #
#    Updated: 2023/05/30 15:48:27 by lvincent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m

RED = \033[0;31m

RED_B = \033[1;31m

YELLOW = \033[1;33m

BLUE = \033[0;34m

RESET = \033[0m


SRC =		get_next_line.c \
		ft_printf.c ft_printf_utils1.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c \
		ft_striteri.c ft_strmapi.c ft_itoa.c ft_atoi.c ft_split.c ft_strtrim.c \
		ft_strjoin.c ft_substr.c ft_calloc.c ft_strdup.c ft_strnstr.c ft_memcmp.c \
		ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_memchr.c \
		ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_len_arr.c

OBJ = $(SRC:.c=.o)

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

RM = rm -f

CC = clang

AR = ar

AR_FLAGS = rc

all : $(NAME)

.c.o:

	@echo -n "\\r\033[2K$(GREEN)Compiling $<"
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ)
	@echo "\n$(BLUE)Compiled object files for libft"
	@$(AR) $(AR_FLAGS) $(NAME) $(OBJ)
	@echo "$(YELLOW)Compiled libft!$(RESET)"
	
clean:
	@$(RM) $(OBJ)
	@echo "$(RED)removed object files from libft$(RESET)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(RED_B)Removed $(NAME) $(RESET)"

re: clean all

.PHONY: all clean fclean re
