/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:24:41 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/14 04:07:08 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char	*str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != c)
		i++;
	return (i);
}

int	ft_strchr(char *str, char c)
{
	if (!str)
		return (0);
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
	int		i;
	char	*dest;
	char	*newstr;
	int		l;

	l = ft_strlen(str, 10) + 1;
	dest = malloc(l + 1);
	newstr = malloc(ft_strlen(str, 0) - l + 2);
	if (!dest || !newstr)
		return (NULL);
	dest[l] = 0;
	i = -1;
	while (str[++i])
	{
		if (i < l)
			dest[i] = str[i];
		else
			newstr[i - l] = str[i];
	}
	newstr[i - l] = 0;
	free(str);
	str = newstr;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	// printf("s1: %s\n", s1);
	str = malloc(ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = 0;
	// write(1, "sj4\n", 4);
	if (*s1)
		free(s1);
	return (str);
}
