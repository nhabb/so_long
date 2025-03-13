/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:42:11 by nhaber            #+#    #+#             */
/*   Updated: 2025/03/06 14:03:48 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_game(t_long *game)
{
	load_textures(game);
	mlx_loop_hook(game->mlx, &update, game);
	mlx_hook(game->window, 2, 1L << 0, &key_press, game);
	mlx_key_hook(game->window, handle_keypress, game);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, &close_game,
		game);
	mlx_loop(game->mlx);
}

void	window_cleaner(t_long *game)
{
	int	i;

	i = 0;
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_empty)
		mlx_destroy_image(game->mlx, game->img_empty);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->pl_im);
	free(game->mlx);
}

void	cleanup_game(t_long *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->map_height)
		{
			if (game->map[i])
				free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	if (game->pl_im->ptr)
		mlx_destroy_image(game->mlx, game->pl_im->ptr);
	window_cleaner(game);
}
