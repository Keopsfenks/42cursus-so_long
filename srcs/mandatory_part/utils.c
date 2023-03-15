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

void	map_exit_check(t_data *data)
{
	if ((data->mapr.y_player == data->mapr.y_exit \
		&& data->mapr.x_player == data->mapr.x_exit))
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
