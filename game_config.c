/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:39:39 by tbezerra          #+#    #+#             */
/*   Updated: 2024/08/06 14:36:25 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			if (data->map[y][x] == 'P')
			{
				data->player.y = y;
				data->player.x = x;
			}
			x++;
		}
		y++;
	}
}

void	map_copy(t_data *data, char *map_name)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nInvalid file\n");
		exit(1);
	}
	data->copy_map = ft_calloc(data->rows, sizeof(char *));
	if (!data->copy_map)
		exit(1);
	while (i < data->rows)
	{
		data->copy_map[i] = get_next_line(fd);
		i++;
	}
}

int	flood_fill(char **copy_map, int y, int x, t_data *data)
{
	if (copy_map[y][x] == '1' || copy_map[y][x] == 'V')
		return (0);
	if (copy_map[y][x] == 'C')
		data->collect_check++;
	if (copy_map[y][x] == 'E')
		data->exit_check++;
	if (copy_map[y][x] != '1')
		copy_map[y][x] = 'V';
	flood_fill(copy_map, y, x - 1, data);
	flood_fill(copy_map, y, x + 1, data);
	flood_fill(copy_map, y - 1, x, data);
	flood_fill(copy_map, y + 1, x, data);
	if (data->exit_check != 1 || data->collect_check != data->collect)
		return (1);
	return (0);
}

void	map_config(t_data *data, char *map_name)
{
	player_position(data);
	map_copy(data, map_name);
	if (flood_fill(data->copy_map, data->player.y, data->player.x, data) == 1)
	{
		ft_printf("Error\nInvalid map\nNo path to the exit or collectibles\n");
		end_game(data);
		exit(1);
	}
	(void)map_name;
}
