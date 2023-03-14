#include "so_long.h"

void	xpm_convert(t_data *data, int x, int y)
{
	data->maprender.xpm_wall = mlx_xpm_file_to_image(data->mlx, WALL, &x, &y);
	data->maprender.xpm_collectible = mlx_xpm_file_to_image(data->mlx, COLLECTIBLE, &x, &y);
	data->maprender.xpm_floor = mlx_xpm_file_to_image(data->mlx, FLOOR, &x, &y);
	data->maprender.xpm_player = mlx_xpm_file_to_image(data->mlx, PLAYER, &x, &y);
	data->maprender.xpm_exit = mlx_xpm_file_to_image(data->mlx, EXIT, &x, &y);
}

void	add_image_to_window(t_data *data, char c, int x, int y)
{
	int x64;
	int y64;

	x64 = x * 64;
	y64 = y * 64;
	if(c == '1')
		mlx_put_image_to_window(data->mlx, data->window, data->maprender.xpm_wall, x64, y64);
	if(c == '0' || c == 'C' || c == 'E' || c == 'P')
		mlx_put_image_to_window(data->mlx, data->window, data->maprender.xpm_floor, x64, y64);
	if(c == 'P')
	{
		if((data->maprender.y_exit == y && data->maprender.x_exit == x))
		{
			mlx_put_image_to_window(data->mlx, data->window, data->maprender.xpm_floor, x64, y64);
			mlx_put_image_to_window(data->mlx, data->window, data->maprender.xpm_exit, x64, y64);
			mlx_put_image_to_window(data->mlx, data->window, data->maprender.xpm_player, x64, y64);
		}
		else
			mlx_put_image_to_window(data->mlx, data->window, data->maprender.xpm_player, x64, y64);
	}
	if(c == 'C')
		mlx_put_image_to_window(data->mlx, data->window, data->maprender.xpm_collectible, x64, y64);;
	if(c == 'E')
		mlx_put_image_to_window(data->mlx, data->window, data->maprender.xpm_exit, x64, y64);;
}

int	add_image_select_x_y(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	mlx_clear_window(data->mlx, data->window);
	while(data->map[i])
	{
		while(data->map[i][j] != '\0')
		{
			add_image_to_window(data, data->map[i][j], j, i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	map_render(t_data *data)
{
	data->window = mlx_new_window(data->mlx, data->x_map * 64, data->y_map * 64, "so_long");
	xpm_convert(data, 64, 64);
	add_image_select_x_y(data);
}