/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:24:47 by tbezerra          #+#    #+#             */
/*   Updated: 2024/08/06 09:45:50 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*begin(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	bg_data(data);
	bg_window(data);
	return (data);
}

void	bg_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = NULL;
	data->img.img = NULL;
	data->img.addr = NULL;
	data->img.bpp = 0;
	data->img.line = 0;
	data->img.ednian = 0;
	data->img_size.y = SIZE;
	data->img_size.x = SIZE;
}

void	bg_data(t_data *data)
{
	data->map = NULL;
	data->copy_map = NULL;
	data->name_map = NULL;
	data->moves = 0;
	data->cols = 0;
	data->rows = 0;
	data->coins = 0;
	data->collect = 0;
	data->collect_check = 0;
	data->exit_check = 0;
	data->coord.x = 0;
	data->coord.y = 0;
	data->img_size.x = 0;
	data->img_size.y = 0;
}
