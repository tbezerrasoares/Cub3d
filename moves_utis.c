/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:57:38 by tbezerra          #+#    #+#             */
/*   Updated: 2024/08/06 09:56:48 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moves_checek(t_data *data)
{
	if (data->map[data->player.y][data->player.x] == 'C')
	{
		data->map[data->player.y][data->player.x] = '0';
		data->coins++;
	}
	if (data->map[data->player.y][data->player.x] == 'E'
		&& data->coins == data->collect)
	{
		ft_printf("You win!\n");
		end_game(data);
	}
	data->moves++;
	ft_printf("Moves: %d\n", data->moves);
}

void	move_up_mecanicis(t_data *data)
{
	int	old_y;
	int	new_y;

	new_y = data->player.y - 1;
	old_y = data->player.y;
	if (data->map[new_y][data->player.x] == 'E')
	{
		put_texture(data, EXIT, new_y * SIZE, data->player.x * SIZE);
		put_texture(data, FLOOR, old_y * SIZE, data->player.x * SIZE);
		data->player.y = new_y;
		moves_checek(data);
		return ;
	}
	put_texture(data, PLAYER, new_y * SIZE, data->player.x * SIZE);
	if (data->map[old_y][data->player.x] == 'E')
		put_texture(data, EXIT, old_y * SIZE, data->player.x * SIZE);
	else
		put_texture(data, FLOOR, old_y * SIZE, data->player.x * SIZE);
	data->player.y = new_y;
	moves_checek(data);
}

void	move_down_mecanicis(t_data *data)
{
	int	old_y;
	int	new_y;

	new_y = data->player.y + 1;
	old_y = data->player.y;
	if (data->map[new_y][data->player.x] == 'E')
	{
		put_texture(data, EXIT, new_y * SIZE, data->player.x * SIZE);
		put_texture(data, FLOOR, old_y * SIZE, data->player.x * SIZE);
		data->player.y = new_y;
		moves_checek(data);
		return ;
	}
	put_texture(data, PLAYER, new_y * SIZE, data->player.x * SIZE);
	if (data->map[old_y][data->player.x] == 'E')
		put_texture(data, EXIT, old_y * SIZE, data->player.x * SIZE);
	else
		put_texture(data, FLOOR, old_y * SIZE, data->player.x * SIZE);
	data->player.y = new_y;
	moves_checek(data);
}

void	move_right_mecanicis(t_data *data)
{
	int	old_x;
	int	new_x;

	new_x = data->player.x + 1;
	old_x = data->player.x;
	if (data->map[data->player.y][new_x] == 'E')
	{
		put_texture(data, EXIT, data->player.y * SIZE, new_x * SIZE);
		put_texture(data, FLOOR, data->player.y * SIZE, old_x * SIZE);
		data->player.x = new_x;
		moves_checek(data);
		return ;
	}
	put_texture(data, PLAYER, data->player.y * SIZE, new_x * SIZE);
	if (data->map[data->player.y][old_x] == 'E')
		put_texture(data, EXIT, data->player.y * SIZE, old_x * SIZE);
	else
		put_texture(data, FLOOR, data->player.y * SIZE, old_x * SIZE);
	data->player.x = new_x;
	moves_checek(data);
}

void	move_left_mecanicis(t_data *data)
{
	int	old_x;
	int	new_x;

	new_x = data->player.x - 1;
	old_x = data->player.x;
	if (data->map[data->player.y][new_x] == 'E')
	{
		put_texture(data, EXIT, data->player.y * SIZE, new_x * SIZE);
		put_texture(data, FLOOR, data->player.y * SIZE, old_x * SIZE);
		data->player.x = new_x;
		moves_checek(data);
		return ;
	}
	put_texture(data, PLAYER, data->player.y * SIZE, new_x * SIZE);
	if (data->map[data->player.y][old_x] == 'E')
		put_texture(data, EXIT, data->player.y * SIZE, old_x * SIZE);
	else
		put_texture(data, FLOOR, data->player.y * SIZE, old_x * SIZE);
	data->player.x = new_x;
	moves_checek(data);
}
