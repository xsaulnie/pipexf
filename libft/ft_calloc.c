/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:37:25 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/07/28 12:15:03 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*res;
	size_t	total_size;

	i = 0;
	total_size = size * nmemb;
	res = (void *)malloc(total_size);
	if (res == NULL)
		return (NULL);
	while (i < total_size)
	{
		((unsigned char *)(res))[i] = 0;
		i++;
	}
	return (res);
}
