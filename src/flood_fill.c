/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbatista <gbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 13:17:09 by gbatista          #+#    #+#             */
/*   Updated: 2026/01/02 13:31:24 by gbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map)
{
	char	**copy;
	int		i;
	int		lines;

	lines = 0;
	while (map[lines])
		lines++;
	copy = malloc(sizeof(char *) * (lines + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(char **map, int x, int y)
{
	if (y < 0 || x < 0)
		return ;
	if (!map[y] || !map[y][x])
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	check_path(char **map, int start_x, int start_y)
{
	char	**copy;
	int		y;
	int		x;

	copy = copy_map(map);
	if (!copy)
		return (0);
	flood_fill(copy, start_x, start_y);
	y = 0;
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == 'C' || copy[y][x] == 'E')
			{
				free_map(copy);
				return (0);
			}
			x++;
		}
		y++;
	}
	free_map(copy);
	return (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
