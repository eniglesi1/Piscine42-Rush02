/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_nodo_t_dict.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivas-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:33:45 by irivas-v          #+#    #+#             */
/*   Updated: 2025/03/08 19:12:43 by irivas-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//crear un nodo para el dict siguiendo la estructura definida en rush2.h
t_dict *ft_create_nodo(t_dict *prev)
{
        t_dict *nodo;

        nodo = (t_dict *)malloc(sizeof(t_dict) + 1);
        nodo->key = 0;
        nodo->value = NULL;
        nodo->prev = prev;
        prev->next = nodo;
        nodo->next = NULL;
        return (nodo);
}
