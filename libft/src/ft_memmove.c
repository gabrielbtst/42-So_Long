/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbatista <gbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:32:24 by gbatista          #+#    #+#             */
/*   Updated: 2025/07/24 15:52:18 by gbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ds;
	const unsigned char	*sc;

	if (dest == src || n == 0)
		return (dest);
	ds = (unsigned char *)dest;
	sc = (const unsigned char *)src;
	if (ds < sc)
	{
		i = 0;
		while (i < n)
		{
			ds[i] = sc[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
			ds[i] = sc[i];
	}
	return (dest);
}
