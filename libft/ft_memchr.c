/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:57:54 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/06/03 09:46:30 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		if (((unsigned char *)b)[i] == (unsigned char)c)
			return ((void *)(b + i));
		i++;
	}
	return (NULL);
}
