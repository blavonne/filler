#include "filler.h"

void		clean_split(char ***arr)
{
	char	**ptr;
	int		i;

	i = 0;
	ptr = *arr;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
}
