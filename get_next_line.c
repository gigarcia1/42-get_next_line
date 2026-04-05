/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:52:24 by gigarcia          #+#    #+#             */
/*   Updated: 2026/04/05 14:28:59 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_loop(int fd, char *line_residue)
{
	int		bytes_read;
	char	*buffer;
       	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(line_residue));
	bytes_read = 1;

	while (!ft_strchr(line_residue, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return(ft_free(line_residue));
		}
		buffer[bytes_read] = '\0';
		line_residue = //memmove y memcpy para unir lo viejo con lo nuevo (??)
						//strjoin modificado
	}
	free(buffer);
	return (line_residue);
}

char	*line_extraction(char *line_residue)
{
	int	i;
	char	*buffer_line;

	i = 0;
	if (!line_residue || !line_residue[0])
		return (NULL); // no hay nada que retornar en el residuo
	while (line_residue[i] && line_residue[i] != '\n')
		i++; //te quedas con el índice del \n o el \0
	buffer_line = (char *)malloc(sizeof(char) * (i + 2)); //+2 por el carácter nulo y el carácter
							      //de salto de línea
	if (!buffer_line)
		return (NULL); //solo retorna NULL para limpiar la estática en la función //principal ante un error
	ft_memcpy(buffer_line, line_residue, i);
	if (line_residue[i] == '\n')
	{
		buffer_line[i] = '\n';
		i++;
	}
	buffer_line[i] = '\0';
	return (buffer_line);	
}

char	*residue_update(char *line_residue) //toma la cadena antigua y 
											//rescata el sobrante luego 
											//del salto de línea
{
	int		i;
	int		j;
	char	*new_residue;

	i = 0;
	while (line_residue[i] && line_residue[i] != '\n')
		i++;
	if (!line_residue[i])
	{
		free(line_residue);
		return (NULL);
	}
	new_residue = (char *)malloc(sizeof(char) * (ft_strlen(line_residue) - i));
	if (!new_residue)
	{
		free(line_residue); //hacer funcion que libere y retorne null???
		return(NULL);
	}
	i++; //para comenzar a copiar desde el siguiente caracter de '\n'
	j = 0;
	while (line_residue[i])
	{
		new_residue[j] = line_residue[i]; //o usar memcpy con el strlen? Es mejor o peor? Por qué?
		i++;
		j++;
	}
	new_residue[j] = '\0';
	free(line_residue);
	return (new_residue;
}

char	*get_next_line(int fd)
{
	static char	*line_residue;
	char		*line;
	char		*buffer;
	int		read_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//delegación del bucle del read a una función auxiliar
	line_residue = read_loop(fd, line_residue);
	if (!line_residue)
		return (NULL); //hubo un error y read retorno -1
	//delegación de la extracción de la línea a una función auxiliar
	line = line_extraction(line_residue);
	line_residue = residue_update(line_residue);
	return (line);
}
