/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_check_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:18:24 by tbezerra          #+#    #+#             */
/*   Updated: 2024/08/06 14:23:33 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cols_wall_check(t_data *data)
{
	int	y;
	int	x;
	int	columns;

	columns = data->cols - 1;
	y = 1;
	while (data->rows > y)
	{
		x = 0;
		while (data->cols > x)
		{
			if (data->map[y][0] != '1')
				return (1);
			if (data->map[y][columns] != '1')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	first_last_line_check(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = data->rows - 1;
	while (data->map[0][x])
	{
		if (data->map[0][x] != '1' && data->map[0][x] != '\n'
			&& data->map[0][x] != '\0')
			return (1);
		x++;
	}
	x = 0;
	while (data->map[y][x])
	{
		if (data->map[y][x] != '1' &&
			data->map[y][x] != '\n'
			&& data->map[y][x] != '\0')
			return (1);
		x++;
	}
	return (0);
}

int	characters_check(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->rows > y)
	{
		x = 0;
		while (data->cols > x)
		{
			if (data->map[y][x] != 'C' && data->map[y][x] != 'E'
				&& data->map[y][x] != 'P' && data->map[y][x] != '1' &&
				data->map[y][x] != '0' && data->map[y][x] != '\0' &&
				data->map[y][x] != '\n')
			{
				ft_printf("Error\nHave an invalid character in the map!\n");
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	map_check(t_data *data)
{
	if (map_validation(data) == 1)
		return (1);
	if (cols_wall_check(data) == 1)
	{
		ft_printf("Error\nInvalid map\n");
		return (1);
	}
	if (first_last_line_check(data) == 1)
	{
		ft_printf("Error\nInvalid map\n");
		return (1);
	}
	if (characters_check(data) == 1)
		return (1);
	return (0);
}
