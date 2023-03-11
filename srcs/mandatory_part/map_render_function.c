#include "so_long.h"

void	xpm_convert(t_data *data, int x, int y)
{
	data->xpm_wall = mlx_xpm_file_to_image(data->mlx, WALL, &x, &y);
	data->xpm_collectible = mlx_xpm_file_to_image(data->mlx, COLLECTIBLE, &x, &y);
	data->xpm_floor = mlx_xpm_file_to_image(data->mlx, FLOOR, &x, &y);
	data->xpm_player = mlx_xpm_file_to_image(data->mlx, PLAYER, &x, &y);
}


void	map_render(t_data *data)
{
	data->window = mlx_new_window(data->mlx, data->x_map * 64, data->y_map * 64, "so_long");
	xpm_convert(data, 64, 64);
}