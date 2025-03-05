/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:43:02 by tbezerra          #+#    #+#             */
/*   Updated: 2024/08/06 09:52:59 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_texture(t_data *data, char *texture, int y, int x)
{
	if (data->img.img)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img);
		data->img.img = 0;
	}
	data->img.img = mlx_xpm_file_to_image(data->mlx_ptr, texture,
			&data->img_size.x, &data->img_size.y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, x, y);
}

void	texture(t_data *data, int x, int y)
{
	char	position;

	position = data->map[y][x];
	if (position == '1')
		put_texture(data, BOX, y * SIZE, x * SIZE);
	else if (position == '0')
		put_texture(data, FLOOR, y * SIZE, x * SIZE);
	else if (position == 'C')
		put_texture(data, COLLECT, y * SIZE, x * SIZE);
	else if (position == 'E')
		put_texture(data, EXIT, y * SIZE, x * SIZE);
	else if (position == 'P')
		put_texture(data, PLAYER, y * SIZE, x * SIZE);
}

void	render_map(t_data *data)
{
	data->coord.y = 0;
	while (data->coord.y < data->rows)
	{
		data->coord.x = 0;
		while (data->coord.x < data->cols)
		{
			texture(data, data->coord.x, data->coord.y);
			data->coord.x += 1;
		}
		data->coord.y += 1;
	}
}

void	windows_open(t_data *data)
{
	if (data->mlx_ptr == NULL)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->cols * SIZE,
			data->rows * SIZE, "so_long");
	if (data->win_ptr == NULL)
		return ;
}

void	bg_game(t_data *data)
{
	windows_open(data);
	if (!data->win_ptr)
	{
		ft_printf("Error\nFailed to open window\n");
		return ;
	}
	render_map(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key_press, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
		&end_game, data);
	mlx_loop(data->mlx_ptr);
}
