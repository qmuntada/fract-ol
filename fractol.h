
#ifndef FRACTOL_H
# define FRACTOL_H

# define LINUX
//# define MAC

# ifdef MAC
#  include </usr/X11/include/X11/X.h>
#  include </usr/X11/include/X11/Xlib.h>
# endif

# ifdef LINUX
#  include <X11/X.h>
#  include <X11/Xlib.h>
# endif

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <time.h>

# define WIDTH 1000
# define HEIGHT 1000

# define ESC 65307

typedef struct			s_img
{
	void				*win;
	void				*img_ptr;
	unsigned char		*img;
	int					bpp;
	int					sl;
	int					endian;
	int					width;
	int					height;
}						t_img;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	t_img				img;
	int					color;
	int					ftype;
	int					iter;
	int					x;
	int					y;
	long double			xbotM;
	long double			xtopM;
	long double			ybotM;
	long double			ytopM;
}						t_env;

void	init_env(t_env *e, int ac, char **av);
int		mouse(int x, int y, t_env *e);
int		mouse2(int button, int x, int y, t_env *e);
int		key_press(int keycode, t_env *e);
int		key_release(int keycode, t_env *e);
void	mandelbrot(t_env *e);
void	pixel_put(t_env *e);
long double	scaledx(t_env *e, int x);
long double	scaledy(t_env *e, int y);
int		expose_hook(t_env *e);

#endif
