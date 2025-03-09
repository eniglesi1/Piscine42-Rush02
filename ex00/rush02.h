/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:48:22 by marvin            #+#    #+#             */
/*   Updated: 2025/03/08 02:48:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				cen;
	int				dec;
	int				uni;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_dict
{
	int				key;
	char			*value;
	struct s_dict	*next;
	struct s_dict	*prev;
}	t_dict;

static int	parsenum(char *str)
int	ft_strlen(const char *s)
t_dict *ft_create_dir_nodo(t_dict *prev, char *str)
t_list *ft_create_list_nodo(t_list *prev)
t_list *creatematrix(char *str)
char	*ft_find_value(t_dict *dict, int nb, int i)
int	get_dic_value(t_dict *dict, t_list *list, char **output, int nod_counter)
void	get_all_list(t_dict *dict, t_list *list, char **output)
void	liberar(t_list *list)
int	ft_my_atoi(const char *str)
t_dict	*read_dict(void)

#endif
