/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:51:44 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/06/03 09:46:11 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = n;
	if ((dest == NULL && src == NULL))
		return (NULL);
	if ((src < dest))
	{
		while (i--)
		{
			((char *)dest)[i] = ((char *)src)[i];
		}
	}
	else
		while (i--)
			((char *)dest)[n - i - 1] = ((char *)src)[n - i - 1];
	return (dest);
}
