/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:16:56 by tgibier           #+#    #+#             */
/*   Updated: 2024/03/26 18:00:03 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	sqr(double thing)
{
	return (thing * thing);
}

void	clean_init(t_fract *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->palette = RAINBOW;
	f->set = 0;
	f->img.mlx_img = NULL;
	f->img.addr = NULL;
	f->img.bpp = 0;
	f->img.line_len = 0;
	f->img.endian = 0;
	f->max_iter = 50;
	f->min.re = -2.0;
	f->max.re = 2.0;
	f->min.im = -2.0;
	f->max.im = 2.0;
	f->mid.re = 0;
	f->mid.im = 0;
}

int	main(int argc, char **argv)
{
	t_fract	f;

	clean_init(&f);
	if (argc == 1)
		help_params(&f);
	f.mlx = mlx_init();
	if (!f.mlx)
		return (0);
	parsing(argc, argv, &f);
	init_mlx(&f);
	clean_exit(&f);
	return (1);
}
