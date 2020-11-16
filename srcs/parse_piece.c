#include "filler.h"

int			piece_init(t_filler *filler)
{
	int		i;

	i = 0;
	if (filler->piece.w && filler->piece.h && !filler->piece.piece)
	{
		if (!(filler->piece.piece = (char **)malloc(sizeof(char *) *\
		(filler->piece.h + 1))))
			return (0);
		filler->piece.piece[filler->piece.h] = NULL;
		while (i < filler->piece.h)
		{
			if (!(filler->piece.piece[i] = (char *)malloc(sizeof(char) *\
			(filler->piece.w + 1))))
				return (emergency_clean(i, &filler->piece.piece));
			i++;
		}
	}
	return (1);
}

int			parse_piece(t_filler *filler, char *line)
{
	char	*tmp;
	int		i;

	tmp = 0;
	i = 0;
	if (line && ft_strstr(line, "Piece") && filler->piece.w && filler->piece.h\
	&& filler->piece.piece)
	{
		while (i < filler->piece.h)
		{
			if (get_next_line(0, &tmp) > 0)
			{
				filler->piece.piece[i] = ft_strcpy(filler->piece.piece[i], tmp);
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