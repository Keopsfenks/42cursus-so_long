/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:55:52 by segurbuz          #+#    #+#             */
/*   Updated: 2023/03/14 19:55:53 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_up(t_data *data)
{
	data->pl.y_player -= 1;
	data->mapr.step += 1;
	data->pl.y_check = -1;
	if (data->map[data->pl.y_player][data->pl.x_player] == 'C')
		data->value.c_count -= 1;
	if ((data->pl.y_player + 1 == data->mapr.y_exit \
		&& data->pl.x_player == data->mapr.x_exit))
	{
		data->map[data->pl.y_player][data->pl.x_player] = 'P';
		data->map[data->pl.y_player + 1][data->pl.x_player] = 'E';
	}
	else
	{
		data->map[data->pl.y_player][data->pl.x_player] = 'P';
		data->map[data->pl.y_player + 1][data->pl.x_player] = '0';
	}
	map_exit_check(data);
}

void	player_move_down(t_data *data)
{
	data->pl.y_player += 1;
	data->mapr.step += 1;
	data->pl.y_check = 1;
	if (data->map[data->pl.y_player][data->pl.x_player] == 'C')
		data->value.c_count -= 1;
	if ((data->pl.y_player - 1 == data->mapr.y_exit \
		&& data->pl.x_player == data->mapr.x_exit))
	{
		data->map[data->pl.y_player][data->pl.x_player] = 'P';
		data->map[data->pl.y_player - 1][data->pl.x_player] = 'E';
	}
	else
	{
		data->map[data->pl.y_player][data->pl.x_player] = 'P';
		data->map[data->pl.y_player - 1][data->pl.x_player] = '0';
	}
	map_exit_check(data);
}

void	player_move_left(t_data *data)
{
	data->pl.x_player -= 1;
	data->mapr.step += 1;
	data->pl.x_check = -1;
	if (data->map[data->pl.y_player][data->pl.x_player] == 'C')
		data->value.c_count -= 1;
	if ((data->pl.y_player == data->mapr.y_exit \
		&& data->pl.x_player + 1 == data->mapr.x_exit))
	{
		data->map[data->pl.y_player][data->pl.x_player] = 'P';
		data->map[data->pl.y_player][data->pl.x_player + 1] = 'E';
	}
	else
	{
		data->map[data->pl.y_player][data->pl.x_player] = 'P';
		data->map[data->pl.y_player][data->pl.x_player + 1] = '0';
	}
	map_exit_check(data);
}

void	player_move_right(t_data *data)
{
	data->pl.x_player += 1;
	data->mapr.step += 1;
	data->pl.x_check = 1;
	if (data->map[data->pl.y_player][data->pl.x_player] == 'C')
		data->value.c_count -= 1;
	if ((data->pl.y_player == data->mapr.y_exit \
		&& data->pl.x_player - 1 == data->mapr.x_exit))
	{
		data->map[data->pl.y_player][data->pl.x_player] = 'P';
		data->map[data->pl.y_player][data->pl.x_player - 1] = 'E';
	}
	else
	{
		data->map[data->pl.y_player][data->pl.x_player] = 'P';
		data->map[data->pl.y_player][data->pl.x_player - 1] = '0';
	}
	map_exit_check(data);
}

int	key_hook_event(int keycode, t_data *data)
{
	int	x;
	int	y;

	x = data->pl.x_player;
	y = data->pl.y_player;
	if (keycode == ESC_KEY)
		error_print("GAME CLOSED");
	if (keycode == W_KEY \
		&& data->map[y - 1][x] != '1')
		 player_move_up(data);
	if (keycode == A_KEY \
		&& data->map[y][x - 1] != '1')
		player_move_left(data);
	if (keycode == S_KEY \
		&& data->map[y + 1][x] != '1')
		player_move_down(data);
	if (keycode == D_KEY \
		&& data->map[y][x + 1] != '1')
		player_move_right(data);
	mlx_clear_window(data->mlx, data->win);
	add_image_select_x_y(data);
	return (1);
}
