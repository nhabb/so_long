/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:23:32 by nhaber            #+#    #+#             */
/*   Updated: 2024/10/02 19:23:32 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	count_map_lines(int fd)
{
	char	*line;
	int		lines;

	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 1 || (ft_strlen(line) == 1 && line[0] != '\n'))
			lines++;
		free(line);
		line = get_next_line(fd);
	}
	lseek(fd, 0, SEEK_SET);
	return (lines);
}

int	parse_map_columns(int fd, t_long *game)
{
	char	*line;
	int		i;

	i = 0;
	while (i < game->map_height)
	{
		line = get_next_line(fd);
		if (!line)
			return (free_map(game), 0);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (line[0] == '\0')
		{
			ft_printf("Error\nEmpty line in map\n");
			return (free(line), 0);
		}
		game->map[i] = malloc(ft_strlen(line) + 1);
		if (!game->map[i])
			return (free_resources(line, game), 0);
		ft_strcpy(game->map[i], line);
		free(line);
		i++;
	}
	game->map[i] = NULL;
	return (1);
}

int	parse_map_lines(char *file, t_long *game)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	game->map_height = count_map_lines(fd);
	if (game->map_height == 0)
	{
		ft_printf("Error\nEmpty Map\n");
		return (close(fd), 0);
	}
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
	{
		close(fd);
		return (0);
	}
	null_map(game);
	if (!parse_map_columns(fd, game))
	{
		close_file(fd, game);
		return (0);
	}
	close(fd);
	return (1);
}

void	null_map(t_long *game)
{
	int	i;

	i = 0;
	while (i <= game->map_height)
	{
		game->map[i] = NULL;
		i++;
	}
}

void	close_file(int fd, t_long *game)
{
	free_map(game);
	close(fd);
}
