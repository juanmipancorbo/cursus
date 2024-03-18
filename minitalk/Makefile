# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 21:15:07 by jpancorb          #+#    #+#              #
#    Updated: 2024/03/10 20:20:53 by jpancorb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): server.o
	cc -Wall -Wextra -Werror $^ -o $@
$(NAME_CLIENT): client.o
	cc -Wall -Wextra -Werror $^ -o $@

bonus: .bonus
.bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): server_bonus.o
	cc -Wall -Wextra -Werror $^ -o $@
$(NAME_CLIENT_BONUS): client_bonus.o
	cc -Wall -Wextra -Werror $^ -o $@

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f server.o client.o server_bonus.o client_bonus.o

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) 
	rm -f $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	
re: fclean all

.PHONY: all clean fclean re