# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 22:30:28 by jchu              #+#    #+#              #
#    Updated: 2023/02/15 22:47:07 by jchu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c utils.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: server.o utils.o
	$(CC) -o $@ $^

client: client.o utils.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $?


clean:
	rm -f $(OBJECTS)
	
fclean: clean
	rm -f server client

re: fclean all

.PHONY: all bonus  clean fclean re