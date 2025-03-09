# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jota <jota@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 22:46:10 by jota              #+#    #+#              #
#    Updated: 2025/03/09 22:46:10 by jota             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush02

SRC = rush02.c
OBJS = $(SRC:.c=.o)
HEADERS = rush02.h
CFLAGS = -Wall -Wextra -Werror

NORM := norminette
NORM_FLAGS := -R CheckForbiddenSourceHeader -R CheckDefine

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
