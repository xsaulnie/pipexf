/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:38:58 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/06/03 09:48:13 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	res;

	i = 0;
	res = -1;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			res = i;
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	if (res != -1)
		return ((char *)(s + res));
	return (NULL);
}
