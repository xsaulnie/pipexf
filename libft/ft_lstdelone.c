#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void(*del)(void*))
{
	if (lst == NULL)
		return ;
	if (lst->content)
		(*del)(lst->content);
	free(lst);
}
