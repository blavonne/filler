#include "graphics_base.h"

void			put_img_to_window(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->background.ptr,\
	x, y);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image.ptr,\
	x, y);
}


