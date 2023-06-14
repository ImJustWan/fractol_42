/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:51:27 by tgibier           #+#    #+#             */
/*   Updated: 2023/06/14 14:41:49 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_in(t_fract *f, t_complex mouse, double zoom)
{
	double	diff_re;
	double	diff_im;

	diff_re = mouse.re - f->min.re;
	diff_im = mouse.im - f->min.im;
	f->size.re = (f->max.re - f->min.re) * zoom;
	f->size.im = (f->max.im - f->min.im) * zoom;
	f->min.re = f->min.re + diff_re * (zoom / 4);
	f->max.re = f->min.re + f->size.re;
	f->min.im = f->min.im + diff_im * (zoom / 4);
	f->max.im = f->min.im + f->size.im;
}

static void	zoom_out(t_fract *f, t_complex mouse, double zoom)
{
	double	diff_re;
	double	diff_im;

	diff_re = mouse.re - f->min.re;
	diff_im = mouse.im - f->min.im;
	f->size.re = (f->max.re - f->min.re) * zoom;
	f->size.im = (f->max.im - f->min.im) * zoom;
	f->min.re = f->min.re - diff_re * (zoom / 6);
	f->max.re = f->min.re + f->size.re;
	f->min.im = f->min.im - diff_im * (zoom / 6);
	f->max.im = f->min.im + f->size.im;
}

int	handle_mouse(int button, int x, int y, t_fract *f)
{
	t_complex	mouse;

	mouse.re = f->min.re + x * ((f->max.re - f->min.re) / (WIDTH));
	mouse.im = f->min.im + y * ((f->max.im - f->min.im) / (HEIGHT));
	if (button == MOUSE_SCR_UP)
		zoom_in(f, mouse, 0.8);
	if (button == MOUSE_SCR_DOWN)
		zoom_out(f, mouse, 1.2);
	if (f->set == JULIA && button == MOUSE_MID)
	{
		f->c.re = mouse.re;
		f->c.im = mouse.im;
	}
	return (0);
}
