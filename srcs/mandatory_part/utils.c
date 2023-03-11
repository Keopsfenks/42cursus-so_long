#include "so_long.h"

size_t	ft_strlen_nl(char *str)
{
	size_t i;

	i = 0;
	while((str[i] != '\0' && str[i] != '\n'))
	{
		i++;
	}
	return (i);
}

void	error_print(char *str)
{
	ft_printf("%s", str);
	exit(0);
}


void	xpm_convert(t_data *data, int x, int y)
{
	data->xpm_wall = mlx_xpm_file_to_image(data->mlx, WALL, &x, &y);
	data->xpm_collectible = mlx_xpm_file_to_image(data->mlx, COLLECTIBLE, &x, &y);
	data->xpm_floor = mlx_xpm_file_to_image(data->mlx, FLOOR, &x, &y);
	data->xpm_player = mlx_xpm_file_to_image(data->mlx, PLAYER, &x, &y);
}
