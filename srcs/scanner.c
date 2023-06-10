/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiffany.gibier <tiffany.gibier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:00:09 by tgibier           #+#    #+#             */
/*   Updated: 2023/06/10 22:25:59 by tiffany.gib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	half_atof(int i, double res, char *str)
{
	double	div;

	div = 0.1;
	if (str[i] == '0' || str[i] == '1')
	{
		res = (res * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	else
		return (-42);
	while (str[i] >= '0' && str[i] <= '9' )
	{
		res = res + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	return (res);
}

static double	ft_atof(char *str)
{
	int		i;
	int		neg;
	double	res;

	i = 0;
	neg = 1;
	res = 0;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	res = half_atof(i, res, str);
	if (res == -42)
		return (-42);
	return (res * neg);
}

static void	loading_julia(char **argv, t_fract *f)
{
	if (argv[2][0] != '-' && argv[2][0] != '0' && argv[2][0] != '1'
		&& argv[3][0] != '-' && argv[3][0] != '0' && argv[3][0] != '1')
		handle_error("Wrong format for Julia parameters\n", f);
	f->c.re = ft_atof(argv[2]);
	f->c.im = ft_atof(argv[3]);
	f->set = JULIA;
	f->palette = DIBISTAN;
	if (f->c.re == -42 || f->c.im == -42)
		handle_error("Invalid parameters for Julia :(\n", f);
}

static void	scanner_julia(int argc, char **argv, t_fract *f)
{
	f->max_iter = 100;
	if (argc == 2)
	{
		change_set(KEY_ONE, f);
	}
	else if (argc == 4)
		loading_julia(argv, f);
	else
	{
		handle_error("Julia takes either two or no args :)\n", f);
		exit (0);
	}
}

void	scanner(int argc, char **argv, t_fract *f)
{
	if (ft_strncmp(argv[1], "1", 20) == 0
		|| ft_strncmp(argv[1], "Julia", 20) == 0)
		scanner_julia(argc, argv, f);
	else if (argc == 2)
	{
		if (ft_strncmp(argv[1], "2", 20) == 0
			|| ft_strncmp(argv[1], "Mandelbrot", 20) == 0)
			change_set(KEY_TWO, f);
		else if (ft_strncmp(argv[1], "3", 20) == 0
			|| ft_strncmp(argv[1], "Box", 20) == 0)
			change_set(KEY_THREE, f);
		else if (ft_strncmp(argv[1], "4", 20) == 0
			|| ft_strncmp(argv[1], "Ship", 20) == 0)
			change_set(KEY_FOUR, f);
		else if (argv[1][0] == 'h' || argv[1][0] == 'H')
			help_params(f);
		else
			handle_error("Invalid parameter, sorry !\n", f);
	}
	else
		handle_error("\n", f);
}
