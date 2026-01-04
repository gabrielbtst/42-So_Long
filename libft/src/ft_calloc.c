/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbatista <gbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:43:03 by gbatista          #+#    #+#             */
/*   Updated: 2025/07/24 15:51:25 by gbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size)
{
	size_t	length;
	void	*ptr;

	if (size != 0 && count > (size_t)(-1) / size)
	{
		return (NULL);
	}
	length = count * size;
	ptr = malloc (length);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_bzero(ptr, length);
	return (ptr);
}
