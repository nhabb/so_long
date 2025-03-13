/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:05:47 by nhaber            #+#    #+#             */
/*   Updated: 2025/03/05 23:16:57 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_long *game)
{
	game->keys[keycode] = 1;
	return (0);
}

void	move_counter(t_long *game)
{
	char	*move_count_str;
	char	*text;

	move_count_str = ft_itoa(game->moves);
	text = ft_strjoin("Total Moves: ", move_count_str);
	mlx_string_put(game->mlx, game->window, 10, 10, 0xFFFFFF, text);
	free(move_count_str);
	free(text);
}

void	move_player(t_long *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
		ft_printf("Total collected items: %d/%d\n", game->collected,
			game->collectibles);
	}
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collected != game->collectibles)
		{
			ft_printf("You must collect all items before exiting!\n");
			return ;
		}
		else
			close_game(game);
	}
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	game->moves++;
}
