/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiffany.gibier <tiffany.gibier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:32:10 by tgibier           #+#    #+#             */
/*   Updated: 2023/06/10 22:15:51 by tiffany.gib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_error(char *str, t_fract *f)
{
	ft_putstr_fd(str, 1);
	ft_putendl_fd("\n---->  Need some help ? Try ./fractol h :)\n\n", 1);
	help_params(f);
	clean_exit(f);
	exit (0);
}


int	clean_exit(t_fract *f)
{
	if (!f)
		exit (0);
	if (f->img.mlx_img)
		mlx_destroy_image(f->mlx, f->img.mlx_img);
	if (f->mlx)
	{
		if (f->win)
			mlx_destroy_window(f->mlx, f->win);
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit (0);
}
