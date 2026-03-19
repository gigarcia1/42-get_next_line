/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:52:56 by gigarcia          #+#    #+#             */
/*   Updated: 2026/03/19 14:00:51 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//LIBRARIES
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

//PROTOTYPES -> check all functions in get_next_line_utils.c
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
