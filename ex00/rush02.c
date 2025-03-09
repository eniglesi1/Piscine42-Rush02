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

// c == (nb, 0) && (1, 2) || d == (nb, 1) || u == (nb, 0) || m == (1, 3*i)
char	*ft_find_value(t_dict *dict, int nb, int i) // i es la cantidad de 0
{
	if (i != -1)
	while (i > 0)
		to_find = (nb * 10) + (0 * i--);
	while (to_find != dict->key)
	{
		dict = dict->next;
		if (dict == NULL)
			return (ft_error_handler()); // To ADD
	}
	return (&(dict->value[0]));
}

//comparar al dict && write; // ToDo
//cen; dec; uni; millones;
int	get_dic_value(t_dict *dict, t_list *list, char **output, int nod_counter)
{
	int	*num;
	int	i;
	int	j;
	int	zeros;

	i = 4;
	j = 0;
	zeros = 0;
	num = (dict->c);
	if (list != NULL)
		return (0);
	if (list->c == 0)
		num = &(dict->d) i = i - 2;
	if (list->d == 0)
		i = i - 1;
	if (list->u == 0)
		i = i - 1;
	if (list->c == 0 && list->d == 0 && list->u == 0)
		i = - 1;

	while (i >= j)
	{
		output[j] = ft_find_value(dict, num, zeros);
		j++;
	}
	i++;
	output[1] = ft_find_value(dict, 1, 2);
	output[2] = ft_find_value(dict, list->d, 1);
	output[3] = ft_find_value(dict, list->u, 0);
	output[4] = ft_find_value(dict, 1, i);
	if (!output[0])
		return (0);
	return (i);
}

void	get_all_list(t_dict *dict, t_list *list, char **output)
{
	int	i;

	i = 0;
	while (t_list != NULL && t_list->prev != NULL)
	{
		output[i++] = get_dic_value(dict, list->prev, i);
		if (output[i++])
			return (0);
	}
	return (i);
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
				if (!matrix)
					return (ft_error_handler()); // To ADD
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