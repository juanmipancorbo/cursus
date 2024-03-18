# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 18:00:18 by jpancorb          #+#    #+#              #
#    Updated: 2024/03/06 19:29:44 by jpancorb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap

SRCS 	= push_swap.c to_ranked.c to_sort.c to_push.c to_swap.c \
		  to_rotate.c algo_100.c algo_500.c ft_utils.c utils.c

HEADER 	= push_swap.h

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
		cc $(SRCS) -o $(NAME) 

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: make all clean fclean re
