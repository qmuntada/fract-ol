
#include "fractol.h"

int		key_press(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int		key_release(int keycode, t_env *e)
{
	return (1);
}

int		mouse(int x, int y, t_env *e)
{
	return (1);
}

int		mouse2(int button, int x, int y, t_env *e)
{
	float	x1;
	float	y1;

	printf("button %d x %d y %d\n", button, x, y);
	x1 = scaledx(e, x);
	y1 = scaledy(e, y);
	if (button == 4)
	{
		e->xbotM = x1 + ((e->xbotM - x1) / 2);
		e->xtopM = e->xtopM + ((x1 - e->xtopM) / 2);
		e->ybotM = y1 + ((e->ybotM - y1) / 2);
		e->ytopM = e->ytopM + ((y1 - e->ytopM) / 2);
	}
	if (button == 5)
	{
		;
	}
	e->iter += 10;
	expose_hook(e);
	return (1);
}