/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:26:44 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/05/26 11:55:31 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *newc)
{
	if (*alst == NULL)
		*alst = newc;
	else
		(ft_lstlast(*alst))->next = newc;
}
