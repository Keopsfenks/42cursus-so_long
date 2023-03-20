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
#include "textures.h"

void	enemy_animation_line(t_data *data, int x, int y)
{
	if (data->enemy.check_wall == 0)
		enemy_animation(data, x, y);
	else if (data->enemy.check_wall == 1)
		reenemy_animation(data, x, y);
}

void	add_image_to_window_line_norm(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->mapr.img[0], x, y);
	mlx_put_image_to_window(data->mlx, data->win, data->mapr.img[2], x, y);
	player_animation(data, x, y);
}

void	add_image_to_window(t_data *data, char c, int x, int y)
{
	int	i;
	int	j;

	i = x * 64;
	j = y * 64;
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->mapr.img[1], i, j);
	if (c == '0' || c == 'C' || c == 'E' || c == 'P' || c == 'M')
		mlx_put_image_to_window(data->mlx, data->win, data->mapr.img[0], i, j);
	if (c == 'P')
	{
		if (data->mapr.y_exit == y && data->mapr.x_exit == x)
			add_image_to_window_line_norm(data, i, j);
		else
			player_animation(data, i, j);
	}
	if (c == 'C')
		collectible_animation(data, i, j);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->mapr.img[2], i, j);
	if (c == 'M')
		enemy_animation_line(data, i, j);
	step_add_to_screen(data);
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
	xpm_convert_to_wall_and_floor(data, 64, 64);
	xpm_convert_to_player_b(data, 64, 64);
	xpm_convert_to_player_right(data, 64, 64);
	xpm_convert_to_player_left(data, 64, 64);
	xpm_convert_to_player_up_and_down(data, 64, 64);
	xpm_convert_to_collectible(data, 64, 64);
	xpm_convert_to_enemy(data, 64, 64);
	xpm_convert_to_reenemy(data, 64, 64);
	add_image_select_x_y(data);
}
