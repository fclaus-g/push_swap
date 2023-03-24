# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 10:36:04 by fclaus-g          #+#    #+#              #
#    Updated: 2023/03/24 15:57:07 by fclaus-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	check_input.c check_input_utils.c arg_to_array.c save_args.c \
	push.c swap.c reverse.c rotate.c sorting.c sorting_utils.c \
	exec_rotates.c

OBJ = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re