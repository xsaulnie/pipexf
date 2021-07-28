/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:05:25 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/06/03 09:50:59 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	littlen;
	size_t	biglen;
	size_t	i;

	i = 0;
	if (needle[0] == 0)
		return ((char *)(haystack));
	if (len == 0)
		return (0);
	littlen = ft_strlen((char *)needle);
	biglen = ft_strlen((char *)haystack);
	while (i <= (len - littlen) && (haystack[i] != '\0'))
	{
		if (ft_strncmp(needle, haystack + i, littlen) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
