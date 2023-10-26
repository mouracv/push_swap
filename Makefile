# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 14:55:07 by aleperei          #+#    #+#              #
#    Updated: 2023/08/31 12:11:05 by aleperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRCS =	src/push.c src/rotate.c src/reverse_rotate.c src/swap.c \
		src/push_swap.c src/check_args.c src/check_args_utils.c \
		src/node_utils_1.c src/smal_sort.c src/stack_utils_1.c \
		src/big_sort.c src/big_sort_utils.c \

OJBS = $(SRCS:.c=.o)

$(NAME):	$(OJBS)
	$(CC) $(CFLAGS) $(OJBS) -o $(NAME)

all: $(NAME)

clean:
		$(RM) $(OJBS)

fclean:	clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re