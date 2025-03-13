/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:47:01 by nhaber            #+#    #+#             */
/*   Updated: 2025/03/06 13:43:22 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_long *game)
{
	if (keycode == 65307)
		close_game(game);
	if (keycode == 119 || keycode == 'w'
		|| keycode == 65362)
		forward(game);
	if (keycode == 97 || keycode == 'a'
		|| keycode == 65361)
		left(game);
	if (keycode == 115 || keycode == 's'
		|| keycode == 65364)
		back(game);
	if (keycode == 100 || keycode == 'd'
		|| keycode == 65363)
		right(game);
	return (0);
}

void	left(t_long *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x - 1;
	new_y = game->player_y;
	move_player(game, new_x, new_y);
}

void	right(t_long *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + 1;
	new_y = game->player_y;
	move_player(game, new_x, new_y);
}

void	forward(t_long *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y - 1;
	move_player(game, new_x, new_y);
}

void	back(t_long *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y + 1;
	move_player(game, new_x, new_y);
}
