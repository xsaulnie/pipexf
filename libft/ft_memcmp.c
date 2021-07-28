/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:08:34 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/06/03 09:46:50 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned int	i;

	i = 0;
	while (((unsigned char *)b1)[i] == ((unsigned char *)b2)[i] && i < len - 1)
		i++;
	if (i == len)
		return (0);
	return ((int)(((unsigned char *)b1)[i] - ((unsigned char *)b2)[i]));
}
