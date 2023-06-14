/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_box.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:23:10 by tgibier           #+#    #+#             */
/*   Updated: 2023/06/14 10:26:12 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	golden(int color)
{
	static int	golden[100] = {0x110902, 0x150b01, 0x190c01, 0x1c0e00, 0x1f0f00,
		0x221000, 0x271403, 0x2d1705, 0x331a07, 0x3a1d09, 0x40200b, 0x47230d,
		0x4d260e, 0x542a0f, 0x5b2d0f, 0x623010, 0x693411, 0x703711, 0x773a12,
		0x7e3e12, 0x8c4513, 0x9b4c14, 0xaa5314, 0xb95b14, 0xc96214, 0xd86a13,
		0x432304, 0x4d2807, 0x592e08, 0x65340a, 0x713a0a, 0x7d400b, 0x89460c,
		0x964c0d, 0xa3530d, 0xb1590e, 0xbe5f0f, 0xcc6510, 0xda6c11, 0xe87212,
		0x753004, 0x6e2d04, 0x672a03, 0x612702, 0x5a2401, 0x7c4910, 0x814c10,
		0x865010, 0x8b5311, 0x8f5611, 0x945a12, 0x995d12, 0xc07913, 0xc57d13,
		0xca8113, 0xcf8412, 0xd48812, 0xd88c12, 0xdd9011, 0x753004, 0x6e2d04,
		0x672a03, 0x612702, 0x5a2401, 0xe29311, 0xe79710, 0xec9b10, 0xf19f0f,
		0xa94302, 0xa33c02, 0x3d1f01, 0x6E3700, 0x783C01, 0x7F4102, 0x8D4601,
		0x924800, 0x7E3E01, 0x773A01, 0x753004, 0x6e2d04, 0x672a03, 0x612702,
		0x5a2401, 0x964f0f, 0xB0621C, 0xB5661E, 0xC56E19, 0xECD4BC, 0x000000};

	return (golden[color]);
}

double	the_box(double z)
{
	if (z > 1)
		z = 2 - z;
	else if (z < -1)
		z = -2 - z;
	return (z);
}

double	the_ball(double r, double mag)
{
	if (mag < r)
		mag = mag / (r * r);
	else if (mag < 1)
		mag = 1 / (mag * mag);
	return (mag);
}

void	render_box(t_fract *f)
{
	int		i;
	double	mag;

	i = 0;
	mag = 0;
	f->z.re = f->c.re;
	f->z.im = f->c.im;
	while (i <= f->max_iter)
	{
		f->z.re = 1 * the_box(f->z.re);
		f->z.im = 1 * the_box(f->z.im);
		mag = sqrt(sqr(f->z.re) + sqr(f->z.im));
		f->z.re = f->z.re * 2 * the_ball(0.5, mag) + f->c.re;
		f->z.im = f->z.im * 2 * the_ball(0.5, mag) + f->c.im;
		if (sqrt(mag) > 2)
			break ;
		i++;
	}
	f->iter = i;
}

/*
vr = f->fx * box_fold(vr);
vr = vr * f->sx * ball_fold(f->rx, mag) + cr;

avec :

	f->sx = 2.0;
	f->rx = 0.5;
	f->fx = 1.0;
*/

void	iter_box(t_fract *f)
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
			render_box(f);
			color = palette(98 * f->iter / f->max_iter, f);
			img_pix_put(&f->img, x, y, color);
		}
	}
}
