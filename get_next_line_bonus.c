/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 01:11:26 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/17 01:25:31 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*s_buf[OPEN_MAX];
	char		*line;
	ssize_t		size;

	size = 1;
	while ((!s_buf[fd] || !ft_strchr(s_buf[fd], 10)) && size)
	{
		line = malloc(BUFFER_SIZE + 1);
		if (!line)
			return (NULL);
		size = read(fd, line, BUFFER_SIZE);
		if (size < 0)
			return (ft_free(line, NULL));
		line[size] = 0;
		s_buf[fd] = ft_strjoin(s_buf[fd], line);
	}
	line = ft_get_line(s_buf[fd]);
	s_buf[fd] = ft_backup(s_buf[fd]);
	return (line);
}
