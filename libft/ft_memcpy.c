/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:48:56 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/05/26 09:52:21 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
