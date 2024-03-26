/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:26:56 by tgibier           #+#    #+#             */
/*   Updated: 2024/03/26 17:57:07 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


#include "fractol.h"

int	palette(int color, t_fract *f)
{
	if (f->palette == MOUNTBATTEN)
		color = mountbatten(color);
	if (f->palette == DIBISTAN)
		color = dibistan(color);
	if (f->palette == RAINBOW)
		color = rainbow(color);
	if (f->palette == RORSCHACH)
		color = rorschach(color);
	if (f->palette == NIGHTSKY)
		color = nightsky(color);
	if (f->palette == GOLDEN)
		color = golden(color);
	return (color);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	render(t_fract *f)
{
	if (!f->mlx || !f->win)
		clean_exit(f);
	if (f->img.mlx_img)
		mlx_destroy_image(f->mlx, f->img.mlx_img);
	f->img.mlx_img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->img.addr = mlx_get_data_addr(f->img.mlx_img, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
	if (f->set == MANDELBROT)
		iter_brot(f);
	if (f->set == JULIA)
		iter_ia(f);
	if (f->set == THE_BOX)
		iter_box(f);
	if (f->set == BURNING_SHIP)
		iter_ship(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img.mlx_img, 0, 0);
	return (0);
}

void	init_mlx(t_fract *f)
{
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractoooooool baby");
	if (!f->win)
		clean_exit(f);
	mlx_loop_hook(f->mlx, render, f);
	mlx_hook(f->win, DESTROY, 0, clean_exit, f);
	mlx_key_hook(f->win, handle_keys, f);
	mlx_mouse_hook(f->win, handle_mouse, f);
	mlx_loop(f->mlx);
	mlx_destroy_image(f->mlx, f->img.mlx_img);
}
