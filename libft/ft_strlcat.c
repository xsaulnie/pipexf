/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:52:05 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/06/03 10:39:37 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	dlen;
	size_t	dsrc;
	size_t	i;

	dlen = ft_strlen((const char *)dest);
	dsrc = ft_strlen((const char *)src);
	if (!size || size < dlen + 1)
		return (dsrc + size);
	i = 0;
	while (src[i] && i < size - dlen - 1)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + dsrc);
}
