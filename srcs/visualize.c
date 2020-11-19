#include "filler.h"

void		clean_mlx(t_mlx *mlx)
{
	if (mlx->image.ptr)
		mlx_destroy_image(mlx->mlx, mlx->image.ptr);
	if (mlx->background.ptr)
		mlx_destroy_image(mlx->mlx, mlx->background.ptr);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
		free(mlx->mlx);
}

static int	safe_mlx_create(t_mlx *mlx, int w, int h)
{
	if (!mlx->mlx)
	{
		if (!(mlx->mlx = create_mlx()))
			return (0);
		if (!(mlx->win = create_win(mlx, w, h, "Filler")))
		{
			free(mlx->mlx);
			return (0);
		}
		create_background(mlx, w, h, 0xffffff);
		mlx->image = create_img(mlx, w, h);
		colorize(mlx->image.img, w, h, 0x969F34);
	}
	return (1);
}

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

int			clean_exit(int key, t_filler *filler)
{
	if (key == ESC)
	{
		clean_mlx(&filler->mlx);
		if (filler->map.map)
			clean_two_dim((void ***)&filler->map.map);
		if (filler->piece.piece)
			clean_two_dim((void ***)&filler->piece.piece);
		exit(1);
	}
	return (0);
}

int			clean_exit2(t_filler *filler)
{
	clean_mlx(&filler->mlx);
	if (filler->map.map)
		clean_two_dim((void ***)&filler->map.map);
	if (filler->piece.piece)
		clean_two_dim((void ***)&filler->piece.piece);
	exit(1);
}

int			vizualize(t_filler *filler)
{
	int		h;
	int		w;
	int		size;
	int		margin;
	t_point	start;

	size = (filler->map.h > 50 ? 5 : 15);
	margin = 2;
	if (!safe_mlx_create(&filler->mlx, filler->map.w * size + (filler->map.w)\
	* margin, filler->map.h * size + (filler->map.h) * margin))
		return (0);
	h = 0;
	if (filler->map.map)
	{
		while (h < filler->map.h)
		{
			w = 0;
			while (w < filler->map.w)
			{
				start = point_init(w * (size + margin), -(h * (size + margin)));
				draw_square(start, size, &filler->mlx, (char)filler->map.map[h][w]);
				w++;
			}
			h++;
		}
		mlx_key_hook(filler->mlx.win, clean_exit, filler);
		mlx_hook(filler->mlx.win, 17, 1L << 17, clean_exit2, filler);
		put_img_to_window(&filler->mlx, 0, 0);
	}
	return (1);
}