#include "so_long.h"

static void	map(t_data *data, char *path)
{
	data->map_extension = path;
	map_size(data, path);
	map_create(data, path);

}


int main(int ac, char **av)
{
	t_data *data;

	if(ac == 2)
	{
		data = ft_calloc(sizeof (t_data), 1);
		data->mlx = mlx_init();
		map(data, ft_strjoin("/Users/segurbuz/Desktop/42cursus-so_long/srcs/maps/", av[1]));
		check_map(data);

		data->window = mlx_new_window(data->mlx, data->x_map * 64, data->y_map * 64, "so_long");

		mlx_loop(data->mlx);
	}
	error_print("ARGUMENT ERROR");
}