/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiffany.gibier <tiffany.gibier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:23:10 by tgibier           #+#    #+#             */
/*   Updated: 2023/06/06 10:50:08 by tiffany.gib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	jul_true(int x, int y, t_fract *f)
{
	int		i;
	double	temp;

	i = 0;
	(void)x;
	(void)y;
	while (i <= f->max_iter)
	{
		if ((sqr(f->z.re) + sqr(f->z.im)) > 4)
			break ;
		temp = sqr(f->z.re) - sqr(f->z.im);
		f->z.im = 2 * f->z.re * f->z.im + f->c.im;
		f->z.re = temp + f->c.re;
		i++;
	}
	f->iter = i;
	return ;
}

void	iter_ia(t_fract *f)
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
			f->z.re = f->min.re + (x * (f->max.re - f->min.re) / WIDTH);
			f->z.im = f->min.im + (y * (f->max.im - f->min.im) / HEIGHT);
			jul_true(x, y, f);
			color = palette(100 * f->iter / f->max_iter, f);
			img_pix_put(&f->img, x, y, color);
		}
	}
}
