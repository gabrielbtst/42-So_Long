/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbatista <gbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 04:17:15 by gbatista          #+#    #+#             */
/*   Updated: 2026/01/01 23:15:06 by gbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, void *param)
{
	t_game	*game;
	int		new_x;
	int		new_y;

	game = (t_game *)param;
	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == 119 || keycode == 65362)
		new_y -= 1;
	else if (keycode == 115 || keycode == 65364)
		new_y += 1;
	else if (keycode == 97 || keycode == 65361)
		new_x -= 1;
	else if (keycode == 100 || keycode == 65363)
		new_x += 1;
	else if (keycode == 65307)
		close_game(game);
	else
		return (0);
	move_player(game, new_x, new_y);
	render_map(game);
	return (1);
}

void	move_player(t_game *game, int new_x, int new_y)
{
	char	dest;

	dest = game->map[new_y][new_x];
	if (dest == '1')
		return ;
	else if (dest == 'C')
	{
		game->collectibles--;
		game->map[new_y][new_x] = '0';
	}
	else if (dest == 'E')
	{
		if (game->collectibles > 0)
			return ;
		else
			exit(0);
	}
	game->player_x = new_x;
	game->player_y = new_y;
	game->steps++;
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(game->steps, 1);
	ft_putstr_fd("\n", 1);
}
