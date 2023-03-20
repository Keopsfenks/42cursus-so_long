/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:43:36 by segurbuz          #+#    #+#             */
/*   Updated: 2023/03/19 21:43:37 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_move(t_data *data, int check)
{
	if (check == 0)
	{
		data->enemy.x_enemy -= 1;
		data->map[data->enemy.y_enemy][data->enemy.x_enemy + 1] = '0';
		data->map[data->enemy.y_enemy][data->enemy.x_enemy] = 'M';
	}
	else
	{
		data->enemy.x_enemy += 1;
		data->map[data->enemy.y_enemy][data->enemy.x_enemy - 1] = '0';
		data->map[data->enemy.y_enemy][data->enemy.x_enemy] = 'M';
	}
}

void	check_enemy_move(t_data *data)
{
	if (data->enemy.x_enemy == data->pl.x_player
		&& data->enemy.y_enemy == data->pl.y_player)
		error_print("CAUGHT BY THE ENEMY");
	if (data->map[data->enemy.y_enemy][data->enemy.x_enemy - 1] == '1'
			|| data->map[data->enemy.y_enemy][data->enemy.x_enemy - 1] == 'C'
			|| data->map[data->enemy.y_enemy][data->enemy.x_enemy - 1] == 'E'
			|| data->map[data->enemy.y_enemy][data->enemy.x_enemy - 1] == 'M')
		data->enemy.check_wall = 1;
	if (data->map[data->enemy.y_enemy][data->enemy.x_enemy + 1] == '1'
			|| data->map[data->enemy.y_enemy][data->enemy.x_enemy + 1] == 'C'
			|| data->map[data->enemy.y_enemy][data->enemy.x_enemy + 1] == 'E'
			|| data->map[data->enemy.y_enemy][data->enemy.x_enemy + 1] == 'M')
		data->enemy.check_wall = 0;
}

int	enemy_move_function(t_data *data)
{
	add_image_select_x_y(data);
	usleep(10000);
	check_enemy_move(data);
	enemy_move(data, data->enemy.check_wall);
	return (0);
}
