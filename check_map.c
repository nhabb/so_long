/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:13:28 by nhaber            #+#    #+#             */
/*   Updated: 2025/03/01 15:13:28 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_rectangular(t_long *game)
{
	int	i;
	int	map_width;
	int	line_len;

	i = 1;
	if (game->map == NULL || game->map_height == 0)
		return (0);
	map_width = ft_strlen(game->map[0]);
	while (i < game->map_height)
	{
		line_len = ft_strlen(game->map[i]);
		if (line_len != map_width)
		{
			free_map(game);
			return (0);
		}
		i++;
	}
	game->map_width = map_width;
	return (1);
}

int	check_map_border(t_long *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
		{
			free_map(game);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
		{
			free_map(game);
			return (0);
		}
		i++;
	}
	return (1);
}

void	initialize_assets(t_long *game)
{
	int	x;
	int	y;

	game->collectibles = 0;
	game->collected = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				game->collectibles++;
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
}

void	check_space(int fd)
{
	int		i;
	char	*line;

	i = 1;
	while ((line))
	{
		line = get_next_line(fd);
		if (line[i] == ' ' || line[i] == '\t'
			|| line[i] == '\n' || line[i] == '\r')
			i++;
		if (line[i] == '\0')
		{
			printf("line is ivalid\n");
			exit (1);
		}
		i++;
	}
}

int	validate_map(t_long *game)
{
	if (!check_map_rectangular(game))
	{
		ft_printf("Error: Map is not rectangular\n");
		return (0);
	}
	if (!check_map_border(game))
	{
		ft_printf("Error: Map is not surrounded by walls\n");
		return (0);
	}
	initialize_assets(game);
	if (!check_path_to_exit(game))
	{
		ft_printf("Error: No valid path from player to exit\n");
		return (0);
	}
	return (1);
}
