/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:39:49 by gigarcia          #+#    #+#             */
/*   Updated: 2026/05/04 19:03:56 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join_n_free(char *stash, char *buffer, int bt_rd)
{
	char	*aux;
	int		stash_len;

	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		*stash = '\0';
	}
	aux = stash;
	stash_len = ft_strlen(stash);
	stash = malloc(stash_len + bt_rd + 1);
	if (!stash)
		return (free(aux), NULL);
	ft_memcpy(stash, aux, stash_len);
	ft_memcpy(&stash[stash_len], buffer, bt_rd);
	stash[stash_len + bt_rd] = '\0';
	return (free(aux), stash);
}

char	*ft_strchr(char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	if (c == '\0')
		return (tmp + ft_strlen(tmp));
	while (*tmp)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp++;
	}
	return (NULL);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, int n)
{
	const char		*tmp_src;
	unsigned char	*tmp_dest;

	if (!src && !dest)
		return (NULL);
	tmp_src = (const char *)src;
	tmp_dest = (unsigned char *)dest;
	while (n > 0)
	{
		*tmp_dest++ = *tmp_src++;
		n--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, int n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	if (!src && !dest)
		return (NULL);
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	if (dest <= src)
	{
		while (n--)
			*tmp_dest++ = *tmp_src++;
	}
	else
	{
		tmp_src += n - 1;
		tmp_dest += n - 1;
		while (n--)
			*tmp_dest-- = *tmp_src--;
	}
	return (dest);
}
