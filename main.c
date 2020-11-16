#include <stdio.h>
#include "filler.h"
#include <fcntl.h>

int main()
{
	t_filler filler;

	ft_bzero(&filler, sizeof(filler));
	if (parse_player(&filler))
		if (!filler_loop(&filler))
			return (0);
	return (0);
}
