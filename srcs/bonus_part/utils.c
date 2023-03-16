/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:21:32 by segurbuz          #+#    #+#             */
/*   Updated: 2023/03/14 23:21:33 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_nl(char *str)
{
	size_t	i;

	i = 0;
	while ((str[i] != '\0' && str[i] != '\n'))
	{
		i++;
	}
	return (i);
}

void	step_add_to_screen(t_data *data)
{
	char *step;

	step = ft_itoa(data->mapr.step);
	mlx_string_put(data->mlx, data->win, 5, 20, WHITE, "step: ");
	mlx_string_put(data->mlx, data->win, 45, 20, WHITE, step);
}

void	map_exit_check(t_data *data)
{
	if ((data->pl.y_player == data->mapr.y_exit \
		&& data->pl.x_player == data->mapr.x_exit))
	{
		if (data->value.c_count == 0)
			error_print("GAME FINISH!");
	}
}

void	error_print(char *str)
{
	ft_printf("%s", str);
	exit(0);
}
