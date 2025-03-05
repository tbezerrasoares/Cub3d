/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utis_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:32:32 by tbezerra          #+#    #+#             */
/*   Updated: 2024/08/06 14:33:43 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *map_name)
{
	char	*tmp;
	int		rows;
	int		fd;

	rows = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFailed to open the map!\n");
		return (-1);
	}
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		rows++;
		tmp = get_next_line(fd);
	}
	close(fd);
	free (tmp);
	return (rows);
}

/*int count_lines(char *map_name)
{
    FILE *file = fopen(map_name, "r");
    if (file == NULL)
    {
        printf("Error\nInvalid file\n");
        return 0;
    }

    int ch;
    int lines = 0;
    while (!feof(file))
    {
        ch = fgetc(file);
        if (ch == '\n')
        {
            lines++;
        }
    }
	ft_printf("lines: %d\n", lines);
    fclose(file);
    return lines;
}*/

void	fill_map(char *map_name, t_data *data)
{
	int		i;
	int		fd;

	i = 0;
	fd = open(map_name, O_RDONLY);
	while (i < data->rows)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	collun_size(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n' && line[i] != '\r')
		i++;
	return (i);
}

int	read_map(char *map_name, t_data *data)
{
	char	fd;

	data->rows = count_lines(map_name);
	if (data->rows == 0)
	{
		ft_printf("Error\nInvalid file\n");
		end_game(data);
		return (1);
	}
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nInvalid file\n");
		end_game(data);
		return (1);
	}
	data->map = ft_calloc(data->rows, sizeof(char *));
	if (!data->map)
		return (1);
	fill_map(map_name, data);
	data->cols = collun_size(data->map[0]);
	close(fd);
	return (0);
}
