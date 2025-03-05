/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:49:51 by tbezerra          #+#    #+#             */
/*   Updated: 2024/08/06 10:31:51 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "./includes/libft/libft.h"
#include "./includes/mlx/mlx.h"

#define SIZE 32
#define FLOOR "./imgs/back.xpm"
#define PLAYER "./imgs/player.xpm"
#define BOX "./imgs/box.xpm"
#define COLLECT "./imgs/coin.xpm"
#define EXIT "./imgs/End.xpm"

typedef struct s_loc
{
	int		x;
	int		y;
}	t_loc;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		line;
	int		bpp;
	int		ednian;
}	t_img;

typedef struct s_data
{
	char	**map;
	char	**copy_map;
	char	*name_map;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;

	t_loc	player;
	t_loc	coord;
	t_loc	img_size;

	int		moves;
	int		rows;
	int		cols;
	int		collect;
	int		coins;
	int		collect_check;
	int		exit_check;
}	t_data;

//Funtions//
int		extension_file(char *file);
void	bg_window(t_data *data);
void	bg_data(t_data *data);
t_data	*begin(void);
void	bg_window(t_data *data);
void	bg_data(t_data *data);
void	put_texture(t_data *data, char *texture, int y, int x);
void	texture(t_data *data, int x, int y);
void	render_map(t_data *data);
void	windows_open(t_data *data);
void	bg_game(t_data *data);
int		count_lines(char *map_name);
void	fill_map(char *map_name, t_data *data);
int		collun_size(char *line);
int		read_map(char *map_name, t_data *data);
int		key_press(int key, t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	moves_checek(t_data *data);
void	move_up_mecanicis(t_data *data);
void	move_down_mecanicis(t_data *data);
void	move_right_mecanicis(t_data *data);
void	move_left_mecanicis(t_data *data);
int		end_game(t_data *data);
void	map_free(t_data *data, char **map);
void	free_copy_map(t_data *data, char **map);
void	free_all(t_data *data);
void	player_position(t_data *data);
int		exit_player_check(t_data *data);
int		collect_check(t_data *data);
int		rectangle_check(t_data *data);
int		cols_wall_check(t_data *data);
int		first_last_line_check(t_data *data);
int		characters_check(t_data *data);
void	map_copy(t_data *data, char *map_name);
void	map_config(t_data *data, char *map_name);
int		flood_fill(char **copy_map, int y, int x, t_data *data);
int		map_check(t_data *data);
int		map_validation(t_data *data);