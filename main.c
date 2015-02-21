/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:33:55 by qmuntada          #+#    #+#             */
/*   Updated: 2015/01/16 16:33:56 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_env *e)
{
	if (e->ftype == 1)
		mandelbrot(e);
	else if (e->ftype == 2)
		julia(e);
	else if (e->ftype == 3)
		newton(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
	mlx_string_put(e->mlx, e->win, 5, 24, 0xFFFFFF, "Iterations :");
	mlx_string_put(e->mlx, e->win, 80, 24, 0xFFFFFF, ft_itoa(e->iter));
	return (1);
}

int		main(int ac, char **av)
{
	t_env e;

	init_env(&e, ac, av);
	mlx_hook(e.win, KeyPress, KeyPressMask, &key_press, &e);
	mlx_hook(e.win, KeyRelease, KeyReleaseMask, &key_release, &e);
	mlx_hook(e.win, MotionNotify, PointerMotionMask, &mouse, &e);
	mlx_hook(e.win, ButtonPress, ButtonPressMask, &mouse2, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (1);
}
