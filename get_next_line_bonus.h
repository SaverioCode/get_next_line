/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 01:12:15 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/17 01:22:38 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *str, char c);
char	*ft_get_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char	*str, int c);
char	*ft_backup(char	*backup);
char	*ft_free(char *s1, char *s2);

#endif
