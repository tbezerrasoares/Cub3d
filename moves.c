/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:07:11 by tbezerra          #+#    #+#             */
/*   Updated: 2024/08/06 09:55:23 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		ft_printf("\nThanks for playing!\n");
		end_game(data);
	}
	else if (key == 'w' || key == XK_Up)
		move_up(data);
	else if (key == 's' || key == XK_Down)
		move_down(data);
	else if (key == 'a' || key == XK_Left)
		move_left(data);
	else if (key == 'd' || key == XK_Right)
		move_right(data);
	return (0);
}

void	move_up(t_data *data)
{
	if (data->map[data->player.y - 1][data->player.x] == '1')
		return ;
	move_up_mecanicis(data);
}

void	move_down(t_data *data)
{
	if (data->map[data->player.y + 1][data->player.x] == '1')
		return ;
	move_down_mecanicis(data);
}

void	move_left(t_data *data)
{
	if (data->map[data->player.y][data->player.x - 1] == '1')
		return ;
	move_left_mecanicis(data);
}

void	move_right(t_data *data)
{
	if (data->map[data->player.y][data->player.x + 1] == '1')
		return ;
	move_right_mecanicis(data);
}
