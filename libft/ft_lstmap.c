/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:14:12 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/06/03 11:30:26 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cleanalloc(t_list *lst0, t_list *lst, void *val, void(*del)(void *))
{
	lst->next = ft_lstnew(val);
	if (lst->next == NULL)
	{
		ft_lstclear(&lst0, del);
		return (1);
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*cur;
	t_list	*res0;
	void	*val;

	cur = lst;
	if (lst == NULL)
		return (NULL);
	val = (*f)(cur->content);
	res = ft_lstnew(val);
	res0 = res;
	cur = lst->next;
	while (cur)
	{
		val = (*f)(cur->content);
		if (cleanalloc(res0, res, val, del))
			return (NULL);
		cur = cur->next;
		res = res->next;
	}
	return (res0);
}
