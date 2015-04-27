/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:33:59 by qmuntada          #+#    #+#             */
/*   Updated: 2015/04/27 17:19:32 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_m(t_env *e, double x0, double y0)
{
	double	x;
	double	y;
	double	x2;
	double	y2;
	double	i;

	x = 0.0;
	y = 0.0;
	x2 = e->xs;
	y2 = e->ys;
	i = -1.0;
	while (++i < e->iter && (x2 + y2) < e->iter)
	{
		y = 2.0 * x * y + y0;
		x = x2 - y2 + x0;
		x2 = x * x;
		y2 = y * y;
	}
	if (e->theme < 3)
		i = ft_mix(i, i - log2(log2(x2 + y2)), 1.0);
	e->color = palette(i, (e->theme > 2 ? e->theme - 3 : e->theme));
	pixel_put(e);
}

void	mandelbrot(t_env *e)
{
	e->y = -1;
	while ((e->y += 1) < e->img.height)
	{
		e->x = -1;
		while ((e->x += 1) < e->img.width)
			calculate_m(e, scaledx(e, e->x), scaledy(e, e->y));
	}
}
