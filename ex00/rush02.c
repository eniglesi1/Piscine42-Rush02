/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:30:46 by marvin            #+#    #+#             */
/*   Updated: 2025/03/08 02:30:46 by marvin           ###   ########.fr       */
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
		if (str[i] < '0' || str[i] >= '9')
			return (0);
		i++;
	}
	return (1);
}

t_list *ft_create_nodo(t_list *prev)
{
	t_list *nodo;

	nodo = (t_list *)malloc(sizeof(t_list) + 1);
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
		list = ft_create_nodo(list);
		list->uni = str[i--] - '0'; 
		if (i >= 0)
			list->dec = str[i--] - '0';
		if (i >= 0)
			list->cen = str[i--] - '0'; 
	}
	return (list);
}

void	print_nodo(t_dict *dict, t_list *list, int i)
{
	comparar al dict && write; // ToDo
	cen; dec; uni; millones;
}

void	printmatrix(t_dict *dict, t_list *list, int i)
{
	if (t_list->prev != NULL)
		printmatrix(dict, list->prev, i + 1);
	print_nodo(dict, list, i);
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

t_dict	*read_dict(void)
{
	open, read, close; // ToDo
}

int	main(int arg, char **argv)
{
	t_list	*matrix;
	t_dict	*dict;

	dict = NULL;
	matrix = NULL;
	if (argc == 2)
	{
		if (parsenum(argv[1]) == 1)
			{
				matrix = creatematrix(arv[1]);
				dict = read_dict(void); // ToDo
				printmatrix(dict, matrix, i); // ToDo
				liberar(matrix); // To Do Proteger los mallocs;
			}
		else
			write(1, "Error\n", 6);
	}
	else if (argc == 3)
		changedic; // realizar alternativa
	else
		write(1, "Error\n", 6);
	return (0);
}