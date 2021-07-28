/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 09:53:39 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/07/28 11:51:13 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	*afftrim(const char *s, size_t trid, size_t trif)
{
	size_t	i;
	size_t	len;
	char	*res;

	len = ft_strlen((char *)s);
	res = (char *)malloc(sizeof(char) * (len - (trid + trif) + 1));
	if (res == NULL)
		return (NULL);
	i = trid;
	while (i < len - trif)
	{
		res[i - trid] = s[i];
		i++;
	}
	res[i - trid] = '\0';
	return (res);
}	

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	int		i;
	size_t	trideb;
	size_t	trifin;

	if (set == NULL || s1 == NULL)
		return (NULL);
	i = 0;
	trideb = 0;
	trifin = 0;
	len = ft_strlen((char *)s1);
	if (len == 0)
		return (ft_emptystr());
	while (ft_strchr(set, s1[i]) != NULL && s1[i++])
		trideb++;
	i = len - 1;
	while (ft_strchr(set, s1[i]) != NULL && s1[i--] && i >= 0)
		trifin++;
	if (trideb >= len || trifin >= len)
		return (ft_emptystr());
	return (afftrim(s1, trideb, trifin));
}
