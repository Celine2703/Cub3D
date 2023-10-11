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
# include "../libft/libft.h"
# include "../Get_next_line/get_next_line.h"

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}	t_color;

typedef struct s_map
{
	char	**tab;
	int		map_width;
	int		map_height;
}	t_map;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	angle;
}	t_player;

typedef struct s_data
{
	char		**file;
	char		*filename;
	t_map		map;
	t_player	player;
	int			nb_lines;
	t_color		ceiling;
	t_color		floor;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
}	t_data;

typedef struct s_pair
{
	int		first;
	int		second;
}	t_pair;

// readFile.c
int	init_data(t_data *data, int argc, char **argv);
void	destroy_data(t_data *data);


char	**getfile(t_data *data);
int		checkfilename(char *filename);
int		getnumberoflines(t_data *data);
int		getallline(t_data *data);

// parseUtils.c
int		iswhitespace(char c);
int		parse_error(t_data *data);
// char	*skipwhitespace(char *line);
char	*deletewhitespace(char *line);
int		isallnb(char *line);

// parseFile.c
int		parsefile(t_data *data);
int		getpath(char *line, char **path);
int		getcolor(char *line, t_color *color);
int		whichline(char *line);
int		readpath(int type, char *line, t_data *data);

// splitUtils.c
int		sizesplit(char **split);
void	freesplit(char **split);
void	printsplit(char **split);

// errors_utils.c
int		print_error_color(char c);
int		missinfo(t_data data);

// parseMap.c
int		parseMap(t_data *data);
int		ft_startmap(char **fil, t_pair *lines);
int		find_longest(char **file, t_pair lines);
int		find_copy_map(t_data data, t_pair lines);



#endif