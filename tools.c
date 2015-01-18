/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:34:09 by qmuntada          #+#    #+#             */
/*   Updated: 2015/01/16 16:45:09 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			dual(int x, int iter, int style)
{
	if (x % 2 == 0)
		x = (pow(256, style) * x) / iter;
	else
		x = (pow(128, style) * x) / iter;
	return (x);
}

int			palette(t_env *e, int x)
{
	int		color;

	color = (256 * x) / e->iter;
	if (e->theme == 1)
		color *= 256;
	else if (e->theme == 2)
		color *= 256 * 256;
	else if (e->theme >= 3 && e->theme <= 5)
		color = dual(x, e->iter, e->theme - 1);
	return (color);
}

double		scaledy(t_env *e, int y)
{
	double dy;

	dy = (((e->ytop - e->ybot) * y) / e->img.height) + e->ybot;
	return (dy);
}

double		scaledx(t_env *e, int x)
{
	double dx;

	dx = (((e->xtop - e->xbot) * x) / e->img.height) + e->xbot;
	return (dx);
}
