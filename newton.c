
#include "fractol.h"

void		Ncalculate(t_env *e, double x0, double y0)
{
	int		i;
	double	xx;
	double	yy;
	double	w;

	i = 0;
	while (++i < e->iter)
	{
		xx = 2 * x0 / 3 - (x0 * x0 - y0 * y0) / (x0 * x0 + y0 * y0) \
		/ (x0 * x0 + y0 * y0) / 3;
		yy = 2 * y0 / 3 + 2 * x0 * y0 / (x0 * x0 + y0 * y0) \
		/ (x0 * x0 + y0 * y0) / 3;
		x0 = xx;
		y0 = yy;
		if (x0 * x0 + y0 * y0 < e->tol)
			w = i;
	}
	e->color = palette(e, 255 * w * w / 10 / 10);
	pixel_put(e);
}

void	newton(t_env *e)
{
	e->y = -1;
	while ((e->y += 1) < e->img.width)
	{
		e->x = -1;
		while ((e->x += 1) < e->img.height)
			Ncalculate(e, scaledx(e, e->x), scaledy(e, e->y));
	}
}
