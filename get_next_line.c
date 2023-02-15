/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:18:07 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/15 01:30:02 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_isprint(int c)
{
	if ((c > 31 && c < 127) || (c > 7 && c < 14))
		return (1);
	else
		return (0);
}

char	*get_next_line(int fd)
{
	static char	*s_buf;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		size;

	if (!s_buf)
		s_buf = "";
	size = read(fd, buf, BUFFER_SIZE);
	if (size < 0 || !ft_isprint(*buf))
		return (NULL);
	buf[BUFFER_SIZE] = 0;
	s_buf = ft_strjoin(s_buf, buf);
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

