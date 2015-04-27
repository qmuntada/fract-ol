/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 17:18:17 by qmuntada          #+#    #+#             */
/*   Updated: 2015/04/27 17:30:22 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_arg(int n)
{
	if (n == 0)
		ft_putstr_fd("No paramater found\n\n", 2);
	else
		ft_putstr_fd("Incorrect paramater\n", 2);
	ft_putstr_fd("FRACT'OL : Please reboot this program with one", 2);
	ft_putstr_fd(" of the following parameter :\n", 2);
	ft_putstr_fd("M for Mandelbrot\nJ for Julia\nN for Newton\n", 2);
	exit(EXIT_FAILURE);
}

int		frac_type(int ac, char **av)
{
	if (ac < 2)
		error_arg(0);
	if (av[1][0] == 'M')
		return (1);
	else if (av[1][0] == 'J')
		return (2);
	else if (av[1][0] == 'N')
		return (3);
	error_arg(1);
	return (0);
}

void	init_sval(t_env *e)
{
	if (e->ftype == 1)
	{
		e->xbot = -2.5;
		e->xtop = 1;
		e->ybot = -1;
		e->ytop = 1;
	}
	else if (e->ftype == 2)
	{
		e->xbot = -2;
		e->xtop = 2;
		e->ybot = -2;
		e->ytop = 2;
	}
	else if (e->ftype == 3)
	{
		e->xbot = -4;
		e->xtop = 4;
		e->ybot = -4;
		e->ytop = 4;
		e->xs = e->img.width / 2;
	}
}

void	init_env(t_env *e, int ac, char **av)
{
	t_vec3	normedemerde;

	e->ftype = frac_type(ac, av);
	e->img.width = WIDTH;
	e->img.height = HEIGHT;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->img.width, e->img.height, "Fract'ol");
	e->img.img_ptr = mlx_new_image(e->mlx, e->img.width, e->img.height);
	e->img.img = (unsigned char *)mlx_get_data_addr(e->img.img_ptr, \
				&e->img.bpp, &e->img.sl, &e->img.endian);
	e->xs = 0;
	e->ys = 0;
	e->iter = 50;
	e->theme = 0;
	normedemerde = (t_vec3){0.0, 0.0, 0.0};
	e->color = normedemerde;
	init_sval(e);
	e->xoril = e->xbot;
	e->xorir = e->xtop;
}
