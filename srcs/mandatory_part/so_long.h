/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:16:09 by segurbuz          #+#    #+#             */
/*   Updated: 2023/03/14 23:16:12 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "stdlib.h"
# include "stdio.h"
# include "../libary/ft_printf/ft_printf.h"
# include "../libary/get_next_line/get_next_line.h"
# include "../libary/ft_printf/ft_printf.h"
# include "../libary/ft_libft/libft.h"
# include "../libary/mlx/mlx.h"

//MAP EXTENSION
# define MAP_EXTENSION "/Users/segurbuz/Desktop/42cursus-so_long/srcs/maps/"

//XPM FORMAT
# define WALL "/Users/segurbuz/Desktop/42cursus-so_long/srcs/textures/1.xpm"
# define COLLEC "/Users/segurbuz/Desktop/42cursus-so_long/srcs/textures/c.xpm"
# define PLAYER "/Users/segurbuz/Desktop/42cursus-so_long/srcs/textures/p.xpm"
# define FLOOR "/Users/segurbuz/Desktop/42cursus-so_long/srcs/textures/0.xpm"
# define EXIT "/Users/segurbuz/Desktop/42cursus-so_long/srcs/textures/e.xpm"

//KEY CODE
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define UP_KEY 126
# define LEFT_KEY 123
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define ESC_KEY 53

typedef struct s_value
{
	int		i;
	char	*value;
	int		j;
	int		c_count;
	int		e_count;
	int		p_count;
	int		b;
}		t_value;

typedef struct s_maprender
{
	void	*wall;
	void	*coll;
	void	*pl;
	void	*fl;
	void	*ex;
	int		x_player;
	int		y_player;
	int		x_exit;
	int		y_exit;
	int		keycode;
}		t_maprender;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	char		**temp_map;
	char		*map_extension;
	t_value		value;
	t_maprender	mapr;
	int			x_map;
	int			y_map;
}			t_data;

size_t	ft_strlen_nl(char *str);
void	error_print(char *str);
void	map_size(t_data *data, char *path);
void	map_create(t_data *data, char *path);
int		map_size_control(t_data *data);
void	check_map(t_data *data);
int		map_value_control(t_data *data);
int		check_value(char c, t_data *data);
int		map_firstandlast_wall_control(t_data *data);
int		map_unknown_value_control(t_data *data);
int		map_ber_control(t_data *data);
void	map_value_left_control(t_data *data, int x, int y);
void	find_player_x_y(t_data *data);
void	map_value_left_control_2(t_data *data);
void	temp_map_create(t_data *data, char *path);
void	find_exit_x_y(t_data *data);
void	map_render(t_data *data);
void	xpm_convert(t_data *data, int x, int y);
int		add_image_select_x_y(t_data *data);
void	add_image_to_window(t_data *data, char c, int x, int y);
int		key_hook_event(int keycode, t_data *data);
void	player_move_up(t_data *data);
void	player_move_down(t_data *data);
void	player_move_left(t_data *data);
void	player_move_right(t_data *data);
void	map_exit_check(t_data *data);

#endif
