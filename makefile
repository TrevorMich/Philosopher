# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 09:24:32 by ioduwole          #+#    #+#              #
#    Updated: 2023/05/15 20:16:01 by ioduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC =	*.c
		
CC  =  gcc -pthread

CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(SRC)
		$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean: 
		@rm -f $(NAME)

fclean: clean

re: fclean all
