
#include "fractol.h"

int		palette(int x, int maxiter)
{
	int		color;


	x = (256 * x) / maxiter;
	color = x;
	return (color);
}

double scaledy(t_env *e, int y)
{
	double dy;

	dy = (((e->ytop - e->ybot) * y) / e->img.height) + e->ybot;
	return (dy);
}

double scaledx(t_env *e, int x)
{
	double dx;

	dx = (((e->xtop - e->xbot) * x) / e->img.height) + e->xbot;
	return (dx);
}
