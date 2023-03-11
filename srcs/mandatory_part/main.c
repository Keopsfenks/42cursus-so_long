#include "so_long.h"

void	map(t_data *data, char *path)
{
	data->map_extension = path;
	map_size(data, path);
	map_create(data, path);
	temp_map_create(data, path);
	check_map(data);
}


int main(int ac, char **av)
{
	t_data *data;

	if(ac == 2)
	{
		data = malloc(sizeof (t_data));
		map(data, ft_strjoin("/Users/segurbuz/Desktop/42cursus-so_long/srcs/maps/", av[1]));
		data->mlx = mlx_init();
		map_render(data);
		mlx_loop(data->mlx);
	}
	error_print("ARGUMENT ERROR");
}