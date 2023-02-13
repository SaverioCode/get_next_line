/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:18:07 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/13 22:36:32 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	// char	c; 		// valid in A.
	char	*buf;
	int		size;
	// int		buflen; // testing in B. valid in A.

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	/// B. ///
	size = read(fd, buf, BUFFER_SIZE);
	if (size < 0)
		return (NULL);
	if (!ft_strchr(buf, 10))
	{
		write(1, "b\n", 2);
		if (!size)
			return (buf);
		return (ft_end_buf(buf, &fd));
	}
	else if (ft_strchr(buf, 10) && buf[BUFFER_SIZE] != 10)
		return (ft_strcut(buf));
	else
		return (buf);
	/// A. ///
	// while (++buflen < BUFFER_SIZE)
	// {
	// 	size = read(fd, c, 1);
	// 	if (size < 0)
	// 		return (NULL);
	// 	buf[buflen - 1] = c;
	// 	if (c == 10 || !size)
	// 		return (buf) ;
	// }
	// if (!ft_strchr(buf, 10))
	// {
	// 	while (buf[buflen] != 10)
	// 	{	
	// 		size = read(fd, c, 1);
	// 		buf[++buflen] = c;
	// 		if (c == 10 || !size)
	// 			return (buf) ;
	// 	}
	// }
	// buf[buflen] = 0;
	// return (buf);
}
 // A. first attempt loop read till buffer_size if zero or \n is no reached
 // B. second attempt read buffer_size and then cut what you whant to print