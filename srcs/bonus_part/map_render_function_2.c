/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_function_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 06:23:08 by segurbuz          #+#    #+#             */
/*   Updated: 2023/03/20 06:23:09 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_animation(t_data *data, int x, int y)
{
	static int	i = 0;

	if (data->pl.x_check == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->pl.d_img[i], x, y);
	else if (data->pl.x_check == -1)
		mlx_put_image_to_window(data->mlx, data->win, data->pl.a_img[i], x, y);
	else if (data->pl.y_check == -1)
		mlx_put_image_to_window(data->mlx, data->win, data->pl.j_img[i], x, y);
	else if (data->pl.y_check == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->pl.j_img[i], x, y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->pl.b_img[i], x, y);
	if (data->pl.x_check != 0 || data->pl.y_check != 0)
	{
		data->pl.x_check = 0;
		data->pl.y_check = 0;
	}
	i++;
	if (i == 8)
		i = 0;
	usleep(20000);
}

void	collectible_animation(t_data *data, int x, int y)
{
	static int	i = 0;

	mlx_put_image_to_window(data->mlx, data->win, data->coll.img[i], x, y);
	i++;
	if (i == 16)
		i = 0;
	usleep(20000);
}

void	enemy_animation(t_data *data, int x, int y)
{
	static int	i = 0;

	mlx_put_image_to_window(data->mlx, data->win, data->enemy.img[i], x, y);
	i++;
	if (i == 8)
		i = 0;
	usleep(20000);
}

void	reenemy_animation(t_data *data, int x, int y)
{
	static int	i = 0;

	mlx_put_image_to_window(data->mlx, data->win, data->enemy.r_img[i], x, y);
	i++;
	if (i == 8)
		i = 0;
	usleep(20000);
}
