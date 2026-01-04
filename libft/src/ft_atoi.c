/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbatista <gbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:29:30 by gbatista          #+#    #+#             */
/*   Updated: 2025/07/31 20:08:05 by gbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sinal;
	int	resultado;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
	{
		i++;
	}
	sinal = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		{
			sinal = sinal * -1;
		}
		i++;
	}
	resultado = 0;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		resultado = resultado * 10 + (nptr[i] - '0');
		i++;
	}
	return (resultado * sinal);
}
