/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbatista <gbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 04:36:06 by gbatista          #+#    #+#             */
/*   Updated: 2026/01/02 13:53:24 by gbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_positions(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			else if (game->map[y][x] == 'C')
				game->collectibles++;
		}
	}
}

void	init_game(t_game *game, char *file)
{
	game->mlx_ptr = mlx_init();
	game->map = read_map_to_array(file);
	if (!game->map || !game->mlx_ptr)
		exit(1);
	game->height = count_lines_map(game->map);
	game->width = ft_strlen(game->map[0]);
	game->steps = 0;
	init_positions(game);
	if (!is_rectangular(game->map) || !check_walls(game->map)
		|| !check_valid_chars(game->map) || !check_elements(game->map)
		|| !check_path(game->map, game->player_x, game->player_y))
	{
		ft_putendl_fd("Error\nInvalid map", 2);
		exit(1);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
	mlx_hook(game->win_ptr, 2, 1L << 0, handle_key, game);
	mlx_hook(game->win_ptr, 17, 0, close_game, game);
	load_images(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putendl_fd("Error\nUsage: ./so_long map.ber", 2);
		return (1);
	}
	if (!is_valid_extension(argv[1]))
	{
		ft_putendl_fd("Error\nInvalid map extension", 2);
		return (1);
	}
	ft_bzero(&game, sizeof(t_game));
	init_game(&game, argv[1]);
	render_map(&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}

int	is_valid_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5)
		return (0);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
	return (0);
}
