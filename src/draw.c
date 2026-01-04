/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbatista <gbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:19:09 by gbatista          #+#    #+#             */
/*   Updated: 2026/01/01 23:18:49 by gbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->player_img = mlx_xpm_file_to_image(game->mlx_ptr, "xpm/cat.xpm", &w,
			&h);
	game->collect_img = mlx_xpm_file_to_image(game->mlx_ptr, "xpm/fish.xpm", &w,
			&h);
	game->exit_img = mlx_xpm_file_to_image(game->mlx_ptr, "xpm/door.xpm", &w,
			&h);
	game->wall_img = mlx_xpm_file_to_image(game->mlx_ptr, "xpm/tree.xpm", &w,
			&h);
	game->floor_img = mlx_xpm_file_to_image(game->mlx_ptr, "xpm/grass.xpm", &w,
			&h);
	if (!game->player_img || !game->collect_img || !game->exit_img
		|| !game->wall_img || !game->floor_img)
	{
		perror("Failed to load images");
		exit(1);
	}
}

void	draw_line(t_game *game, int y)
{
	int	x;

	x = 0;
	while (game->map[y][x])
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor_img, x
			* TILE_SIZE, y * TILE_SIZE);
		if (game->map[y][x] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
		else if (game->map[y][x] == 'C')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->collect_img, x * TILE_SIZE, y * TILE_SIZE);
		else if (game->map[y][x] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->exit_img, x * TILE_SIZE, y * TILE_SIZE);
		if (y == game->player_y && x == game->player_x)
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->player_img, x * TILE_SIZE, y * TILE_SIZE);
		x++;
	}
}

char	*trim_newline(char *line)
{
	int	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

void	render_map(t_game *game)
{
	int	y;

	y = 0;
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	while (game->map[y])
	{
		draw_line(game, y);
		y++;
	}
}
