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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	map_exit_check(t_data *data)
{
	ft_printf("step: %d\n", data->mapr.step);
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
