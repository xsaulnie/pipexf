/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:24:14 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/05/26 14:28:52 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cur;

	cur = lst;
	if (cur == NULL)
		return (NULL);
	while (cur->next)
		cur = cur->next;
	return (cur);
}
