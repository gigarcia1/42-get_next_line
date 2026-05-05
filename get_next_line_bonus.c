/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:40:25 by gigarcia          #+#    #+#             */
/*   Updated: 2026/05/05 14:19:24 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_loop(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = line_extractor(stash[fd]);
	if (!line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = stash_update(stash[fd]);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	char	*line;
	int		fd1 = open("doc1.txt", O_RDONLY);
	int		fd2 = open("doc2.txt", O_RDONLY);
	int		fd3 = open("doc3.txt", O_RDONLY);

	line = get_next_line(fd1);
	printf("%s", line);
	free(line);

	line = get_next_line(fd2);
	printf("%s", line);
	free(line);

	line = get_next_line(fd1);
	printf("%s", line);
	free(line);

	line = get_next_line(fd3);
	printf("%s", line);
	free(line);
}
*/
