/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:27:23 by nhaber            #+#    #+#             */
/*   Updated: 2025/03/07 15:31:30 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, t_long *game)
{
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height
		|| map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
		map[y][x] = 'V';
	if (game->map[y][x] == 'C')
		game->coint_count++;
	if (game->map[y][x] == 'P')
		game->player_count++;
	if (game->map[y][x] == 'E')
		game->exit_count++;
	map[y][x] = 'V';
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x, y - 1, game);
	flood_fill(map, x, y + 1, game);
}

void	free_map_copy(char **map_copy, t_long *game)
{
	int	i;

	i = -1;
	while (++i < game->map_height)
		free(map_copy[i]);
	free(map_copy);
}

char	**copy_map(t_long *game)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (game->map_height + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < game->map_height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
		{
			free_map_copy(map_copy, game);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	check_map_copy(char **map_copy, t_long *game)
{
	int	y;
	int	x;
	int	result;

	result = 1;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C' || game->map[y][x] == 'E')
			{
				if (map_copy[y][x] != 'V')
					return (0);
			}
			if (game->map[y][x] != 'E' && game->map[y][x] != 'C' &&
				game->map[y][x] != 'P'
				&& game->map[y][x] != '1' && game->map[y][x] != '0')
				return (0);
			x++;
		}
		y++;
	}
	return (result);
}

int	check_path_to_exit(t_long *game)
{
	char	**map_copy;
	int		result;

	game->coint_count = 0;
	game->exit_count = 0;
	game->player_count = 0;
	if (game->player_x < 0 || game->player_x >= game->map_width
		|| game->player_y < 0 || game->player_y >= game->map_height)
		return (0);
	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game->player_x, game->player_y, game);
	result = check_map_copy(map_copy, game);
	free_map_copy(map_copy, game);
	if (result == 0 || game->coint_count == 0
		|| game->exit_count == 0 || game->player_count != 1)
	{
		free_map(game);
		return (0);
	}
	return (1);
}
