/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbatista <gbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:53:07 by gbatista          #+#    #+#             */
/*   Updated: 2025/09/15 13:00:48 by gbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_until_newline(int fd, char **stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	if (!stash)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!*stash || !ft_strchr(*stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(*stash), *stash = NULL, NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		*stash = ft_strjoin_free(*stash, buffer);
		if (!*stash)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (*stash);
}

static char	*extract_line(char **stash)
{
	char	*line;
	char	*nl;
	size_t	len;
	size_t	i;

	if (!stash || !*stash)
		return (NULL);
	nl = ft_strchr(*stash, '\n');
	if (nl)
		len = (size_t)(nl - *stash + 1);
	else
		len = ft_strlen(*stash);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = (*stash)[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_stash(char *stash)
{
	char	*nl;
	char	*temp;

	if (!stash)
		return (NULL);
	nl = ft_strchr(stash, '\n');
	if (!nl || !*(nl + 1))
		return (free(stash), NULL);
	temp = ft_strdup(nl + 1);
	free(stash);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_until_newline(fd, &stash))
		return (NULL);
	line = extract_line(&stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = update_stash(stash);
	return (line);
}
