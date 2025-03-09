# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 01:48:53 by marvin            #+#    #+#              #
#    Updated: 2025/03/08 01:48:53 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush02

SRC = 	ft_atoi.c utils.c utils2.c ...

OBJS = $(SRC:.c=.o)?????????
HEADERS = libft.h
CFLAGS = -Wall -Wextra -Werror

NORM := norminette
NORM_FLAGS := -R CheckForbiddenSourceHeader -R CheckDefine

all: $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(NAME): $(OBJS) rush.h
	ar -crs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
