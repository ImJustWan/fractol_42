/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:43:10 by tgibier           #+#    #+#             */
/*   Updated: 2023/06/14 15:10:44 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "keys.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"

# define WIDTH 		800
# define HEIGHT 	800

# define JULIA 1
# define MANDELBROT 2
# define THE_BOX 3
# define BURNING_SHIP 4

# define MOUNTBATTEN 1
# define DIBISTAN 	2
# define RAINBOW	3
# define RORSCHACH	4
# define NIGHTSKY	5
# define GOLDEN		6

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fract
{
	void		*mlx;
	void		*win;
	int			palette;
	int			set;
	int			iter;
	int			max_iter;
	int			pos_x;
	int			pos_y;
	t_img		img;
	t_complex	z;
	t_complex	size;
	t_complex	min;
	t_complex	max;
	t_complex	mid;
	t_complex	pos;
	t_complex	c;
}	t_fract;

int		main(int argc, char **argv);
void	scanner(int argc, char **argv, t_fract *f);
void	transfer(t_fract *f);
int		virtualization(t_fract *f);

int		initialization(t_fract *f);
void	clean_init(t_fract *f);
int		clean_exit(t_fract *f);
void	handle_error(char *str, t_fract *f);

void	help(int keysym, t_fract *f);
void	help_params(t_fract *f);

void	img_pix_put(t_img *img, int x, int y, int color);

double	sqr(double thing);

void	iter_ia(t_fract *f);
void	iter_brot(t_fract *f);
void	iter_box(t_fract *f);
void	iter_ship(t_fract *f);

int		handle_mouse(int button, int x, int y, t_fract *f);
int		handle_keys(int keysym, t_fract *f);
void	change_set(int keysym, t_fract *f);
void	change_iter(int keysym, t_fract *f);
void	change_colors(int keysym, t_fract *f);

int		palette(int color, t_fract *f);
int		mountbatten(int color);
int		dibistan(int color);
int		rorschach(int color);
int		nightsky(int color);
int		rainbow(int color);
int		golden(int color);

#endif
