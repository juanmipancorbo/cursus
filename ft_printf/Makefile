# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 19:09:32 by jpancorb          #+#    #+#              #
#    Updated: 2023/10/16 19:56:08 by jpancorb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a

SRCS 	= ft_printf.c ft_putchar.c ft_putstr.c ft_puthexa.c \
		ft_hexapoint.c ft_putnbr.c ft_unsnbr.c

HEADER 	= ft_printf.h

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
		ar rc $(NAME) $(OBJS)

%.o: %.c
		cc -Wall -Werror -Wextra -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: make all clean fclean re
