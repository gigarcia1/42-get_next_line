/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:52:30 by gigarcia          #+#    #+#             */
/*   Updated: 2026/03/28 15:15:55 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, char c)
{
	
}

size_t ft_strlen(char *str)
{
	size_t	i;
	
	i = 0;
	while(str[i])
		i++;
	return (i);
}
