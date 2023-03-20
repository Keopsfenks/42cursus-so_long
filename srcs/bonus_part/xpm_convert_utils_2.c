/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_convert_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 06:25:44 by segurbuz          #+#    #+#             */
/*   Updated: 2023/03/20 06:25:45 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "textures.h"

void	xpm_convert_to_player_up_and_down(t_data *data, int x, int y)
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

void	xpm_convert_to_collectible(t_data *data, int x, int y)
{
	data->coll.img = ft_calloc(sizeof (void *), 16);
	data->coll.img[0] = mlx_xpm_file_to_image(data->mlx, COL1, &x, &y);
	data->coll.img[1] = mlx_xpm_file_to_image(data->mlx, COL2, &x, &y);
	data->coll.img[2] = mlx_xpm_file_to_image(data->mlx, COL3, &x, &y);
	data->coll.img[3] = mlx_xpm_file_to_image(data->mlx, COL4, &x, &y);
	data->coll.img[4] = mlx_xpm_file_to_image(data->mlx, COL5, &x, &y);
	data->coll.img[5] = mlx_xpm_file_to_image(data->mlx, COL6, &x, &y);
	data->coll.img[6] = mlx_xpm_file_to_image(data->mlx, COL7, &x, &y);
	data->coll.img[7] = mlx_xpm_file_to_image(data->mlx, COL8, &x, &y);
	data->coll.img[8] = mlx_xpm_file_to_image(data->mlx, COL9, &x, &y);
	data->coll.img[9] = mlx_xpm_file_to_image(data->mlx, COL10, &x, &y);
	data->coll.img[10] = mlx_xpm_file_to_image(data->mlx, COL11, &x, &y);
	data->coll.img[11] = mlx_xpm_file_to_image(data->mlx, COL12, &x, &y);
	data->coll.img[12] = mlx_xpm_file_to_image(data->mlx, COL13, &x, &y);
	data->coll.img[13] = mlx_xpm_file_to_image(data->mlx, COL14, &x, &y);
	data->coll.img[14] = mlx_xpm_file_to_image(data->mlx, COL15, &x, &y);
	data->coll.img[15] = mlx_xpm_file_to_image(data->mlx, COL16, &x, &y);
}

void	xpm_convert_to_enemy(t_data *data, int x, int y)
{
	data->enemy.img = ft_calloc(sizeof (void *), 8);
	data->enemy.img[0] = mlx_xpm_file_to_image(data->mlx, ENEMY1, &x, &y);
	data->enemy.img[1] = mlx_xpm_file_to_image(data->mlx, ENEMY2, &x, &y);
	data->enemy.img[2] = mlx_xpm_file_to_image(data->mlx, ENEMY3, &x, &y);
	data->enemy.img[3] = mlx_xpm_file_to_image(data->mlx, ENEMY4, &x, &y);
	data->enemy.img[4] = mlx_xpm_file_to_image(data->mlx, ENEMY5, &x, &y);
	data->enemy.img[5] = mlx_xpm_file_to_image(data->mlx, ENEMY6, &x, &y);
	data->enemy.img[6] = mlx_xpm_file_to_image(data->mlx, ENEMY7, &x, &y);
	data->enemy.img[7] = mlx_xpm_file_to_image(data->mlx, ENEMY8, &x, &y);
}

void	xpm_convert_to_reenemy(t_data *data, int x, int y)
{
	data->enemy.r_img = ft_calloc(sizeof (void *), 8);
	data->enemy.r_img[0] = mlx_xpm_file_to_image(data->mlx, RENEMY1, &x, &y);
	data->enemy.r_img[1] = mlx_xpm_file_to_image(data->mlx, RENEMY2, &x, &y);
	data->enemy.r_img[2] = mlx_xpm_file_to_image(data->mlx, RENEMY3, &x, &y);
	data->enemy.r_img[3] = mlx_xpm_file_to_image(data->mlx, RENEMY4, &x, &y);
	data->enemy.r_img[4] = mlx_xpm_file_to_image(data->mlx, RENEMY5, &x, &y);
	data->enemy.r_img[5] = mlx_xpm_file_to_image(data->mlx, RENEMY6, &x, &y);
	data->enemy.r_img[6] = mlx_xpm_file_to_image(data->mlx, RENEMY7, &x, &y);
	data->enemy.r_img[7] = mlx_xpm_file_to_image(data->mlx, RENEMY8, &x, &y);
}
