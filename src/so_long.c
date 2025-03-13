/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:44:21 by nhaber            #+#    #+#             */
/*   Updated: 2024/10/08 10:44:21 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_resources(char *line, t_long *game)
{
	free(line);
	free_map(game);
}

int	main(int argc, char **argv)
{
	t_long	game;

	game.moves = 0;
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (1);
	}
	if (!parse_map_lines(argv[1], &game) || !validate_map(&game))
	{
		return (1);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.window = mlx_new_window(game.mlx, game.map_width * TILE_SIZE,
			game.map_height * TILE_SIZE, "so_long");
	if (!game.window)
		return (1);
	load_game(&game);
	return (0);
}
