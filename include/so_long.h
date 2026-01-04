/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbatista <gbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:19:12 by gbatista          #+#    #+#             */
/*   Updated: 2026/01/02 13:32:00 by gbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/include/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 64

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		width;
	int		height;
	void	*player_img;
	void	*collect_img;
	void	*exit_img;
	void	*wall_img;
	void	*floor_img;
	int		player_x;
	int		player_y;
	int		steps;
	int		collectibles;
}			t_game;

char		**read_map_to_array(char *filename);
char		*trim_newline(char *line);
int			count_lines(char *filename);
int			count_lines_map(char **map);
void		read_map(char *path);

int			is_rectangular(char **map);
int			check_walls(char **map);
int			is_line_wall(char *line);
int			check_valid_chars(char **map);
int			check_elements(char **map);
void		count_element(char c, int *player, int *exit, int *collect);

void		load_images(t_game *game);
void		draw_map(t_game *game);

void		init_positions(t_game *game);
void		init_game(t_game *game, char *file);

int			handle_key(int keycode, void *param);
void		move_player(t_game *game, int new_x, int new_y);
int			is_valid_extension(char *file);
int			close_game(t_game *game);
void		render_map(t_game *game);
char		**copy_map(char **map);
void		flood_fill(char **map, int x, int y);
int			check_path(char **map, int start_x, int start_y);
void		free_map(char **map);

#endif
