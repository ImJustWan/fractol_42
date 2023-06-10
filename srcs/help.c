/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiffany.gibier <tiffany.gibier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:16:56 by tgibier           #+#    #+#             */
/*   Updated: 2023/06/10 22:21:37 by tiffany.gib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	help_controls(int keysym)
{
	(void)keysym;
	ft_putstr_fd("\t\t\t=========================\t\tWELCOME TO THE ", 1);
	ft_putendl_fd("CONTROLS HELP CENTER\t\t=========================\n\n", 1);
	ft_putstr_fd("\n\t\t\tThe arrows do usual arrow stuff : move around ", 1);
	ft_putstr_fd("using ← ↑ → ↓\n\n\t\t\tZoom controls : use the + ", 1);
	ft_putendl_fd("and - buttons to zoom in and out (centered)\n", 1);
	ft_putstr_fd("\t\t\tYou can zoom following your mouse: \n\t\t\t\t", 1);
	ft_putstr_fd("- Scroll up = zoom in\n\t\t\t\t- Scroll down = ", 1);
	ft_putstr_fd("zoom out\n\n\t\t\tAlso, if you're in Julia, try a ", 1);
	ft_putstr_fd("middle click ( ͡° ͜ʖ ͡°)\n\n\n\n\t\t\t\t\t\t", 1);
	ft_putendl_fd("\t\t\t\t\t\t\t\tFor the main menu press 'H'\n\n\n\n", 1);
	
}

static void	help_fractals(int keysym)
{
	(void)keysym;
	ft_putstr_fd("\t\t\t=========================\t\tWELCOME TO THE ", 1);
	ft_putendl_fd("FRACTALS HELP CENTER\t\t=========================\n\n", 1);
	ft_putendl_fd("\n\n\t\t\tWhich one do you want ?\n\n\n", 1);
	ft_putstr_fd("\t\t\t/*\\\tJULIA\t\t/*\\\t\t Press '1'\n\n", 1);
	// ft_putendl_fd("Wanna change to Julia ? Press '1'\n\n", 1);
	ft_putstr_fd("\t\t\t/*\\\tMANDELBROT\t/*\\\t\t Press '2'\n\n", 1);
	// ft_putendl_fd("Wanna change to Mandelbrot ? Press '2'\n\n", 1);
	ft_putstr_fd("\t\t\t/*\\\tMANDELBOX\t/*\\\t\t Press '3'\n\n", 1);
	// ft_putendl_fd("tWanna change to Mandelbox ? Press '3'\n\n", 1);	
	ft_putstr_fd("\t\t\t/*\\\tBURNING SHIP\t/*\\\t\t Press '4'\n\n", 1);
	// ft_putendl_fd("Wanna change to Burning Ship ? Press '4'", 1);
	ft_putstr_fd("\n\n\n\t\t\t\t\t\t", 1);
	ft_putendl_fd("\t\t\t\t\t\t\t\tFor the main menu press 'H'\n\n\n\n", 1);
	
}

static void	help_palette(int keysym)
{
	(void)keysym;
	ft_putstr_fd("\t\t\t=========================\t\tWELCOME TO THE ", 1);
	ft_putendl_fd("PALETTE HELP CENTER\t\t=========================\n\n", 1);
	ft_putstr_fd("\n\t\t\t/*\\\tMOUNTBATTEN\t/*\\\t\t(purple gradient)", 1);
	ft_putendl_fd("\t\t------>\t\tpress 'M'\n\n", 1);
	ft_putstr_fd("\t\t\t/*\\\tDIBISTAN\t/*\\\t\t(blue gradient)", 1);
	ft_putendl_fd("\t\t\t------>\t\tpress 'D'\n\n", 1);
	ft_putstr_fd("\t\t\t/*\\\tRORSCHACH\t/*\\\t\t(B&W gradient)", 1);
	ft_putendl_fd("\t\t\t------>\t\tpress 'W'\n\n", 1);
	ft_putstr_fd("\t\t\t/*\\\tNIGHTSKY\t/*\\\t\t(blue to yellow gradient)", 1);
	ft_putendl_fd("\t------>\t\tpress 'N'\n\n", 1);
	ft_putstr_fd("\t\t\t/*\\\tRAINBOW\t\t/*\\\t\t(rainbow gradient duh)", 1);
	ft_putendl_fd("\t\t------>\t\tpress 'R'\n\n", 1);
	ft_putstr_fd("\t\t\t/*\\\tGOLDEN\t\t/*\\\t\t(it's in the name init)", 1);
	ft_putstr_fd("\t\t------>\t\tpress 'G'\n\n\n\n\t\t\t\t\t\t", 1);
	ft_putendl_fd("\t\t\t\t\t\t\t\tFor the main menu press 'H'\n\n\n\n", 1);
}

void	help_params(t_fract *f)
{
	ft_putstr_fd("\t\t\t=========================\t\tWELCOME TO THE PARAMS", 1);
	ft_putendl_fd(" HELP CENTER\t\t=========================\n\n\n", 1);
	ft_putstr_fd("\t\t\tTo display Julia set, write \"$>./fractol 1\" or ", 1);
	ft_putendl_fd("\"$./fractol Julia\"", 1);
	ft_putendl_fd("\t\t\t\t-  Default constant params are -0.8 and 0.2", 1);
	ft_putstr_fd("\t\t\t\t-  You can enter different params :\n\t\t\t\t\t", 1);
	ft_putstr_fd("- Enter exactly two args, which will be the real and ", 1);
	ft_putstr_fd("imaginary parts of the constant c\n\t\t\t\t\t- Both ", 1);
	ft_putendl_fd("args have to be > -2.0 and < 2.0 and include a '.'\n\n", 1);
	ft_putstr_fd("\t\t\tTo display Mandelbrot set, write \"$>./fractol", 1);
	ft_putendl_fd(" 2\" or \"$./fractol Mandelbrot\"\n\n", 1);
	ft_putstr_fd("\t\t\tTo display Mandelbox set, write \"$>./fractol 3\"", 1);
	ft_putendl_fd(" or \"$./fractol Box\"\n\n", 1);
	ft_putstr_fd("\t\t\tTo display Burning Ship set, write \"$>./fractol ", 1);
	ft_putendl_fd("4\" or \"$./fractol Ship\"\n\n\n", 1);
	clean_exit(f);
}

void	help(int keysym, t_fract *f)
{
	(void)f;
	if (keysym == KEY_H)
	{
		ft_putstr_fd("\t\t\t=========================\t\tWELCOME", 1);
		ft_putendl_fd("TO THE HELP CENTER\t\t=========================", 1);
		ft_putendl_fd("\n\n\t\t\tWhat do you need exactly ?\n\n\n", 1);
		ft_putstr_fd("\t\t\t/*\\\tCONTROLS\t/*\\\t\t------>", 1);
		ft_putendl_fd("\t\tTo get controls options, please press 'C'\n\n", 1);
		ft_putstr_fd("\t\t\t/*\\\tFRACTALS\t/*\\\t\t------>", 1);
		ft_putendl_fd("\t\tTo get fractal options, please press 'F'\n\n", 1);
		ft_putstr_fd("\t\t\t/*\\\tPALETTE\t\t/*\\\t\t------>", 1);
		ft_putstr_fd("\t\tTo get palette / colors options, ", 1);
		ft_putendl_fd("please press 'P'\n\n\n\n\n", 1);
	}
	if (keysym  == KEY_C)
		help_controls(keysym);
	if (keysym  == KEY_F)
		help_fractals(keysym);
	if (keysym  == KEY_P)
		help_palette(keysym);
}
