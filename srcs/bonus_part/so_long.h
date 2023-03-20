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
# include "../libary/ft_printf/ft_printf.h"
# include "../libary/get_next_line/get_next_line.h"
# include "../libary/ft_printf/ft_printf.h"
# include "../libary/ft_libft/libft.h"
# include "../libary/mlx/mlx.h"

# define YELLOW 0xffff99

//KEY CODE
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
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

typedef struct s_enemy
{
	int		x_enemy;
	int		y_enemy;
	int		check_wall;
	void	**img;
	void	**r_img;
	int		*fr;
}			t_enemy;

typedef struct s_material
{
	void		**img;
}				t_collect;

typedef struct s_player
{
	int			x_player;
	int			y_player;
	int			x_check;
	int			y_check;
	void		**b_img;
	void		**j_img;
	void		**w_img;
	void		**a_img;
	void		**s_img;
	void		**d_img;
}				t_player;

typedef struct s_maprender
{
	void	**img;
	int		step;
	int		x_exit;
	int		y_exit;
}			t_maprender;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*map_arg;
	char		**map;
	char		**temp_map;
	char		*map_extension;
	t_value		value;
	t_maprender	mapr;
	t_player	pl;
	t_collect	coll;
	t_enemy		enemy;
	int			x_map;
	int			y_map;
}				t_data;

size_t	ft_strlen_nl(char *str);
void	error_print(char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	map_size(t_data *data, char *path);
void	enemy_move(t_data *data, int check);
int		enemy_move_function(t_data *data);
void	enemy_animation(t_data *data, int x, int y);
void	reenemy_animation(t_data *data, int x, int y);
void	map_create(t_data *data, char *path);
void	collectible_animation(t_data *data, int x, int y);
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
void	step_add_to_screen(t_data *data);
void	reenemy_animation(t_data *data, int x, int y);
void	temp_map_create(t_data *data, char *path);
void	find_exit_x_y(t_data *data);
void	xpm_convert_to_player_left(t_data *data, int x, int y);
void	map_render(t_data *data);
void	xpm_convert_to_enemy(t_data *data, int x, int y);
void	xpm_convert_to_reenemy(t_data *data, int x, int y);
void	xpm_convert_to_wall_and_floor(t_data *data, int x, int y);
void	xpm_convert_to_player_b(t_data *data, int x, int y);
void	xpm_convert_to_collectible(t_data *data, int x, int y);
int		add_image_select_x_y(t_data *data);
void	xpm_convert_to_player_right(t_data *data, int x, int y);
void	add_image_to_window(t_data *data, char c, int x, int y);
void	xpm_convert_to_player_up_and_down(t_data *data, int x, int y);
int		key_hook_event(int keycode, t_data *data);
void	player_move_up(t_data *data);
void	player_move_down(t_data *data);
void	player_animation(t_data *data, int x, int y);
void	player_move_left(t_data *data);
void	player_move_right(t_data *data);
void	map_exit_check(t_data *data);

#endif
