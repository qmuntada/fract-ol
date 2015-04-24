/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:47:53 by qmuntada          #+#    #+#             */
/*   Updated: 2015/04/24 18:42:43 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <time.h>

# define WIDTH 640
# define HEIGHT 480

# define ESC 53
# define SPACE 49
# define W 13
# define A 0
# define S 1
# define D 2
# define T 17
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125

typedef struct			s_img
{
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
	t_vec3				color;
	int					ftype;
	int					iter;
	int					x;
	int					y;
	int					theme;
	double				xbot;
	double				xtop;
	double				ybot;
	double				ytop;
	double				xorir;
	double				xoril;
	double				xs;
	double				ys;
}						t_env;

void					init_env(t_env *e, int ac, char **av);
int						mouse(int button, int x, int y, t_env *e);
int						mouse2(int x, int y, t_env *e);
int						key_press(int keycode, t_env *e);
void					mandelbrot(t_env *e);
void					julia(t_env *e);
void					newton(t_env *e);
void					pixel_put(t_env *e);
double					scaledx(t_env *e, int x);
double					scaledy(t_env *e, int y);
t_vec3					palette(double x, int theme);
int						expose_hook(t_env *e);

#endif
