/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:46:00 by gigarcia          #+#    #+#             */
/*   Updated: 2026/05/05 14:30:30 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_loop(int fd, char *stash)
{
	int		bt_read;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash), NULL);
	bt_read = 1;
	while ((!stash || !ft_strchr(stash, SEPARATOR)) && bt_read > 0)
	{
		bt_read = read(fd, buffer, BUFFER_SIZE);
		if (bt_read == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bt_read] = '\0';
		stash = join_n_free(stash, buffer, bt_read);
		if (!stash)
			return (free(buffer), NULL);
	}
	return (free(buffer), stash);
}

static char	*line_extractor(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != SEPARATOR)
		i++;
	line = malloc(i + (stash[i] == SEPARATOR) + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, i);
	if (stash[i] == SEPARATOR)
		line[i++] = SEPARATOR;
	line[i] = '\0';
	return (line);
}

static char	*stash_update(char	*stash)
{
	char	*update_idx;
	int		new_len;

	update_idx = ft_strchr(stash, SEPARATOR);
	if (!update_idx)
		return (free(stash), NULL);
	new_len = ft_strlen(update_idx + 1);
	ft_memmove(stash, (update_idx + 1), new_len);
	stash[new_len] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_loop(fd, stash);
	if (!stash)
		return (NULL);
	line = line_extractor(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = stash_update(stash);
	return (line);
}
/*
#include <stdio.h>
int	main()
{
	char *line = NULL;
	int fd = open("prueba.txt", O_RDONLY); 
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
