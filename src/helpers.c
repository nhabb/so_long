/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:48:12 by nhaber            #+#    #+#             */
/*   Updated: 2025/03/07 15:16:02 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_long *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}

int	update(t_long *game)
{
	render_map(game);
	move_counter(game);
	return (0);
}

int	animate_map(t_long *game)
{
	static int	last_time = 0;
	int			current_time;

	current_time = clock();
	if ((current_time - last_time) > CLOCKS_PER_SEC / 10)
		render_map(game);
	return (0);
}

void	free_map(t_long *game)
{
	int	i;

	i = 0;
	if (!game || !game->map)
		return ;
	while (i < game->map_height)
	{
		if (game->map[i])
			free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
