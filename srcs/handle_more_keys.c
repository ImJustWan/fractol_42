/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_more_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiffany.gibier <tiffany.gibier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:21:34 by tgibier           #+#    #+#             */
/*   Updated: 2023/06/10 20:17:48 by tiffany.gib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	layout(t_fract *f, double a, double b, double c, double d)
{
	f->min.re = a;
	f->max.re = b;
	f->min.im = c;
	f->max.im = d;
}

void	change_colors(int keysym, t_fract *f)
{
	if (keysym == KEY_M)
		f->palette = MOUNTBATTEN;
	if (keysym == KEY_D)
		f->palette = DIBISTAN;
	if (keysym == KEY_R)
		f->palette = RAINBOW;
	if (keysym == KEY_W)
		f->palette = RORSCHACH;
	if (keysym == KEY_N)
		f->palette = NIGHTSKY;
	if (keysym == KEY_G)
		f->palette = GOLDEN;
}

void	change_iter(int keysym, t_fract *f)
{
	if (keysym == KEY_FIVE || keysym == MAC_FIVE)
		f->max_iter -= 50;
	if (keysym == KEY_EIGHT || keysym == MAC_EIGHT)
		f->max_iter += 50;
}

static void	ze_box(t_fract *f)
{
	f->set = THE_BOX;
	f->palette = GOLDEN;
	f->max_iter = 60;
	layout(f, -5.0, 5.0, -5.0, 5.0);
}

void	change_set(int keysym, t_fract *f)
{
	if ((keysym == KEY_ONE || keysym == MAC_ONE) && f->set != JULIA)
	{	
		f->set = JULIA;
		f->max_iter = 100;
		f->palette = DIBISTAN;
		f->c.re = -0.8;
		f->c.im = 0.2;
		layout(f, -2.0, 2.0, -2.0, 2.0);
	}
	if ((keysym == KEY_TWO || keysym == MAC_TWO) && f->set != MANDELBROT)
	{
		f->set = MANDELBROT;
		f->palette = RAINBOW;
		f->max_iter = 30;
		layout(f, -2.0, 1.0, -1.5, 1.5);
	}
	if ((keysym == KEY_THREE || keysym == MAC_THREE) && f->set != THE_BOX)
		ze_box(f);
	if ((keysym == KEY_FOUR || keysym == MAC_FOUR) && f->set != BURNING_SHIP)
	{
		f->set = BURNING_SHIP;
		f->palette = NIGHTSKY;
		f->max_iter = 50;
		layout(f, -2.0, 1.0, -1.5, 1.0);
	}
}
