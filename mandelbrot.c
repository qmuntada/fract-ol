/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:33:59 by qmuntada          #+#    #+#             */
/*   Updated: 2015/02/19 19:01:47 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_m(t_env *e, double x0, double y0)
{
	double		x;
	double		y;
	double		x2;
	double		y2;
	double		i;

	x = 0.0;
	y = 0.0;
	x2 = 0.0;
	y2 = 0.0;
	i = -1.0;
	while (++i < e->iter && (x2 + y2) < e->iter)
	{
		y = 2.0 * x * y + y0;
		x = x2 - y2 + x0;
		x2 = x * x;
		y2 = y * y;
	}
	double sco = i - log2(log2(x2 + y2));
	i = ft_mix(i, sco, 1.0);
	e->color = palette(e, i);
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
