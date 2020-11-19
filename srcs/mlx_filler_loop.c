#include "filler.h"

static void		prepare_to_draw(t_filler *filler)
{
	if (!filler->win_h)
	{
		filler->margin = 2;
		filler->square_len = (filler->map.h > 50 ? 5 : 15);
		filler->win_w = filler->map.w * filler->square_len + (filler->map.w)\
		* filler->margin;
		filler->win_h = filler->map.h * filler->square_len + (filler->map.h)\
		* filler->margin;
	}
}

static int		safe_mlx_create(t_mlx *mlx, int w, int h)
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

int				mlx_filler_loop(t_filler *filler)
{
	if (filler->map.w && filler->map.h)
	{
		prepare_to_draw(filler);
		if (!(safe_mlx_create(&filler->mlx, filler->win_w, filler->win_h)))
			return (0);
		mlx_loop_hook(&filler->mlx, to_file_test, 0);
		mlx_loop_hook(&filler->mlx, filler_loop, filler);
		mlx_loop_hook(&filler->mlx, filler_draw, filler);
		mlx_key_hook(filler->mlx.win, clean_exit, filler);
		mlx_hook(filler->mlx.win, 17, 1L << 17, clean_exit2, filler);
		mlx_loop(filler->mlx.mlx);
	}
	return (1);
}