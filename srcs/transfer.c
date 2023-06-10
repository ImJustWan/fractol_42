/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:26:56 by tgibier           #+#    #+#             */
/*   Updated: 2023/06/02 17:47:47 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	wow(t_fract *f)
{
	if (f->set == JULIA)
	{
		f->c.re = f->z.re;
		f->c.im = f->z.im;
	}
	return (0);
}

void	transfer(t_fract *f)
{
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractoooooool baby");
	if (!f->win)
		clean_exit(f);
	mlx_loop_hook(f->mlx, virtualization, f);
	mlx_hook(f->win, DESTROY, 0, clean_exit, f);
	mlx_key_hook(f->win, handle_keys, f);
	mlx_mouse_hook(f->win, handle_mouse, f);
	mlx_loop(f->mlx);
	mlx_destroy_image(f->mlx, f->img.mlx_img);
}
