#include "filler.h"

int				emergency_clean(int last, char ***arr)
{
	char	**tmp;

	tmp = *arr;
	while (--last >= 0)
		free(tmp[last]);
	free(tmp);
	tmp = NULL;
	return (0);
}

int				map_init(t_filler *filler)
{
	int		i;

	i = 0;
	if (filler->map.w && filler->map.h && !filler->map.map)
	{
		if (!(filler->map.map = (char **)malloc(sizeof(char *) *\
		(filler->map.h + 1))))
			return (0);
		filler->map.map[filler->map.h] = NULL;
		while (i < filler->map.h)
		{
			if (!(filler->map.map[i] = (char *)malloc(sizeof(char) *\
			(filler->map.w + 1))))
				return (emergency_clean(i, &filler->map.map));
			i++;
		}
	}
	return (1);
}


int				parse_map(t_filler *filler, char *line)
{
	char	*tmp;
	int		i;

	tmp = 0;
	i = 0;
	if (line && ft_strlen(line) > 8 && !ft_strncmp(line, "    0123", 8))
	{
		while (i < filler->map.h)
		{
			if (get_next_line(0, &tmp) > 0)
			{
				filler->map.map[i] = ft_strcpy(filler->map.map[i], tmp + 4);
				ft_strdel(&tmp);
				i++;
			}
			else
			{
				ft_strdel(&tmp);
				return (0);
			}
		}
	}
	return (1);
}
