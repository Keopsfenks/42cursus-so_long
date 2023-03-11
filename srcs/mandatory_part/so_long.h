#ifndef SO_LONG_H
#define SO_LONG_H

# include <fcntl.h>
# include "stdlib.h"
# include "stdio.h"
# include "../libary/ft_printf/ft_printf.h"
# include "../libary/get_next_line/get_next_line.h"
# include "../libary/ft_printf/ft_printf.h"
# include "../libary//ft_libft/libft.h"
# include "../libary/mlx/mlx.h"

//XPM FORMAT
#define WALL "/Users/segurbuz/Desktop/42cursus-so_long/srcs/textures/wall.xpm"
#define COLLECTIBLE "/Users/segurbuz/Desktop/42cursus-so_long/srcs/textures/textures/goldenapple.xpm"
#define PLAYER "/Users/segurbuz/Desktop/42cursus-so_long/srcs/textures/textures/hero.xpm"
#define FLOOR "/Users/segurbuz/Desktop/42cursus-so_long/srcs/textures/textures/ground.xpm"

typedef struct s_value
{
	int i;
	char *value;
	int j;
	int c_count;
	int e_count;
	int p_count;
	int b;
}		t_value;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	char	**map;
	char 	**temp_map;
	void	*xpm_wall;
	void	*xpm_collectible;
	void	*xpm_player;
	void	*xpm_floor;
	char	*map_extension;
	int		x_player;
	int		y_player;
	t_value	value;
	int 	x_map;
	int 	y_map;
}			t_data;

size_t	ft_strlen_nl(char *str);
void 	error_print(char *str);
void	map_size(t_data *data, char *path);
void	map_create(t_data *data, char *path);
int		map_size_control(t_data *data);
void	check_map(t_data *data);
int		map_value_control(t_data *data);
int		check_value(char c, t_data *data);
int		map_firstandlast_wall_control(t_data *data);
int		map_unknown_value_control(t_data *data);
int	 	map_ber_control(t_data *data);
int 	map_value_left_control(t_data *data, int x, int y);
void	find_player_x_y(t_data *data);
int 	map_value_left_control_2(t_data *data);
void	map_render(t_data *data);
void	xpm_convert(t_data *data, int x, int y);
void	temp_map_create(t_data *data, char *path);
void	map(t_data *data, char *path);

#endif