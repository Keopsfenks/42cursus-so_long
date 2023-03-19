/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_function_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:03:53 by segurbuz          #+#    #+#             */
/*   Updated: 2023/03/15 00:03:53 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_unknown_value_control(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (data->map[i])
	{
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j - 1] != '1' && data->map[i][j - 1] != '0' \
				&& data->map[i][j - 1] != 'E' && data->map[i][j - 1] != 'C' \
				&& data->map[i][j - 1] != 'P' && data->map[i][j - 1] != 'M')
				return (0);
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

int	map_firstandlast_wall_control(t_data *data)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (data->map[i])
	{
		if (data->map[i][0] != '1' || data->map[i][data->x_map - 1] != '1')
			return (0);
		if (i == 0 || i == data->y_map - 1)
		{
			while (data->map[i][j] != '\0')
			{
				if (data->map[i][j - 1] != '1')
					return (0);
				j++;
			}
		}
		j = 1;
		i++;
	}
	return (1);
}

int	map_value_control(t_data *data)
{
	int	i;
	int	j;
	int	d;

	i = 0;
	j = 0;
	while (data->value.value[data->value.b] != '\0')
	{
		while (data->map[i])
		{
			while (data->map[i][j] != '\0' && data->map[i][j] != '\n')
			{
				if (data->map[i][j] == data->value.value[data->value.b])
					d = check_value(data->map[i][j], data);
				j++;
			}
			j = 0;
			i++;
		}
		j = 0;
		i = 0;
		data->value.b++;
	}
	return (d);
}

int	check_value(char c, t_data *data)
{
	if (c == 'E')
		data->value.e_count++;
	else if (c == 'P')
		data->value.p_count++;
	else if (c == 'C')
		data->value.c_count++;
	if (data->value.e_count != 1 || data->value.p_count != 1 \
		|| data->value.c_count < 1)
		return (0);
	return (1);
}
