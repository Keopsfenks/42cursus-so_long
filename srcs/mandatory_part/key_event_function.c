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
	data->maprender.y_player -= 1;
	if (data->map[data->maprender.y_player][data->maprender.x_player] == 'C')
		data->value.c_count -= 1;
	if ((data->maprender.y_player + 1 == data->maprender.y_exit \
		&& data->maprender.x_player == data->maprender.x_exit))
	{
		data->map[data->maprender.y_player][data->maprender.x_player] = 'P';
		data->map[data->maprender.y_player + 1][data->maprender.x_player] = 'E';
	}
	else
	{
		data->map[data->maprender.y_player][data->maprender.x_player] = 'P';
		data->map[data->maprender.y_player + 1][data->maprender.x_player] = '0';
	}
	map_exit_check(data);
}

void	player_move_down(t_data *data)
{
	data->maprender.y_player += 1;
	if (data->map[data->maprender.y_player][data->maprender.x_player] == 'C')
		data->value.c_count -= 1;
	if ((data->maprender.y_player - 1 == data->maprender.y_exit \
		&& data->maprender.x_player == data->maprender.x_exit))
	{
		data->map[data->maprender.y_player][data->maprender.x_player] = 'P';
		data->map[data->maprender.y_player - 1][data->maprender.x_player] = 'E';
	}
	else
	{
		data->map[data->maprender.y_player][data->maprender.x_player] = 'P';
		data->map[data->maprender.y_player - 1][data->maprender.x_player] = '0';
	}
	map_exit_check(data);
}

void	player_move_left(t_data *data)
{
	data->maprender.x_player -= 1;
	if (data->map[data->maprender.y_player][data->maprender.x_player] == 'C')
		data->value.c_count -= 1;
	if ((data->maprender.y_player == data->maprender.y_exit \
		&& data->maprender.x_player + 1 == data->maprender.x_exit))
	{
		data->map[data->maprender.y_player][data->maprender.x_player] = 'P';
		data->map[data->maprender.y_player][data->maprender.x_player + 1] = 'E';
	}
	else
	{
		data->map[data->maprender.y_player][data->maprender.x_player] = 'P';
		data->map[data->maprender.y_player][data->maprender.x_player + 1] = '0';
	}
	map_exit_check(data);
}

void	player_move_right(t_data *data)
{
	data->maprender.x_player += 1;
	if (data->map[data->maprender.y_player][data->maprender.x_player] == 'C')
		data->value.c_count -= 1;
	if ((data->maprender.y_player == data->maprender.y_exit \
		&& data->maprender.x_player - 1 == data->maprender.x_exit))
	{
		data->map[data->maprender.y_player][data->maprender.x_player] = 'P';
		data->map[data->maprender.y_player][data->maprender.x_player - 1] = 'E';
	}
	else
	{
		data->map[data->maprender.y_player][data->maprender.x_player] = 'P';
		data->map[data->maprender.y_player][data->maprender.x_player - 1] = '0';
	}
	map_exit_check(data);
}

void	map_exit_check(t_data *data)
{
	if ((data->maprender.y_player == data->maprender.y_exit \
		&& data->maprender.x_player == data->maprender.x_exit))
	{
		if (data->value.c_count == 0)
			error_print("GAME FINISH!");
	}
}

int	key_hook_event(int keycode, t_data *data)
{
	int	x;
	int	y;

	x = data->maprender.x_player;
	y = data->maprender.y_player;
	if (keycode == ESC_KEY)
		error_print("GAME CLOSED");
	if ((keycode == W_KEY || keycode == UP_KEY) \
		&& data->map[y - 1][x] != '1')
		player_move_up(data);
	if ((keycode == A_KEY || keycode == LEFT_KEY) \
		&& data->map[y][x - 1] != '1')
		player_move_left(data);
	if ((keycode == S_KEY || keycode == DOWN_KEY) \
		&& data->map[y + 1][x] != '1')
		player_move_down(data);
	if ((keycode == D_KEY || keycode == RIGHT_KEY) \
		&& data->map[y][x + 1] != '1')
		player_move_right(data);
	mlx_clear_window(data->mlx, data->window);
	add_image_select_x_y(data);
	return (0);
}
