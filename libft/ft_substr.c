/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 09:39:23 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/07/28 13:37:37 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;
	size_t	tai;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_emptystr());
	i = start;
	while ((i < (len + start)) && (s[i] != '\0'))
		i++;
	tai = (i - start + 1);
	res = malloc(sizeof(char) * (tai));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < tai - 1)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}
