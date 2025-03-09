/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:30:46 by marvin            #+#    #+#             */
/*   Updated: 2025/03/10 01:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "rush02.h"

int	ft_strlen(const char *s)
{
	int	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		len = ft_strlen(src);
	char	*dup;
	int		i = 0;

	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static int	parsenum(char *str)
{
	int	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

t_dict	*create_dict_node(int key, char *value)
{
	t_dict	*node = malloc(sizeof(t_dict));
	if (!node)
		return (NULL);
	node->key = key;
	node->value = ft_strdup(value);
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

static t_dict	*parse_line(char *line)
{
	int	key = 0;
	int	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		key = key * 10 + (line[i] - '0');
		i++;
	}
	while (line[i] && (line[i] == ' ' || line[i] == ':'))
		i++;
	if (!line[i])
		return (NULL);
	return (create_dict_node(key, &line[i]));
}

static void	add_dict_node(t_dict **head, t_dict **tail, char *line)
{
	t_dict	*node = parse_line(line);
	if (node)
	{
		if (*tail)
		{
			node->prev = *tail;
			(*tail)->next = node;
			*tail = node;
		}
		else
		{
			*head = node;
			*tail = node;
		}
	}
}

static t_dict	*process_buffer(char *buf)
{
	int		i = 0;
	int		start = 0;
	t_dict	*head = NULL;
	t_dict	*tail = NULL;

	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			if (buf[start])
				add_dict_node(&head, &tail, &buf[start]);
			start = i + 1;
		}
		i++;
	}
	if (start < i && buf[start])
		add_dict_node(&head, &tail, &buf[start]);
	return (head);
}

t_dict	*read_dict(const char *fname)
{
	int		fd;
	int		bytes;
	char	buf[4096];

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (NULL);
	bytes = read(fd, buf, 4095);
	if (bytes < 0)
	{
		close(fd);
		return (NULL);
	}
	buf[bytes] = '\0';
	close(fd);
	return (process_buffer(buf));
}

char	*lookup_value(t_dict *dict, int key)
{
	while (dict)
	{
		if (dict->key == key)
			return (dict->value);
		dict = dict->next;
	}
	return (NULL);
}

static t_list	*create_node(char *s, int *i)
{
	int		d[3];
	int		pos;
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	d[0] = 0;
	d[1] = 0;
	d[2] = 0;
	pos = 2;
	while (*i > 0 && pos >= 0)
	{
		d[pos] = s[--(*i)] - '0';
		pos--;
	}
	node->cen = d[0];
	node->dec = d[1];
	node->uni = d[2];
	return (node);
}

t_list	*creatematrix(char *s)
{
	int		i = ft_strlen(s);
	t_list	*head = NULL;
	t_list	*node;

	while (i > 0)
	{
		node = create_node(s, &i);
		if (!node)
		{
			free_matrix(head);
			return (NULL);
		}
		node->next = head;
		if (head)
			head->prev = node;
		head = node;
	}
	return (head);
}

void	free_matrix(t_list *m)
{
	t_list	*tmp;
	while (m)
	{
		tmp = m;
		m = m->next;
		free(tmp);
	}
}

void	free_dict(t_dict *d)
{
	t_dict	*tmp;
	while (d)
	{
		tmp = d;
		d = d->next;
		free(tmp->value);
		free(tmp);
	}
}

static int	validate_group(t_dict *d, t_list *n)
{
	if (n->cen > 0)
		if (!lookup_value(d, n->cen) || !lookup_value(d, 100))
			return (0);
	if (n->dec == 1)
	{
		if (!lookup_value(d, n->dec * 10 + n->uni))
			return (0);
	}
	else
	{
		if (n->dec > 1 && !lookup_value(d, n->dec * 10))
			return (0);
		if (n->uni > 0 && !lookup_value(d, n->uni))
			return (0);
	}
	return (1);
}

static int	validate_scale(t_dict *d, int idx)
{
	int	scale = 1;
	int	j = 0;
	while (j < idx)
	{
		scale *= 1000;
		j++;
	}
	return (lookup_value(d, scale) != NULL);
}

static int	validate_node(t_dict *d, t_list *n, int idx)
{
	int	num = n->cen * 100 + n->dec * 10 + n->uni;
	if (num <= 0)
		return (1);
	if (!validate_group(d, n))
		return (0);
	if (idx > 0 && !validate_scale(d, idx))
		return (0);
	return (1);
}

int	validate_matrix(t_dict *d, t_list *m)
{
	int	groups = 0;
	int	idx;
	t_list	*n = m;
	while (n)
	{
		groups++;
		n = n->next;
	}
	idx = groups - 1;
	n = m;
	while (n)
	{
		if (!validate_node(d, n, idx))
			return (0);
		idx--;
		n = n->next;
	}
	return (1);
}

static void	print_val(t_dict *d, int key)
{
	char	*w = lookup_value(d, key);
	if (w)
		write(1, w, ft_strlen(w));
	write(1, " ", 1);
}

static void	print_node(t_dict *d, t_list *n, int idx)
{
	int	scale = 1;
	int	j = 0;
	if (n->cen > 0)
	{
		print_val(d, n->cen);
		print_val(d, 100);
	}
	if (n->dec == 1)
		print_val(d, n->dec * 10 + n->uni);
	else
	{
		if (n->dec > 1)
			print_val(d, n->dec * 10);
		if (n->uni > 0)
			print_val(d, n->uni);
	}
	if (idx > 0)
	{
		while (j < idx)
		{
			scale *= 1000;
			j++;
		}
		print_val(d, scale);
	}
}

void	printmatrix(t_dict *d, t_list *m)
{
	int	groups = 0;
	int	idx;
	t_list	*n = m;
	while (n)
	{
		groups++;
		n = n->next;
	}
	idx = groups - 1;
	n = m;
	while (n)
	{
		print_node(d, n, idx);
		idx--;
		n = n->next;
	}
}

int	ft_error_handler(void)
{
	write(1, "Error\n", 6);
	return (1);
}

static int	get_args(int ac, char **av, const char **df, char **num)
{
	if (ac == 2)
	{
		*df = "numbers.dict";
		*num = av[1];
		return (1);
	}
	else if (ac == 3)
	{
		*df = av[1];
		*num = av[2];
		return (1);
	}
	return (0);
}

static int	process_number(const char *df, char *num)
{
	t_list	*m;
	t_dict	*d;

	if (!parsenum(num))
		return (ft_error_handler());
	m = creatematrix(num);
	if (!m)
		return (ft_error_handler());
	d = read_dict(df);
	if (!d)
	{
		free_matrix(m);
		write(1, "Dict Error\n", 11);
		return (1);
	}
	if (!validate_matrix(d, m))
	{
		free_matrix(m);
		free_dict(d);
		write(1, "Dict Error\n", 11);
		return (1);
	}
	printmatrix(d, m);
	write(1, "\n", 1);
	free_matrix(m);
	free_dict(d);
	return (0);
}

int	main(int ac, char **av)
{
	const char	*df;
	char		*num;

	if (!get_args(ac, av, &df, &num))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (process_number(df, num));
}
