/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:34:05 by qmuntada          #+#    #+#             */
/*   Updated: 2015/01/16 16:44:28 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_n(t_env *e, double x0, double y0)
{
	int		i;
	double	xx;
	double	yy;
	double	i2;

	i = 0;
	i2 = 0;
	while (++i < e->iter)
	{
		xx = 2 * x0 / 3 - (x0 * x0 - y0 * y0) / (x0 * x0 + y0 * y0) \
		/ (x0 * x0 + y0 * y0) / 3;
		yy = 2 * y0 / 3 + 2 * x0 * y0 / (x0 * x0 + y0 * y0) \
		/ (x0 * x0 + y0 * y0) / 3;
		x0 = xx;
		y0 = yy;
		if (x0 * x0 + y0 * y0 < (e->xs / e->img.width))
			i2 = i;
	}
	e->color = palette(e, i2);
	pixel_put(e);
}

void	newton(t_env *e)
{
	e->y = -1;
	while ((e->y += 1) < e->img.width)
	{
		e->x = -1;
		while ((e->x += 1) < e->img.height)
			calculate_n(e, scaledx(e, e->x), scaledy(e, e->y));
	}
}
