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

void	enemy_move_to_left(t_data *data)
{
	data->map[data->enemy.y_enemy][data->enemy.x_enemy + 1] = '0';
	data->map[data->enemy.y_enemy][data->enemy.x_enemy] = 'M';
	printf("%s\n", data->map[data->enemy.y_enemy]);
}

void enemy_move_to_right(t_data *data)
{
	data->map[data->enemy.y_enemy][data->enemy.x_enemy - 1] = '0';
	data->map[data->enemy.y_enemy][data->enemy.x_enemy] = 'M';
	printf("%s\n", data->map[data->enemy.y_enemy]);
}

int	enemy_move_function(t_data *data)
{
	usleep(70000);
	if ((data->map[data->enemy.y_enemy][data->enemy.x_enemy - 1] != '1' && data->enemy.check_wall == 0))
	{
		data->enemy.x_enemy -= 1;
		enemy_move_to_left(data);
		return (0);
	}
	data->enemy.check_wall = 1;
	if((data->map[data->enemy.y_enemy][data->enemy.x_enemy + 1] != '1' && data->enemy.check_wall == 1))
	{
		data->enemy.x_enemy += 1;
		enemy_move_to_right(data);
		return (0);
	}
	data->enemy.check_wall = 0;
	return (0);
}