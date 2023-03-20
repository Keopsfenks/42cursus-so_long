/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_convert_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 06:25:41 by segurbuz          #+#    #+#             */
/*   Updated: 2023/03/20 06:25:42 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "textures.h"

void	xpm_convert_to_wall_and_floor(t_data *data, int x, int y)
{
	data->mapr.img = ft_calloc(sizeof (void *), 3);
	data->mapr.img[0] = mlx_xpm_file_to_image(data->mlx, FLOOR, &x, &y);
	data->mapr.img[1] = mlx_xpm_file_to_image(data->mlx, WALL, &x, &y);
	data->mapr.img[2] = mlx_xpm_file_to_image(data->mlx, EXIT, &x, &y);
}

void	xpm_convert_to_player_b(t_data *data, int x, int y)
{
	data->pl.b_img = ft_calloc(sizeof(void *), 8);
	data->pl.b_img[0] = mlx_xpm_file_to_image(data->mlx, HEROXPM1, &x, &y);
	data->pl.b_img[1] = mlx_xpm_file_to_image(data->mlx, HEROXPM2, &x, &y);
	data->pl.b_img[2] = mlx_xpm_file_to_image(data->mlx, HEROXPM3, &x, &y);
	data->pl.b_img[3] = mlx_xpm_file_to_image(data->mlx, HEROXPM4, &x, &y);
	data->pl.b_img[4] = mlx_xpm_file_to_image(data->mlx, HEROXPM1, &x, &y);
	data->pl.b_img[5] = mlx_xpm_file_to_image(data->mlx, HEROXPM2, &x, &y);
	data->pl.b_img[6] = mlx_xpm_file_to_image(data->mlx, HEROXPM3, &x, &y);
	data->pl.b_img[7] = mlx_xpm_file_to_image(data->mlx, HEROXPM4, &x, &y);
}

void	xpm_convert_to_player_right(t_data *data, int x, int y)
{
	data->pl.d_img = ft_calloc(sizeof (void *), 8);
	data->pl.d_img[0] = mlx_xpm_file_to_image(data->mlx, HERORIGHT1, &x, &y);
	data->pl.d_img[1] = mlx_xpm_file_to_image(data->mlx, HERORIGHT2, &x, &y);
	data->pl.d_img[2] = mlx_xpm_file_to_image(data->mlx, HERORIGHT3, &x, &y);
	data->pl.d_img[3] = mlx_xpm_file_to_image(data->mlx, HERORIGHT4, &x, &y);
	data->pl.d_img[4] = mlx_xpm_file_to_image(data->mlx, HERORIGHT5, &x, &y);
	data->pl.d_img[5] = mlx_xpm_file_to_image(data->mlx, HERORIGHT6, &x, &y);
	data->pl.d_img[6] = mlx_xpm_file_to_image(data->mlx, HERORIGHT7, &x, &y);
	data->pl.d_img[7] = mlx_xpm_file_to_image(data->mlx, HERORIGHT8, &x, &y);
}

void	xpm_convert_to_player_left(t_data *data, int x, int y)
{
	data->pl.a_img = ft_calloc(sizeof (void *), 8);
	data->pl.a_img[0] = mlx_xpm_file_to_image(data->mlx, HEROLEFT1, &x, &y);
	data->pl.a_img[1] = mlx_xpm_file_to_image(data->mlx, HEROLEFT2, &x, &y);
	data->pl.a_img[2] = mlx_xpm_file_to_image(data->mlx, HEROLEFT3, &x, &y);
	data->pl.a_img[3] = mlx_xpm_file_to_image(data->mlx, HEROLEFT4, &x, &y);
	data->pl.a_img[4] = mlx_xpm_file_to_image(data->mlx, HEROLEFT5, &x, &y);
	data->pl.a_img[5] = mlx_xpm_file_to_image(data->mlx, HEROLEFT6, &x, &y);
	data->pl.a_img[6] = mlx_xpm_file_to_image(data->mlx, HEROLEFT7, &x, &y);
	data->pl.a_img[7] = mlx_xpm_file_to_image(data->mlx, HEROLEFT8, &x, &y);
}

void	xpm_convert_to_player_up(t_data *data, int x, int y)
{
	data->pl.j_img = ft_calloc(sizeof (void *), 8);
	data->pl.j_img[0] = mlx_xpm_file_to_image(data->mlx, HEROJUMP1, &x, &y);
	data->pl.j_img[1] = mlx_xpm_file_to_image(data->mlx, HEROJUMP2, &x, &y);
	data->pl.j_img[2] = mlx_xpm_file_to_image(data->mlx, HEROJUMP3, &x, &y);
	data->pl.j_img[3] = mlx_xpm_file_to_image(data->mlx, HEROJUMP4, &x, &y);
	data->pl.j_img[4] = mlx_xpm_file_to_image(data->mlx, HEROJUMP5, &x, &y);
	data->pl.j_img[5] = mlx_xpm_file_to_image(data->mlx, HEROJUMP6, &x, &y);
	data->pl.j_img[6] = mlx_xpm_file_to_image(data->mlx, HEROJUMP7, &x, &y);
	data->pl.j_img[7] = mlx_xpm_file_to_image(data->mlx, HEROJUMP8, &x, &y);
}
