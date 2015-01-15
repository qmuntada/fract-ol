
#include "fractol.h"

int		key_press(int keycode, t_env *e)
{
	double	tmp;

	if (keycode == SPACE)
		expose_hook(e);
	else if (keycode == W || keycode == S)
	{
		tmp = (e->ytop - e->ybot) / 2;
		e->ybot += (keycode == S ? tmp : -tmp);
		e->ytop += (keycode == S ? tmp : -tmp);
	}
	else if (keycode == A || keycode == D)
	{
		tmp = (e->xtop - e->xbot) / 2;
		e->xbot += (keycode == D ? tmp : -tmp);
		e->xtop += (keycode == D ? tmp : -tmp);
	}
	else if (keycode == RIGHT || keycode == LEFT && e->iter > 1)
		e->iter += (keycode == RIGHT ? 1 : -1);
	expose_hook(e);
	return (1);
}

int		key_release(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int		mouse(int x, int y, t_env *e)
{
	e->xs = scaledx(e, x);
	e->ys = scaledy(e, y);
	return (1);
}

int		mouse2(int button, int x, int y, t_env *e)
{
	double		x1;
	double		y1;

	x1 = scaledx(e, x);
	y1 = scaledy(e, y);
	if (button == 4 || button == 1)
	{
		e->xbot = x1 + ((e->xbot - x1) / 2);
		e->xtop = e->xtop + ((x1 - e->xtop) / 2);
		e->ybot = y1 + ((e->ybot - y1) / 2);
		e->ytop = e->ytop + ((y1 - e->ytop) / 2);
		e->zoom += 1;
	}
	else if (button == 5 || button == 3)
	{
		e->xbot = e->xbot - ((e->xtop - e->xbot) / 2);
		e->xtop = e->xtop + ((e->xtop - e->xbot) / 2);
		e->ybot = e->ybot - ((e->ytop - e->ybot) / 2);
		e->ytop = e->ytop + ((e->ytop - e->ybot) / 2);
		e->zoom -= 1;
	}
	expose_hook(e);
	return (1);
}
