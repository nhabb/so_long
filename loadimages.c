/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadimages.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:37:10 by nhaber            #+#    #+#             */
/*   Updated: 2025/03/06 15:03:37 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player(t_long *game, int width, int height)
{
	char	*path;

	path = "./textures/player.xpm";
	game->pl_im = malloc(sizeof(t_image));
	if (!game->pl_im)
	{
		printf("Error: Failed to allocate memory for player image.\n");
		free(game->pl_im);
		exit(1);
	}
	game->pl_im->ptr = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!game->pl_im->ptr)
	{
		printf("Error: Failed to load %s\n", path);
		free(game->pl_im);
		exit(1);
	}
	game->pl_im->width = width;
	game->pl_im->height = height;
}

void	load_textures(t_long *game)
{
	int	width;
	int	height;

	width = 48;
	height = 48;
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"./textures/wall.xpm", &width, &height);
	game->img_empty = mlx_xpm_file_to_image(game->mlx,
			"./textures/floor.xpm", &width, &height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"./textures/collectible.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"./textures/exit.xpm", &width, &height);
	load_player(game, width, height);
}

void	render_tile(t_long *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->img_wall, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->img_empty, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->pl_im->ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->img_exit, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	render_player(t_long *game)
{
	static int	frame = 0;
	static int	last_time = 0;
	int			current_time;

	if (!game || !game->mlx || !game->window || !game->pl_im)
		return ;
	current_time = clock();
	if ((current_time - last_time) > CLOCKS_PER_SEC / 10)
	{
		frame = (frame + 1);
		last_time = current_time;
	}
	if (!game->pl_im->ptr)
		return ;
	mlx_put_image_to_window(game->mlx, game->window,
		game->pl_im->ptr, game->player_x * TILE_SIZE,
		game->player_y * TILE_SIZE);
}

void	render_map(t_long *game)
{
	int	x;
	int	y;

	mlx_clear_window(game->mlx, game->window);
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			render_tile(game, x, y);
			if (game->map[y][x] == 'P')
				render_player(game);
			x++;
		}
		y++;
	}
}
