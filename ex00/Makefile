/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinoal <marinoal@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:56:05 by marinoal          #+#    #+#             */
/*   Updated: 2025/03/09 19:20:13 by marinoal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

NAME = rush02

SRC = 	utils.c utils2.c 

OBJS = $(SRC:.c=.o)
HEADERS = rush02.h
CFLAGS = -Wall -Wextra -Werror

NORM := norminette
NORM_FLAGS := -R CheckForbiddenSourceHeader -R CheckDefine

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) 
	ar -crs $(NAME) $(OBJS)

%.o: %.c %.h
	@$(NORM) $(NORM_FLAGS) $^
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re	
re: fclean all
