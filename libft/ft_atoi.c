/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:18:49 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/07/28 11:47:22 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f' || c == ' ')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	res;
	int				i;
	short			sig;

	i = 0;
	res = 0;
	sig = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		sig = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
		res = 10 * res + (nptr[i++] - '0');
	return (res * sig);
}
