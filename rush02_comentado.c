/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:30:46 by marvin            #+#    #+#             */
/*   Updated: 2025/03/08 18:53:59 by marinoal         ###   ########.fr       */
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
	nodo->cen = 0;// Esto se iguala a 0 para que comience desde el principio?
	nodo->dec = 0;
	nodo->uni = 0;
	nodo->prev = prev;
	prev->next = nodo;
	nodo->next = NULL;
	return (nodo);

}
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
#define BUFFER_SIZE 1024 //Con 1024 nos vale o debería ser más? 

t_dict	*read_dict(void)
{
	int fd;
	char buffer[BUFFER_SIZE + 1]; // Definimos el tamaño del buffer.
	int bytes_read; //almacenar los bytes
	t_dict *dict // Aquí se van a meter los datos del diccionario.

	fd = open("number.dict" O_RDONLY); // depende del nombre del diccionario
	if (fd == -1) // si el open no funciona
	{
		write(1, "Dict Error\n", 11); // Mensaje de error.
		return (NULL); //Función de error.
	}

	bytes_read = read(fd, buffer, BUFFER_SIZE); //Misma estructura que "write" pero para leer. Lo almacena en Buffer_Size
	if (bytes_read <= 0)
	{
		write(1, "Dict Error\n", 11); //si el número de bytes que lee es nada o negativo, manda mensaje de error.
		close(fd);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	close(fd);	//Añadimos un nulo al final para asegurarnos de que sea válido para C y cerramos el diccionario para liberar espacio
	
	dict = parse_dict(buffer); // Función para convertir el contenido del buffer en una estructura t_dict.
	if (!dict)
	{
		write(1, "Dict error\n", 11);
		return (NULL);
	}
	return (dict);
}
/*
char	*strdup(char *src)
{
	int	i;
	i = 0;
	char *dup;

	dup = (char *)malloc(ft_strlen(src) + 1);
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
*/

t_dict	*parse_dict(char *buffer) // ft_strlen (ya esta hecha), "AÑADIR" *ft_strdup para duplicar. "AÑADIR" *ft_strchr para buscar un caracter en una cadena.
{
	t_dict *dict; //Aquí almacenamos los valores, en dict.
	char *line; //array para recorrer el buffer.
	char *key; //El número entero
	char *value; //El texto del número entero.
	int count; //Contador de elementos.
	
	count = 0;
	
	dict = malloc(sizeof(t_dict) * 100); // Reservamos memoria para el dictado. "ES SUFICIENTE 100??"
	if (!dict)
		return (NULL); //si la memoria falla, devuelve NULL.

	line = buffer;
	while (*line && count < 100) //Mientras linea no sea NULL y no exceda de 100, sigue. 
	{
		char *sep = ft_strchr(line, ':'); //Busca : en la línea
		if (!sep)
			return (NULL); //Si no están los dos puntos, no es válido y retorna NULL.

		*sep = '\0';
		key =  
	}
	*sep = '\0'; //cambia los dos números por un \0, separando key de value
	key = ft_strdup(line); //duplica la parte antes de los dos puntos.
	value = ft_strdup(sep + 1); //Duplica a parte después de los dos puntos.
	
	if (!key || !value)
            return (NULL); //si key o value son NULL retorna error.
        
        dict[count].key = key; //Guarda la clave en "dict"
        dict[count].value = value; //Guarda el valor en "dict"
        count++; 
        
        line = ft_strchr(sep + 1, '\n'); //Encuentra el final de la línea
        if (line) //Si hay un salto de línea, pasamos al siguiente caracter
            line++;
    }
    return (dict); //Devuelve el puntero al diccionario.
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
