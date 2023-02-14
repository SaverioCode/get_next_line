/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:18:07 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/14 04:37:55 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*s_buf;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		size;

	if (read(fd, 0, 0) < 0)
		return (NULL);
	s_buf = "";
	// printf("s_buf: %s\n", s_buf);
	size = read(fd, buf, BUFFER_SIZE);
	s_buf = ft_strjoin(s_buf, buf);
	if (size == -1 && !ft_strlen(s_buf, 0))
		return (NULL);
	while (!ft_strchr(s_buf, 10))
	{
		// write(1, "c\n", 2);
		if (!size)
			return (s_buf);
		size = read(fd, buf, BUFFER_SIZE);
		// write(1, "d\n", 2);
		s_buf = ft_strjoin(s_buf, buf);
		// printf("s_buf: %s\n", s_buf);
		// write(1, "c\n", 2);
	}
	if (ft_strchr(s_buf, 10) && s_buf[ft_strlen(s_buf, 0) - 1] != 10)
		return (ft_strcut(s_buf));
	return (s_buf);
}
