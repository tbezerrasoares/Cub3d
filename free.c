/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:47:28 by tbezerra          #+#    #+#             */
/*   Updated: 2024/08/06 09:47:09 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_data *data)
{
	get_next_line(-1);
	free_all (data);
	exit (0);
}

void	map_free(t_data *data, char **map)
{
	int	i;

	i = 0;
	if (!map[0])
	{
		free(data->map);
		return ;
	}
	while (i < data->rows)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	free_copy_map(t_data *data, char **map)
{
	int	i;

	i = 0;
	if (!map[0])
	{
		free(data->copy_map);
		return ;
	}
	while (i < data->rows)
	{
		free(data->copy_map[i]);
		i++;
	}
	free(data->copy_map);
}

void	free_all(t_data *data)
{
	if (!data)
		return ;
	if (data->map)
		map_free(data, data->map);
	if (data->copy_map)
		free_copy_map(data, data->copy_map);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->img.img)
		mlx_destroy_image(data->mlx_ptr, data->img.img);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free(data);
}
