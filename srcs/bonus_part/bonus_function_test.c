#include "so_long.h"
#include "textures.h"

int	animation_function(t_data *data)
{
	static int i = 0;
	int d = 0;

	mlx_clear_window(data->mlx, data->win);
	while(d < 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img[i], 64, 64);
		i++;
		d++;
		usleep(70000);
	}
	if(i == 3)
		i = 0;
	return 0;
}

int main()
{
	t_data *data;

	int x = 64;
	int y = 64;
	data = ft_calloc(sizeof (t_data), 1);
	data->img = ft_calloc(sizeof (char *), 3);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 1000, "so_long");
	data->img[0] = mlx_xpm_file_to_image(data->mlx, HEROXPM1, &x, &y);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, HEROXPM2, &x, &y);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, HEROXPM3, &x, &y);

	mlx_loop_hook(data->mlx, animation_function, data);
	mlx_loop(data->mlx);
}