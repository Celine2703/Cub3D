/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:51:30 by cmartin-          #+#    #+#             */
/*   Updated: 2023/06/28 10:42:04 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

int		ft_strstr(char *str);
char	*ft_strncpy(char *str, int n);
char	*ft_strdup(char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoingnl(char *s1, char *s2);
void	ft_free(char **str, char *new);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t size, size_t espace);
char	*ft_read(char **str, int fd);
char	*get_next_line(int fd);

#endif
