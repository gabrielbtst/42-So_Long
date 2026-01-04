/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbatista <gbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:34:55 by gbatista          #+#    #+#             */
/*   Updated: 2025/12/18 01:28:46 by gbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int		count;
	long	nb;

	count = 0;
	nb = n;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		count++;
		nb = nb * -1;
	}
	while (nb != 0)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*str;
	int		count;

	nb = n;
	if (nb == 0)
		return (ft_strdup("0"));
	count = count_digits(n);
	str = malloc((count + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	str[count] = '\0';
	while (nb != 0)
	{
		count--;
		str[count] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
