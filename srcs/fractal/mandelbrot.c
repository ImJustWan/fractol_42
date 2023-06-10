/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiffany.gibier <tiffany.gibier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:23:10 by tgibier           #+#    #+#             */
/*   Updated: 2023/06/06 14:12:39 by tiffany.gib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	mandel_true(t_fract *f)
{
	int		i;
	double	temp;

	i = 0;
	f->z.re = 0;
	f->z.im = 0;
	while (i < f->max_iter)
	{
		if (sqr(f->z.re) + sqr(f->z.im) > 4)
			break ;
		temp = sqr(f->z.re) - sqr(f->z.im);
		f->z.im = 2 * f->z.re * f->z.im + f->c.im;
		f->z.re = temp + f->c.re;
		i++;
	}
	f->iter = i;
}

void	iter_brot(t_fract *f)
{
	int	x;
	int	y;
	int	color;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			f->c.re = f->min.re + (x * (f->max.re - f->min.re) / WIDTH);
			f->c.im = f->min.im + (y * (f->max.im - f->min.im) / HEIGHT);
			mandel_true(f);
			color = palette(100 * f->iter / f->max_iter, f);
			img_pix_put(&f->img, x, y, color);
		}
	}
}
