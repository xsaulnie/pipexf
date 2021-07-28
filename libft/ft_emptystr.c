#include <stdlib.h>

char	*ft_emptystr(void)
{
	char	*p;

	p = (char *)malloc(1 * sizeof(char));
	if (p == NULL)
		return (NULL);
	p[0] = '\0';
	return (p);
}
