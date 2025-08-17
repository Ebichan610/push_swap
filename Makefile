# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 07:11:03 by yebi              #+#    #+#              #
#    Updated: 2025/08/17 08:22:30 by ebichan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRCS = err_hand.c \
	ft_atoi.c \
	ft_split.c \
	indexing_utils.c \
	indexing.c \
	main.c \
	organize_astack.c \
	push.c \
	reverse_rotate.c \
	rotate.c \
	sort_a_few.c \
	sort_chunk_utils.c \
	sort_chunk.c \
	swap.c \

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
