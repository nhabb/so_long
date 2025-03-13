/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:05:40 by nhaber            #+#    #+#             */
/*   Updated: 2025/03/06 14:05:40 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "printf/ft_printf.h"
# include "libft/libft.h"
# include "getnextline/get_next_line.h"
# include <X11/X.h>
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# define TILE_SIZE 50

typedef struct s_image
{
	void	*ptr;
	int		width;
	int		height;
}			t_image;

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*window;
	void	*img_wall;
	t_image	*pl_im;
	void	*img_collectible;
	void	*img_exit;
	void	*img_empty;
	void	*ptr;
	int		map_height;
	int		map_width;
	int		collectibles;
	int		collected;
	int		coint_count;
	int		exit_count;
	int		player_count;
	int		player_x;
	int		player_y;
	int		keys[256256];
	int		moves;
}	t_long;

char	*ft_strcpy(char *dest, const char *src);
void	check_space(int fd);
void	close_file(int fd, t_long *game);
void	free_resources(char *line, t_long *game);
void	check_space(int fd);
void	free_map(t_long *game);
void	initialize_assets(t_long *game);
void	render_player(t_long *game);
void	print_map(char **map);
void	left(t_long *game);
void	load_player(t_long *game, int width, int height);
void	right(t_long *game);
void	render_map(t_long *game);
void	render_player(t_long *game);
void	load_textures(t_long *game);
void	render_tile(t_long *game, int x, int y);
void	back(t_long *game);
void	forward(t_long *game);
void	move_counter(t_long *game);
void	move_player(t_long *game, int new_x, int new_y);
void	flood_fill(char **map, int x, int y, t_long *game);
void	flood_fill_map(char **map_copy, t_long *game);
void	free_map_copy(char **map_copy, t_long *game);
int		parse_map_columns(int fd, t_long *game);
void	null_map(t_long *game);
void	print_map(char **map);
void	load_game(t_long *game);
void	window_cleaner(t_long *game);
void	cleanup_game(t_long *game);
int		check_path_to_exit(t_long *game);
int		check_map_copy(char **map_copy, t_long *game);
int		validate_map(t_long *game);
int		parse_map_lines(char *file, t_long *game);
int		check_map_border(t_long *game);
int		check_map_rectangular(t_long *game);
int		key_press(int keycode, t_long *game);
int		close_game(t_long *game);
int		update(t_long *game);
int		animate_map(t_long *game);
int		update(t_long *game);
int		count_map_lines(int fd);
int		animate_map(t_long *game);
int		handle_keypress(int keycode, t_long *game);
size_t	ft_strcspn(const char *str, const char *reject);

#endif