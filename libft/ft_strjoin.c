/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 09:40:35 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/06/03 09:59:11 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	lens1;
	size_t	lens2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	i = 0;
	res = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (res == NULL)
		return (NULL);
	while (i < lens1 + lens2 + 1)
	{
		if (i < lens1)
			res[i] = s1[i];
		else
			res[i] = s2[i - lens1];
		i++;
	}
	res[lens1 + lens2] = '\0';
	return (res);
}
