/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:49:42 by tbezerra          #+#    #+#             */
/*   Updated: 2024/08/06 14:40:22 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;
	int		fd;

	if (ac == 2 && extension_file(av[1]) != 1)
	{
		data = begin();
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("Error\nInvalid file\n");
			end_game(data);
			return (1);
		}
		data->name_map = av[1];
		if (read_map(av[1], data) == 1)
			return (1);
		if (map_check(data) == 1)
			end_game(data);
		map_config(data, data->name_map);
		bg_game(data);
		return (0);
	}
	if (ac != 2)
		ft_printf("Error\nInvalid number of arguments\n");
}
