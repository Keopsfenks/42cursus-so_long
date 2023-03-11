#include "so_long.h"

void	map_create(t_data *data, char *path)
{
	int fd;
	int i;

	i = 0;
	fd = open(path, O_RDONLY);
	if(fd < 0)
		error_print("MAP ERROR = UNKNOWN");
	data->map = ft_calloc(sizeof(char *), data->y_map + 1);
	while(data->y_map > i)
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
	int fd;
	char *a;

	fd = open(path, O_RDONLY);
	if(fd < 0)
		error_print("MAP ERROR = UNKNOWN");
	a = get_next_line(fd);
	if (!a)
		error_print("MAP ERROR = UNKNOWN");
	data->x_map = ft_strlen_nl(a);
	free(a);
	while(1)
	{
		a = get_next_line(fd);
		data->y_map += 1;
		if(!a)
			break ;
		free(a);
	}
	close(fd);
}

int	map_size_control(t_data *data)
{
	int 	i;
	size_t	j;

	i = 0;
	j = ft_strlen_nl(data->map[i]);
	while(data->map[i])
	{
		if(j != ft_strlen_nl(data->map[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_map(t_data *data)
{
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
	if(map_value_left_control(data, data->x_player, data->y_player) == 0)
		error_print("MAP ERROR = VALUE LEFT");
}

void find_player_x_y(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(data->temp_map[i])
	{
		while(data->temp_map[i][j] != '\0')
		{
			if(data->temp_map[i][j] == 'P')
			{
				data->x_player = j;
				data->y_player = i;
				return;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	map_value_left_control(t_data *data, int x, int y)
{
	int d;

	d = 0;
	data->temp_map[y][x] = '.';
	if(data->temp_map[y][x - 1] != '1' && data->temp_map[y][x - 1] != '.')
		map_value_left_control(data, x - 1, y);
	if(data->temp_map[y + 1][x] != '1' && data->temp_map[y + 1][x] != '.')
		map_value_left_control(data, x, y + 1);
	if(data->temp_map[y - 1][x] != '1' && data->temp_map[y - 1][x] != '.')
		map_value_left_control(data, x, y - 1);
	if(data->temp_map[y][x + 1] != '1' && data->temp_map[y][x + 1] != '.')
		map_value_left_control(data, x + 1, y);
	else
	{
		data->temp_map[y][x] = '.';
		d += map_value_left_control_2(data);
		return (d);
	}
	return (d);
}

int map_value_left_control_2(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while(data->temp_map[i])
	{
		while(data->temp_map[i][j] != '\0')
		{
			if(data->temp_map[i][j] == 'E' || data->temp_map[i][j] == 'C'
			   || data->temp_map[i][j] == 'P')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int map_ber_control(t_data *data)
{
	int len;
	int i;
	int b;
	char *ber;
	int d;

	ber = ".ber";
	b = 0;
	i = 42;
	d = 0;
	len = ft_strlen_nl(data->map_extension);
	while(i < len)
	{
		if(data->map_extension[i] == ber[b])
		{
			d++;
			b++;
		}
		i++;
	}
	if(d == 4)
		return (1);
	else
		return (0);
}

int	map_unknown_value_control(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while(data->map[i])
	{
		while(data->map[i][j] != '\0')
		{
			if (data->map[i][j - 1] != '1' && data->map[i][j - 1] != '0' \
				&& data->map[i][j - 1] != 'E' && data->map[i][j - 1] != 'C' \
				&& data->map[i][j - 1] != 'P')
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
	int i;
	int j;

	j = 1;
	i = 0;
	while(data->map[i])
	{
		if (data->map[i][0] != '1' || data->map[i][data->x_map - 1] != '1')
			return (0);
		if(i == 0 || i == data->y_map - 1)
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
	int i;
	int j;
	int d;

	i = 0;
	j = 0;
	while(data->value.value[data->value.b] != '\0')
	{
		while(data->map[i])
		{
			while(data->map[i][j] != '\0' && data->map[i][j] != '\n')
			{
				if(data->map[i][j] == data->value.value[data->value.b])
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
	if (data->value.e_count != 1 || data->value.p_count != 1 || data->value.c_count < 1)
		return (0);
	return (1);
}
