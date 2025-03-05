# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 16:01:55 by tbezerra          #+#    #+#              #
#    Updated: 2024/08/06 10:39:31 by tbezerra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HEADER = ./
MAKE = make -C
CC = cc
LIBFT = ./includes/libft/libft.a
MINILIBX = ./includes/mlx/libmlx_Linux.a
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -L ./includes/mlx -lm -lmlx -Ilmlx -lXext -lX11

SRCS = main.c moves.c moves_utis.c free.c begin.c utis_map.c game_config.c\
	maps_check.c maps_check_2.c render_game.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(LIBFT):
	$(MAKE) ./includes/libft

$(MLX):
	$(MAKE) ./includes/mlx

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)