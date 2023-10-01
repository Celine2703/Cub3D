/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:51:30 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/12 14:51:32 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include "../Libft/libft.h"

# define BUFFER_SIZE 1

int		ft_strstr(char *str);
char	*ft_strncpy(char *str, int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoinb(char *s1, char *s2);
void	ft_free(char **str, char *new);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t size, size_t espace);
char	*ft_read(char **str, int fd);
char	*get_next_line(int fd);

#endif
