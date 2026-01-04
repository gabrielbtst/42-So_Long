/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbatista <gbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:52:41 by gbatista          #+#    #+#             */
/*   Updated: 2025/09/03 11:55:05 by gbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	size_t	len;
	char	*aux;

	len = ft_strlen(s1);
	aux = malloc((len + 1) * sizeof(char));
	if (!aux)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		aux[i] = s1[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*aux;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	aux = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!aux)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		aux[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		aux[i++] = s2[j++];
	aux[i] = '\0';
	free(s1);
	return (aux);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*aux;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	str_len = ft_strlen(s + start);
	if (str_len > len)
		str_len = str_len - len;
	aux = malloc((str_len + 1) * sizeof(char));
	if (!aux)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < str_len)
	{
		aux[i] = s[start];
		i++;
		start++;
	}
	aux[i] = '\0';
	return (aux);
}
