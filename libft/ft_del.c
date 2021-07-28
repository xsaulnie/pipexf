#include "libft.h"

void	ft_del(char **p)
{
	free(*p);
	*p = NULL;
}
