/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:33:51 by qmuntada          #+#    #+#             */
/*   Updated: 2015/02/19 19:01:30 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_j(t_env *e, double x0, double y0)
{
	double		x1;
	double		y1;
	int			i;

	i = -1;
	while (++i < e->iter && (x0 + y0) < 4)
	{
		x1 = x0;
		y1 = y0;
		x0 = x1 * x1 - y1 * y1 + e->xs;
		y0 = 2 * x1 * y1 + e->ys;
	}
	e->color = palette(e, i);
	pixel_put(e);
}

void	julia(t_env *e)
{
	e->y = -1;
	while ((e->y += 1) < e->img.width)
	{
		e->x = -1;
		while ((e->x += 1) < e->img.height)
			calculate_j(e, scaledx(e, e->x), scaledy(e, e->y));
	}
}
