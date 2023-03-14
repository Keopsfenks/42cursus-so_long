/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:03:17 by segurbuz          #+#    #+#             */
/*   Updated: 2023/03/14 20:03:18 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map(t_data *data, char *path)
{
	data->map_extension = path;
	map_size(data, path);
	map_create(data, path);
	temp_map_create(data, path);
	check_map(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		data = ft_calloc(sizeof (t_data), 1);
		data->mlx = mlx_init();
		map(data, ft_strjoin(MAP_EXTENSION, av[1]));
		map_render(data);
		mlx_hook(data->window, 2, 1L << 0, key_hook_event, data);
		mlx_loop(data->mlx);
	}
	error_print("ARGUMENT ERROR");
}
