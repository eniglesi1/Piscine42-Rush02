/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
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

int	ft_strlen(const char *s)
{
  int	i;
  
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	parsenum(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

t_dict *ft_create_dir_nodo(t_dict *prev, char *str)
{
		nodo = (t_dict *)malloc(sizeof(t_dict) + 1);
		if (!nodo)
  			return (NULL);
		nodo->key = 0;
		nodo->value = (char *)malloc((ft_strlen(str) + 1) * (sizefo(char)));
		if (!(nodo->value))
		{
			free(nodo);
			return (NULL);
		}
		ft_strcpy(nodo->value, str); // To ADD
		nodo->prev = prev;
		prev->next = nodo;
		nodo->next = NULL;
		return (nodo);
}

t_list *ft_create_list_nodo(t_list *prev)
{
	t_list *nodo;

	nodo = (t_list *)malloc(sizeof(t_list) + 1);
	if (!nodo)
		return (NULL);
	nodo->cen = 0;
	nodo->dec = 0;
	nodo->uni = 0;
	nodo->prev = prev;
	prev->next = nodo;
	nodo->next = NULL;
	return (nodo);
}

t_list *creatematrix(char *str)
{
	int i;
	t_list *list;

	i = ft_strlen(str);
	list = NULL;
	while (i >= 0)
	{
		list = ft_create_list_nodo(list);
		if (!(list))
			return (NULL);
		list->uni = str[i--] - '0'; 
		if (i >= 0)
			list->dec = str[i--] - '0';
		if (i >= 0)
			list->cen = str[i--] - '0'; 
	}
	return (list);
}
