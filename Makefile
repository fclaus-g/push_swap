# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fernandoclaus <fernandoclaus@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 10:36:04 by fclaus-g          #+#    #+#              #
#    Updated: 2023/03/23 18:04:27 by fernandocla      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	check_input.c check_input_utils.c arg_to_array.c save_args.c \
	push.c swap.c reverse.c rotate.c sorting.c sorting_utils.c \
	bigsort.c exec_rotates.c

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