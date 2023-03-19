/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_function_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:01:47 by segurbuz          #+#    #+#             */
/*   Updated: 2023/03/15 00:01:48 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_create(t_data *data, char *path)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_print("MAP ERROR = UNKNOWN");
	data->map = ft_calloc(sizeof(char *), data->y_map + 1);
	while (data->y_map > i)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	temp_map_create(t_data *data, char *path)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_print("MAP ERROR = UNKNOWN");
	data->temp_map = ft_calloc(sizeof(char *), data->y_map + 1);
	while (i < data->y_map)
	{
		data->temp_map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	map_size(t_data *data, char *path)
{
	char	*a;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_print("MAP ERROR = UNKNOWN");
	a = get_next_line(fd);
	if (!a)
		error_print("MAP ERROR = UNKNOWN");
	data->x_map = ft_strlen_nl(a);
	free(a);
	while (1)
	{
		a = get_next_line(fd);
		data->y_map += 1;
		if (!a)
			break ;
		free(a);
	}
	if (data->y_map < 3)
		error_print("MAP ERROR = SIZE");
	close(fd);
}

void	find_exit_x_y(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->temp_map[i])
	{
		while (data->temp_map[i][j] != '\0')
		{
			if (data->temp_map[i][j] == 'E')
			{
				data->mapr.x_exit = j;
				data->mapr.y_exit = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	find_player_x_y(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->temp_map[i])
	{
		while (data->temp_map[i][j] != '\0')
		{
			if (data->temp_map[i][j] == 'P')
			{
				data->pl.x_player = j;
				data->pl.y_player = i;
			}
			if (data->temp_map[i][j] == 'M')
			{
				data->enemy.x_enemy = j;
				data->enemy.y_enemy = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
