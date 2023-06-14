/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:21:34 by tgibier           #+#    #+#             */
/*   Updated: 2023/06/14 10:22:32 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_move(int keysym, t_fract *f)
{
	f->mid.re = f->min.re - f->max.re;
	f->mid.im = f->max.im - f->min.im;
	if (keysym == LEFT)
	{
		f->min.re += f->mid.re * 0.03;
		f->max.re += f->mid.re * 0.03;
	}
	if (keysym == UP)
	{
		f->min.im -= f->mid.im * 0.03;
		f->max.im -= f->mid.im * 0.03;
	}
	if (keysym == RIGHT)
	{
		f->min.re -= f->mid.re * 0.03;
		f->max.re -= f->mid.re * 0.03;
	}
	if (keysym == DOWN)
	{
		f->min.im += f->mid.im * 0.03;
		f->max.im += f->mid.im * 0.03;
	}
}

static void	key_zoom(int keysym, t_fract *f)
{
	if (keysym == KEY_PLUS)
	{
		f->min.re *= 0.8;
		f->min.im *= 0.8;
		f->max.re *= 0.8;
		f->max.im *= 0.8;
	}
	if (keysym == KEY_MINUS)
	{
		f->min.re *= 1.2;
		f->min.im *= 1.2;
		f->max.re *= 1.2;
		f->max.im *= 1.2;
	}
}

int	handle_keys(int keysym, t_fract *f)
{
	mlx_hook(f->win, 17, 0, clean_exit, f);
	if (keysym == ESC)
		clean_exit(f);
	help(keysym, f);
	key_move(keysym, f);
	key_zoom(keysym, f);
	change_set(keysym, f);
	change_iter(keysym, f);
	change_colors(keysym, f);
	return (0);
}
