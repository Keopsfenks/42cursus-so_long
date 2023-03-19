/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:46:28 by segurbuz          #+#    #+#             */
/*   Updated: 2023/03/14 22:46:29 by segurbuz         ###   ########.fr       */
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

void	player_animation(t_data *data, int x, int y)
{
	static int i = 0;

	if(data->pl.x_check == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->pl.d_img[i], x, y);
	else if(data->pl.x_check == -1)
		mlx_put_image_to_window(data->mlx, data->win, data->pl.a_img[i], x, y);
	else if(data->pl.y_check == -1)
		mlx_put_image_to_window(data->mlx, data->win, data->pl.j_img[i], x, y);
	else if(data->pl.y_check == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->pl.j_img[i], x, y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->pl.b_img[i], x, y);
	usleep(50000);
	if(data->pl.x_check != 0 || data->pl.y_check != 0)
	{
		printf("x = %d - y = %d\n", data->pl.x_check, data->pl.y_check);
		data->pl.x_check = 0;
		data->pl.y_check = 0;
	}
	i++;
	if(i == 8)
		i = 0;
}

void	collectible_animation(t_data *data, int x, int y)
{
	static int i = 0;
	mlx_put_image_to_window(data->mlx, data->win, data->coll.img[i], x, y);
	usleep(7000);
	i++;
	if(i == 16)
		i = 0;

}

void	add_image_to_window(t_data *data, char c, int x, int y)
{
	int	i;
	int	j;
	int d;

	d = 0;
	i = x * 64;
	j = y * 64;

	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->mapr.img[1], i, j);
	if (c == '0' || c == 'C' || c == 'E' || c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->mapr.img[0], i, j);
	if (c == 'P')
		player_animation(data, i, j);
	if (c == 'C')
		collectible_animation(data, i, j);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->mapr.img[2], i, j);
	if (c == 'M')
	{
		enemy_move_function(data);
		mlx_put_image_to_window(data->mlx, data->win, data->mapr.img[2], i , j);
	}
	step_add_to_screen(data);
}

int	add_image_select_x_y(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_clear_window(data->mlx, data->win);
	while (data->map[i])
	{
		while (data->map[i][j] != '\0')
		{
			add_image_to_window(data, data->map[i][j], j, i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	map_render(t_data *data)
{
	int	size_x;
	int	size_y;

	size_x = data->x_map * 64;
	size_y = data->y_map * 64;
	data->win = mlx_new_window(data->mlx, size_x, size_y, "so_long");
	xpm_convert_to_wall_and_floor(data, 64, 64);
	xpm_convert_to_player_b(data, 64, 64);
	xpm_convert_to_player_right(data, 64, 64);
	xpm_convert_to_player_left(data, 64, 64);
	xpm_convert_to_player_up_and_down(data, 64, 64);
	xpm_convert_to_collectible(data, 64, 64);
	add_image_select_x_y(data);
}
