
#include "fractol.h"

void	pixel_put(t_env *e)
{
	int		pos;

	pos = (e->x * e->img.bpp / 8) + (e->y * e->img.sl);
	e->img.img[pos] = (e->color % 256);
	e->img.img[pos + 1] = (e->color >> 8) % 256;
	e->img.img[pos + 2] = (e->color >> 16) % 256;
}
