/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:14:27 by segurbuz          #+#    #+#             */
/*   Updated: 2023/03/14 20:14:28 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_size_control(t_data *data)
{
	int		i;
	size_t	j;

	i = 0;
	j = ft_strlen_nl(data->map[i]);
	while (data->map[i])
	{
		if (j != ft_strlen_nl(data->map[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_map(t_data *data)
{
	int	x;
	int	y;

	data->value.value = "ECP";
	if (map_size_control(data) == 0)
		error_print("MAP ERROR = SIZE");
	if (map_value_control(data) == 0)
		error_print("MAP ERROR = VALUE");
	if (map_ber_control(data) == 0)
		error_print("MAP ERROR = UNKNOWN");
	if (map_unknown_value_control(data) == 0)
		error_print("MAP ERROR = UNKNOWN VALUE");
	if (map_firstandlast_wall_control(data) == 0)
		error_print("MAP ERROR = WALL");
	find_player_x_y(data);
	x = data->mapr.x_player;
	y = data->mapr.y_player;
	find_exit_x_y(data);
	map_value_left_control(data, x, y);
	map_value_left_control_2(data);
}

void	map_value_left_control(t_data *data, int x, int y)
{
	data->temp_map[y][x] = '.';
	if (data->temp_map[y][x - 1] != '1' && data->temp_map[y][x - 1] != '.')
		map_value_left_control(data, x - 1, y);
	if (data->temp_map[y + 1][x] != '1' && data->temp_map[y + 1][x] != '.')
		map_value_left_control(data, x, y + 1);
	if (data->temp_map[y - 1][x] != '1' && data->temp_map[y - 1][x] != '.')
		map_value_left_control(data, x, y - 1);
	if (data->temp_map[y][x + 1] != '1' && data->temp_map[y][x + 1] != '.')
		map_value_left_control(data, x + 1, y);
	else
	{
		data->temp_map[y][x] = '.';
	}
}

void	map_value_left_control_2(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->temp_map[i])
	{
		while (data->temp_map[i][j] != '\0')
		{
			if (data->temp_map[i][j] == 'E' || data->temp_map[i][j] == 'C' \
				|| data->temp_map[i][j] == 'P')
				error_print("MAP ERROR = VALUE LEFT");
			j++;
		}
		j = 0;
		i++;
	}
}

int	map_ber_control(t_data *data)
{
	char	*str;
	int		a;

	str = ft_strrchr(data->map_arg, '.');
	if (str == NULL)
		return (0);
	else if ((ft_strcmp(str, ".ber") != 0) && ft_strlen(str) != 4)
		return (0);
	a = ft_strlen(data->map_arg);
	if (data->map_arg[0] == '.' || (data->map_arg[a - 4] == '.'
			&& (data->map_arg[a - 5] == '.' || data->map_arg[a - 5] == '/')))
		return (0);
	return (1);
}
