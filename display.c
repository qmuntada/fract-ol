/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:33:35 by qmuntada          #+#    #+#             */
/*   Updated: 2015/01/16 16:33:36 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_env *e)
{
	int		pos;

	pos = (e->x * e->img.bpp / 8) + (e->y * e->img.sl);
	e->img.img[pos] = (int)(e->color.z * 256) % 256;
	e->img.img[pos + 1] = ((int)(e->color.y * 256) % 256);
	e->img.img[pos + 2] = ((int)(e->color.x * 256) % 256);
}
