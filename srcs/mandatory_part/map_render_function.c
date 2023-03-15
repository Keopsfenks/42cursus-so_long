/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:46:28 by segurbuz          #+#    #+#             */
/*   Updated: 2023/03/14 22:46:29 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_convert(t_data *data, int x, int y)
{
	data->mapr.wall = mlx_xpm_file_to_image(data->mlx, WALL, &x, &y);
	data->mapr.coll = mlx_xpm_file_to_image(data->mlx, COLLEC, &x, &y);
	data->mapr.fl = mlx_xpm_file_to_image(data->mlx, FLOOR, &x, &y);
	data->mapr.pl = mlx_xpm_file_to_image(data->mlx, PLAYER, &x, &y);
	data->mapr.ex = mlx_xpm_file_to_image(data->mlx, EXIT, &x, &y);
}

void	add_image_to_window(t_data *data, char c, int x, int y)
{
	int	i;
	int	j;

	i = x * 64;
	j = y * 64;
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->mapr.wall, i, j);
	if (c == '0' || c == 'C' || c == 'E' || c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->mapr.fl, i, j);
	if (c == 'P')
	{
		if ((data->mapr.y_exit == y && data->mapr.x_exit == x))
		{
			mlx_put_image_to_window(data->mlx, data->win, data->mapr.fl, i, j);
			mlx_put_image_to_window(data->mlx, data->win, data->mapr.ex, i, j);
			mlx_put_image_to_window(data->mlx, data->win, data->mapr.pl, i, j);
		}
		else
			mlx_put_image_to_window(data->mlx, data->win, data->mapr.pl, i, j);
	}
	if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->mapr.coll, i, j);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->mapr.ex, i, j);
}

int	add_image_select_x_y(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_clear_window(data->mlx, data->win);
	while (data->map[i])
	{
		while (data->map[i][j] != '\0')
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
	int	size_x;
	int	size_y;

	size_x = data->x_map * 64;
	size_y = data->y_map * 64;
	data->win = mlx_new_window(data->mlx, size_x, size_y, "so_long");
	xpm_convert(data, 64, 64);
	add_image_select_x_y(data);
}
