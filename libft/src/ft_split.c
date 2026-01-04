/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbatista <gbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:27:22 by gbatista          #+#    #+#             */
/*   Updated: 2025/08/05 20:21:11 by gbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
		}
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

size_t	ft_get_word_length(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] == c)
	{
		i++;
	}
	while (s[i] != '\0' && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

char	*ft_get_next_word(const char *s, char c, int *i)
{
	int		count;
	char	*aux;
	int		j;
	int		start;

	count = 0;
	while (s[*i] == c && s[*i] != '\0')
	{
		(*i)++;
	}
	start = *i;
	count = ft_get_word_length(&s[start], c);
	*i += count;
	aux = (char *)malloc((count + 1) * sizeof(char));
	j = 0;
	while (j < count)
	{
		aux[j] = s[start + j];
		j++;
	}
	aux[j] = '\0';
	return (aux);
}

void	ft_free_split(char **arr, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**aux;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	count = ft_count_words(s, c);
	aux = (char **)malloc((count + 1) * sizeof(char *));
	if (!aux)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count)
	{
		aux[j] = ft_get_next_word(s, c, &i);
		if (aux[j] == NULL)
		{
			ft_free_split(aux, j);
			return (NULL);
		}
		j++;
	}
	aux[j] = NULL;
	return (aux);
}
