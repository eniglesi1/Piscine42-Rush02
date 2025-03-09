/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinoal <marinoal@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:56:05 by marinoal          #+#    #+#             */
/*   Updated: 2025/03/09 19:20:13 by marinoal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./rush02.h"

char	*ft_find_value(t_dict *dict, int nb, int i) 
{
	if (i != -1)
	while (i > 0)
		to_find = (nb * 10) + (0 * i--);
	while (to_find != dict->key)
	{
		dict = dict->next;
		if (dict == NULL)
			return (ft_error_handler()); 
	}
	return (&(dict->value[0]));
}

void	liberar(t_list *list)
{
	t_list *clean;
	while (list)
	{
		clean = list;
		list = list->prev;
		free(clean);

	}
}

int	ft_my_atoi(const char *str)
{
	int	result;
	int	i;
	
	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}
