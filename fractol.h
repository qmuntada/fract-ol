/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:47:53 by qmuntada          #+#    #+#             */
/*   Updated: 2015/01/16 16:48:53 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/X.h>
# include <X11/Xlib.h>
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
# define SPACE 32
# define W 119
# define A 97
# define S 115
# define D 100
# define T 116
# define LEFT 65361
# define RIGHT 65363

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
	int					theme;
	int					zoom;
	double				xbot;
	double				xtop;
	double				ybot;
	double				ytop;
	double				xs;
	double				ys;
	double				tol;
}						t_env;

void					init_env(t_env *e, int ac, char **av);
int						mouse(int x, int y, t_env *e);
int						mouse2(int button, int x, int y, t_env *e);
int						key_press(int keycode, t_env *e);
int						key_release(int keycode, t_env *e);
void					mandelbrot(t_env *e);
void					julia(t_env *e);
void					newton(t_env *e);
void					pixel_put(t_env *e);
double					scaledx(t_env *e, int x);
double					scaledy(t_env *e, int y);
int						palette(t_env *e, int x);
int						expose_hook(t_env *e);

#endif
