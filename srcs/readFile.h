/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readFile.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:47:37 by ccravero          #+#    #+#             */
/*   Updated: 2023/09/08 16:35:41 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READFILE_H
# define READFILE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../Libft/libft.h"
# include "../Libft/get_next_line.h"
# include "structs.h"

// readFile.c
int			init_data(t_data *data, int argc, char **argv);

char		**getfile(t_data *data);
int			checkfilename(char *filename);
int			getnumberoflines(t_data *data);
int			getallline(t_data *data);

// parseUtils.c
int			iswhitespace(char c);
int			parse_error(t_data *data);
// char	*skipwhitespace(char *line);
char		*deletewhitespace(char *line);
int			isallnb(char *line);

// parseFile.c
int			parsefile(t_data *data);
int			getpath(char *line, char **path);
int			getcolor(char *line, t_color *color);
int			whichline(char *line);
int			readpath(int type, char *line, t_data *data);

// splitUtils.c
int			sizesplit(char **split);
void		freesplit(char **split);
void		printsplit(char **split);

// errors_utils.c
int			print_error_color(char c);
int			missinfo(t_data data);

// parseMap.c
int			parse_map(t_data *data);
int			ft_startmap(char **fil, t_pair *lines, int emptyline);
int			find_longest(char **file, t_pair lines);
int			find_copy_map(t_data *data, t_pair lines);
void		reverse_map(t_map map);

long double	select_direction(char dir);
int			replace_player(t_data *data);
int			test_checkmap(t_data *d, int i, int j);
int			checkmap(t_data *data);
void		replacespace(t_data *data);

int			combinecolor(t_color *color);

#endif