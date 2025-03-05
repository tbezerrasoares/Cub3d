/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:39:04 by tbezerra          #+#    #+#             */
/*   Updated: 2024/08/08 19:12:16 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	extension_file(char *file)
{
	int	i;

	i = 0;
	while (*file)
	{
		if (file[i] == '.' && file[i + 1] == 'b' && file[i + 2] == 'e'
			&& file[i + 3] == 'r')
			i++;
		file++;
	}
	if ((ft_strncmp(&file[ft_strlen(file) - 4], ".ber", 4) != 0) || i != 1)
	{
		ft_printf("Error\nInvalid file extension\n");
		return (1);
	}
	return (0);
}

int	exit_player_check(t_data *data)
{
	int	i;
	int	j;
	int	exit;
	int	player;

	j = 0;
	exit = 0;
	player = 0;
	while (data->rows > j)
	{
		i = 0;
		while (data->cols > i)
		{
			if (data->map[j][i] == 'E')
				exit++;
			if (data->map[j][i] == 'P')
				player++;
			i++;
		}
		j++;
	}
	if (exit != 1 || player != 1)
		return (1);
	return (0);
}

int	collect_check(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->rows > j)
	{
		i = 0;
		while (data->cols > i)
		{
			if (data->map[j][i] == 'C')
				data->collect++;
			i++;
		}
		j++;
	}
	if (data->collect < 1)
		return (1);
	return (0);
}

int	rectangle_check(t_data *data)
{
	int	i;
	int	j;
	int	size;

	j = 0;
	size = ft_strlen(data->map[0]);
	while (data->rows > j)
	{
		i = 0;
		while (data->map[j][i])
			i++;
		if (data->map[j][i] == '\0' && j == data->rows - 1 && i != size)
			i++;
		if (i != size)
			return (1);
		j++;
	}
	return (0);
}

int	map_validation(t_data *data)
{
	if (exit_player_check(data) == 1)
	{
		ft_printf("Error\nProblem in the player or the exit\n");
		return (1);
	}
	if (collect_check(data) == 1)
	{
		ft_printf("Error\nProblem in the collectibles\n");
		return (1);
	}
	if (rectangle_check(data) == 1)
	{
		ft_printf("Error\nMap is not a rectangle\n");
		return (1);
	}
	return (0);
}
