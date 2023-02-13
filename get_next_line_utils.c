/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:24:41 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/13 22:34:35 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strcut(char *str)
{
	int	i;
	char	*dest;

	i = -1;
	while (str[++i])
		if (str[i] == 10)
			break ;
	dest = malloc (i + 2);
	if (!dest)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		dest[i] = str[i];
		if (str[i] == 10)
			break ;
	}
	dest[i++] = 0;
	free(str);
	return (dest);
}

char	*ft_end_buf(char *str, int *fd)
{
	char	c;
	int		size;
	char	*buf;

	size = 1;
	while (size > 0)
	{
		size = read(*fd, &c, 1);
		buf = newstring(str, c);
	}
	return (buf);
}

char	*newstring(char *str, char c)
{
	char	*newstring;
	int		len;

	len = -1;
	while (str[++len])
		;
	newstring = malloc(len + 2);
	len = -1;
	while (str[++len])
		newstring[len] = str[len];
	newstring[len] = c;
	newstring[++len] = 0;
	free(str);
	return (newstring);	
}
