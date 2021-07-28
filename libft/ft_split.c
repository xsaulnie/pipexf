/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:01:44 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/06/16 11:57:16 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count(char const *s, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0' && res == 0)
			return (0);
		while (s[i] != c && s[i] != '\0')
			i++;
		res++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (res);
}

static int	cleanalloc(char **tab, int indelem, int nbcar, int nbelem)
{
	int	i;

	i = 0;
	tab[indelem] = (char *)malloc((nbcar + 1) * sizeof(char));
	if (tab[indelem] == NULL)
	{
		while (i < nbelem)
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
		return (1);
	}
	return (0);
}

static int	alloc(char **tab, char const *s, char c, int nbelem)
{
	int	indelem;
	int	nbcar;
	int	i;

	i = 0;
	indelem = 0;
	while (s[i] != '\0')
	{
		nbcar = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			nbcar++;
			i++;
		}
		if (cleanalloc(tab, indelem, nbcar, nbelem))
			return (1);
		indelem++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (0);
}

static void	affec(char **tab, char const *s, char c)
{
	int	indelem;
	int	nbcar;
	int	i;

	i = 0;
	indelem = 0;
	while (s[i] != '\0')
	{
		nbcar = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			tab[indelem][nbcar] = s[i];
			nbcar++;
			i++;
		}
		tab[indelem][nbcar] = '\0';
		indelem++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	tab[indelem] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		nbelem;

	if (s == NULL)
		return (NULL);
	nbelem = count(s, c);
	res = (char **)malloc((nbelem + 1) * (sizeof(char *)));
	if (res == NULL)
		return (NULL);
	if (nbelem == 0)
		res[0] = NULL;
	else
	{
		if (alloc(res, s, c, nbelem))
			return (NULL);
		affec(res, s, c);
	}
	return (res);
}
