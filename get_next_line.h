/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:25:00 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/14 02:36:25 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

char	*get_next_line(int fd);
int		ft_strchr(char *str, char c);
char	*ft_strcut(char *str);
char	*ft_strjoin(char *dest, char *str);
size_t	ft_strlen(char	*str, int c);

#endif
