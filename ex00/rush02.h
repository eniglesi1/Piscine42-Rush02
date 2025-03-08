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

int	ft_strlen(char *str);

#endif