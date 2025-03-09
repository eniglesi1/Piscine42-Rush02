/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivas-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:18:46 by irivas-v          #+#    #+#             */
/*   Updated: 2025/03/08 21:31:21 by irivas-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// va a transformar un char en int, si es que hay.
// elimina los espacios
// cuenta los "-" para ver si es negativo
// convierte los char que hay entre '0' y '9' en enteros.
// en ASCII, el '0' = 48. Al restar el char que hay en el str, nos da el mismo número ya en int.
// finalmente, le sumamos lo que hay a la izquierda (almacenado en result).
int	my_atoi(const char *str)
{
	int	result;
	int	sign;
	
	result = 0;
	sign = 1;

	while (*str == ' ')
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');//result almacena cada número int ya convertido
		str++;
	}
	return (result * sign);
}

int	main()
{
	char str[] = "  -584abc";
	int num = my_atoi(str);
	printf("El número convertido es: %d\n", num);
	return 0;
}
