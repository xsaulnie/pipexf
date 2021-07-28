/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:00:27 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/05/26 12:06:22 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*cur;
	t_list	*sui;

	cur = lst;
	while (cur)
	{
		sui = cur->next;
		(*f)(cur->content);
		cur = sui;
	}
}
