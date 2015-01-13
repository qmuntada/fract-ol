
#include "fractol.h"

void		error_arg(int n)
{
	if (n == 0)
		ft_putstr_fd(" No paramater found\n", 2);
	else
		ft_putstr_fd(" Incorrect paramater\n", 2);
	ft_putstr_fd( " Please reboot this program with one of the following parameter :\n", 2);
	ft_putstr_fd(" M\n J\n C\n", 2);
	exit(EXIT_FAILURE);
}

int		frac_type(int ac, char **av)
{
	if (ac < 2)
		error_arg(0);
	if (av[1][0] ==  'M')
		return (1);
	else if (av[1][0] == 'J')
		return (2);
	else if (av[1][0] == 'C')
		return (3);
	error_arg(1);
}

void	init_env(t_env *e, int ac, char **av)
{
	e->ftype = frac_type(ac, av);
	e->img.width = WIDTH;
	e->img.height = HEIGHT;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->img.width, e->img.height, "Fract'ol");
	e->img.img_ptr = mlx_new_image(e->mlx, e->img.width, e->img.height);
	e->img.img = mlx_get_data_addr(e->img.img_ptr, &e->img.bpp, \
			&e->img.sl, &e->img.endian);
	e->xbotM = -2.5;
	e->xtopM = 1;
	e->ybotM = -1;
	e->ytopM = 1;
	e->iter = 200;
}