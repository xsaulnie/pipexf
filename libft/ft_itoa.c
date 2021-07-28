/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 10:06:36 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/06/03 10:15:42 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_strinv(char *tab, size_t len)
{
	size_t	i;
	char	temp;

	i = 0;
	while (i < len / 2)
	{
		temp = tab[i];
		tab[i] = tab[len - 1 - i];
		tab[len - 1 - i] = temp;
		i++;
	}
	tab[len] = '\0';
	return (tab);
}

static char	*ft_intoa(int n)
{
	char			tab[12];
	int				i;
	char			*res;
	unsigned int	un;

	un = -n;
	i = 0;
	while (un != 0)
	{
		tab[i++] = (un % 10) + '0';
		un /= 10;
	}
	res = malloc(sizeof(char) * (i + 2));
	if (res == NULL)
		return (NULL);
	res[i + 1] = '\0';
	res[i] = '-';
	while (i-- >= 0)
		res[i] = tab[i];
	ft_strinv(res, ft_strlen(res));
	return (res);
}

static char	*ft_iptoa(int n)
{
	char	tab[12];
	int		i;
	char	*res;

	i = 0;
	while (n != 0)
	{
		tab[i++] = (n % 10) + '0';
		n /= 10;
	}
	res = malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	res[i] = '\0';
	while (i-- >= 0)
		res[i] = tab[i];
	ft_strinv(res, ft_strlen(res));
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;

	if (n < 0)
		return (ft_intoa(n));
	if (n > 0)
		return (ft_iptoa(n));
	res = (char *)malloc(sizeof(char) * 2);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}
