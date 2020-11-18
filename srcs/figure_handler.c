#include "filler.h"

void			set_top_f(t_filler *filler)
{
	int		h;
	int		w;

	h = 0;
	while (h < filler->piece.h)
	{
		w = 0;
		while (w < filler->piece.w)
		{
			if (filler->piece.piece[h][w] == '*')
			{
				filler->piece.top = point_init(w, h);
				return ;
			}
			w++;
		}
		h++;
	}
}

void			set_left_f(t_filler *filler)
{
	int		h;
	int		w;
	t_point	left;

	h = 0;
	left = point_init(filler->piece.w - 1, filler->piece.h - 1);
	while (h < filler->piece.h)
	{
		w = 0;
		while (w < filler->piece.w)
		{
			if (filler->piece.piece[h][w] == '*' && w < left.x)
			{
				left = point_init(w, h);
				break ;
			}
			w++;
		}
		h++;
	}
	filler->piece.left = left;
}

void			set_right_f(t_filler *filler)
{
	int		h;
	int		w;
	t_point	right;

	h = 0;
	right = point_init(0, 0);
	while (h < filler->piece.h)
	{
		w = filler->piece.w - 1;
		while (w >= 0)
		{
			if (filler->piece.piece[h][w] == '*' && w > right.x)
			{
				right = point_init(w, h);
				break ;
			}
			w--;
		}
		h++;
	}
	filler->piece.right = right;
}

void			set_bottom_f(t_filler *filler)
{
	int		h;
	int		w;

	h = filler->piece.h - 1;
	while (h >= 0)
	{
		w = 0;
		while (w < filler->piece.w)
		{
			if (filler->piece.piece[h][w] == '*')
			{
				filler->piece.bottom = point_init(w, h);
				return ;
			}
			w++;
		}
		h--;
	}
}

void			cut_figure(t_filler *filler)
{
	set_top_f(filler);
	set_left_f(filler);
	set_right_f(filler);
	set_bottom_f(filler);
	filler->piece.left_top = point_init(filler->piece.left.x,\
	filler->piece.top.y);
	filler->piece.right_bottom = point_init(filler->piece.right.x,\
	filler->piece.bottom.y);
	filler->piece.real_h = filler->piece.bottom.y - filler->piece.top.y + 1;
	filler->piece.real_w = filler->piece.right.x - filler->piece.left.x + 1;
}

