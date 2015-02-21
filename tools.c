/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:34:09 by qmuntada          #+#    #+#             */
/*   Updated: 2015/02/19 19:05:26 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*t_vec		dual(int x, int iter, int style)
{
	if (x % 2 == 0)
		x = (pow(256, style) * x) / iter;
	else
		x = (pow(128, style) * x) / iter;
	return (x);
}*/

t_vec3		palette(t_env *e, double x)
{
	t_vec3	color;

	color.x = 0.5 + 0.5 * cos(3.0 + x * 0.15 + (e->theme == 0));
	color.y = 0.5 + 0.5 * cos(3.0 + x * 0.15 + (e->theme == 1));
	color.z = 0.5 + 0.5 * cos(3.0 + x * 0.15 + (e->theme == 2));
	//else if (e->theme >= 3 && e->theme <= 5)
		//color = dual(x, e->iter, e->theme - 1);
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
