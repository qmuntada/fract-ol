
#include "fractol.h"

int		palette(int x)
{
	return (x);
}

long double scaledy(t_env *e, int y)
{
	long double dy;

	dy = (((e->ytopM - e->ybotM) * y) / e->img.height) + e->ybotM;
	return (dy);
}

long double scaledx(t_env *e, int x)
{
	long double dx;

	dx = (((e->xtopM - e->xbotM) * x) / e->img.width) + e->xbotM;
	return (dx);
}

void		calculate(t_env *e, long double x0, long double y0)
{
	long double		x;
	long double		y;
	long double		xtemp;
	int			iteration;

	x = 0.0;
	y = 0.0;
	iteration = -1;
	while (x * x + y * y < 2 * 2 && ++iteration < e->iter)
	{
		xtemp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtemp;
	}
	e->color = palette(iteration);
	pixel_put(e);
}

void	mandelbrot(t_env *e)
{
	e->y = 0;
	printf("start\n");
	while (e->y < e->img.width)
	{
		e->x = 0;
		while (e->x < e->img.height)
		{
			calculate(e, scaledx(e, e->x), scaledy(e, e->y));
			e->x += 1;
		}
		e->y += 1;
	}
	printf("finish\n");
}
