/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtualization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiffany.gibier <tiffany.gibier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:21:51 by tgibier           #+#    #+#             */
/*   Updated: 2023/06/04 21:30:49 by tiffany.gib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	virtualization(t_fract *f)
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
