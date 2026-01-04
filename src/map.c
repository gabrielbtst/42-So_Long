/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbatista <gbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:19:01 by gbatista          #+#    #+#             */
/*   Updated: 2025/12/27 20:26:31 by gbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *path)
{
	int		fd;
	ssize_t	bytes_read;
	char	buffer[1024];

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("error");
		return ;
	}
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		write(1, buffer, bytes_read);
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	if (bytes_read == -1)
	{
		perror("error");
		return ;
	}
	close(fd);
}

char	**read_map_to_array(char *filename)
{
	int		fd;
	char	**map;
	int		i;
	int		lines_count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	lines_count = count_lines(filename);
	map = malloc(sizeof(char *) * (lines_count + 1));
	if (lines_count == 0)
		return (NULL);
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i++] = trim_newline(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	count_lines(char *filename)
{
	int		fd;
	char	*lines;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("error");
		return (0);
	}
	i = 0;
	lines = get_next_line(fd);
	if (lines != NULL)
	{
		while (lines != NULL)
		{
			i++;
			free(lines);
			lines = get_next_line(fd);
		}
	}
	close(fd);
	return (i);
}

void	count_element(char c, int *player, int *exit, int *collect)
{
	if (c == 'P')
		(*player)++;
	else if (c == 'E')
		(*exit)++;
	else if (c == 'C')
		(*collect)++;
}

int	count_lines_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
