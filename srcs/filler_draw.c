#include "filler.h"

//static int	safe_mlx_create2(t_mlx *mlx, int w, int h)
//{
//	if (!mlx->mlx)
//	{
//		if (!(mlx->mlx = create_mlx()))
//			return (0);
//		if (!(mlx->win = create_win(mlx, w, h, "Filler")))
//		{
//			free(mlx->mlx);
//			return (0);
//		}
//		create_background(mlx, w, h, 0xffffff);
//		mlx->image = create_img(mlx, w, h);
//		colorize(mlx->image.img, w, h, 0x969F34);
//	}
//	return (1);
//}

void		draw_square(t_point a, int len, t_mlx *mlx, char symb)
{
	t_point	b;
	t_point	c;
	t_point	d;

	if (symb == 'X')
		mlx->argb = int_to_argb(ICE);
	else if (symb == 'O')
		mlx->argb = int_to_argb(YEL_GREEN);
	else
		mlx->argb = int_to_argb(GREEN_GRAY);
	b = point_init(a.x + len, a.y);
	c = point_init(a.x + len, a.y - len);
	d = point_init(a.x, a.y - len);
	draw_line(a, b, mlx);
	draw_line(a, d, mlx);
	draw_line(b, c, mlx);
	draw_line(d, c, mlx);
}

int			filler_draw(t_filler *filler)
{
	int		h;
	int		w;
	t_point	start;

	h = 0;
	if (filler->draw && filler->map.map)
	{
		while (h < filler->map.h)
		{
			w = 0;
			while (w < filler->map.w)
			{
				start = point_init(w * (filler->square_len + filler->margin),\
				-(h * (filler->square_len + filler->margin)));
				draw_square(start, filler->square_len, &filler->mlx,\
				(char)filler->map.map[h][w]);
				w++;
			}
			h++;
		}
		put_img_to_window(&filler->mlx, 0, 0);
		filler->draw = 0;
		solution(filler);
	}
	return (1);
}