/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:18:07 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/15 00:18:26 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*s_buf;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		size;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!s_buf)
		s_buf = "";
	size = read(fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE] = 0;
	s_buf = ft_strjoin(s_buf, buf);
	if (size == -1 && !*s_buf)
		return (NULL);
	while (!ft_strchr(s_buf, 10))
	{
		if (!size)
			return (s_buf);
		size = read(fd, buf, BUFFER_SIZE);
		s_buf = ft_strjoin(s_buf, buf);
	}
	if (ft_strchr(s_buf, 10))
		return (ft_get_line(&s_buf));
	return (NULL);
}
