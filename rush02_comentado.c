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
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

t_list *ft_create_nodo(t_list *prev)
{
	t_list *nodo;

	nodo = (t_list *)malloc(sizeof(t_list) + 1);
	if (!nodo)
  		return (NULL);
	nodo->cen = 0;// Esto se iguala a 0 para que comience desde el principio? --- Sí
	nodo->dec = 0;
	nodo->uni = 0;
	nodo->prev = prev;
	prev->next = nodo;
	nodo->next = NULL;
	return (nodo);

}
//crear un nodo para el dict siguiendo la estructura definida en rush2.h
// --- Bastante acertado, he limado un par de detalles para añadirlo
// --- al código principal. ¡Buen trabajo!
t_dict *ft_create_nodo(t_dict *prev)
{
        nodo = (t_dict *)malloc(sizeof(t_dict) + 1);
		if (!nodo)
  			return (NULL);
        nodo->key = 0;
        nodo->value = NULL;
        nodo->prev = prev;
        prev->next = nodo;
        nodo->next = NULL;
        return (nodo);
}
//Si ft_create_nodo devuelve NULL, el código fallará? --- Sí
//Debe verificarse antes de acceder a list->uni, list->dec, list->cen.  ----Corregido, Bien visto
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
#include <stdio.h> // ------ ¿Nos hace falta?
// va a transformar un char en int, si es que hay.
// elimina los espacios
// cuenta los "-" para ver si es negativo
// convierte los char que hay entre '0' y '9' en enteros.
// en ASCII, el '0' = 48. Al restar el char que hay en el str, nos da el mismo número ya en int.
// finalmente, le sumamos lo que hay a la izquierda (almacenado en result).
// --- Cambio la manera de iterar para usar índices y
// --- elimino el tratamiento de espacios y signos y lo añado, en este programa
// --- solo pueden darnos números enteros sin signos. Por lo demás, ¡Buen trabajo!
int	ft_my_atoi(const char *str)
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
// --- Hay que establecer por separado 
// --- la impresión de las centenas, decenas, unidades y los múltiplos de mil, 
// --- ya que nunca vamos a encontrar el número exacto, 
// --- sino las partes de las que se forma, añado esta modificación. ¡Bien intentado!
void	print_nodo(t_dict *dict, t_list *list, int i)
{
	int number;
	t_dict *aux = dict;
	
	number = (list->cen * 100 + list->dec * 10 + list->uni);

	while (aux)
	{
		if(ft_my_atoi(aux->key) == number)
		{
			write(1, aux->value, ft_strlen(aux->value));
			return;
		}
		aux = aux->next;
	}
}

// Crear un array(el padre yy sus hijos) con malloc y ahí ir guardando los value.
	// Para cada líena hay que reservar memoria con malloc y lo metes en un puntero 
	//	Después de estar todo reservado
	// Hay que reservar un malloc para el doble punter char **str
		// (el padre) de todas las líneas.

// Luego para imprimir tiramos de la memoria creada.
// Crearlo fuera de print_matrix y pasárselo como argumento a print_matrix , 
// de print matrix a print nodo (en print nodo se guarda la info)
// Después de print_matrix imprimir
// Liberar memoria de string.(con un while se libera los hijos y cuando temrine se libera al padre)
// El último hijo tiene que estar sin reservar y tener null. (= NULL)
typedef struct s_string
{
    char **words;        // Array de palabras (los hijos)
    int count;           // Contador de palabras almacenadas
    int capacity;        // Capacidad total del array
} t_string;

t_string *init_string_array(int capacity)
{
    t_string *str_array;
    
    str_array = (t_string *)malloc(sizeof(t_string)); //asigna memoria para t_string y parsea errores
	if (!str_array)
		return (NULL);
    
    str_array->words = (char **)malloc(sizeof(char *) * capacity); //Asigna memoria para words
    if (!str_array->words)
    {
        free(str_array);
        return (NULL);
    }
    
    // Inicializar todos los punteros a NULL
    int i = 0;
    while (i < capacity)
    {
        str_array->words[i] = NULL;
        i++;
    }
    
    str_array->count = 0;
    str_array->capacity = capacity;
    
    return (str_array);
}

void	printmatrix(t_dict *dict, t_list *list, int i)
{
	if (list->prev != NULL)
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
//LIBERAMOS MEMORIA DICCIONARIO.
void liberar_dict(t_dict *dict) 
{
    int i = 0;
    while (dict[i].key != NULL || dict[i].value != NULL) 
	{
        free(dict[i].key);
        free(dict[i].value);
        i++;
    }
    free(dict);
}
#define BUFFER_SIZE 1024 //Con 1024 nos vale o debería ser más? 

t_dict	*read_dict(void)
{
	int fd;
	char buffer[BUFFER_SIZE + 1]; // Definimos el tamaño del buffer.
	int bytes_read; //almacenar los bytes
	t_dict *dict; // Aquí se van a meter los datos del diccionario.

	fd = open("number.dict", O_RDONLY); // depende del nombre del diccionario
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

char *strdup(const char *src)
{
	int	i;
	char *dup;

	i = 0;
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
}

char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    return (NULL);
}

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

		*sep = '\0'; //cambia ':' por un '\0', separando key de value
		key = ft_strdup(line); //duplica la parte antes de los dos puntos.
		value = ft_strdup(sep + 1); //Duplica a parte después de los dos puntos.
	
		if (!key || !value)
            return (NULL); //si key o value son NULL retorna error.
        
        dict[count].key = key; //Guarda la key en "dict"
        dict[count].value = value; //Guarda el value en "dict"
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
				matrix = creatematrix(argv[1]);
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
