/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:16:56 by tgibier           #+#    #+#             */
/*   Updated: 2023/06/14 14:07:19 by tgibier          ###   ########.fr       */
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
	ft_putstr_fd("\t\t\t\t\t\t\t/*\\\tJULIA\t\t/*\\\t\t Press '1'\n\n", 1);
	ft_putstr_fd("\t\t\t\t\t\t\t/*\\\tMANDELBROT\t/*\\\t\t Press '2'\n\n", 1);
	ft_putstr_fd("\t\t\t\t\t\t\t/*\\\tMANDELBOX\t/*\\\t\t Press '3'\n\n", 1);
	ft_putstr_fd("\t\t\t\t\t\t\t/*\\\tBURNING SHIP\t/*\\\t\t Press '4'\n\n", 1);
	ft_putstr_fd("\n\n\n\t\t\t\t\t\t", 1);
	ft_putendl_fd("\t\t\t\t\t\t\t\tFor the main menu press 'H'\n\n\n\n", 1);
}

static void	help_palette(int keysym)
{
	(void)keysym;
	ft_putstr_fd("\t\t\t=========================\t\tWELCOME TO THE ", 1);
	ft_putendl_fd("PALETTE HELP CENTER\t\t=========================\n\n", 1);
	ft_putstr_fd("\n\t\t\t/*\\\t\033[35;1mMOUNTBATTEN\033[0m", 1);
	ft_putendl_fd("\t/*\\\t\t(purple gradient)\t\t------>\t\tpress 'M'\n\n", 1);
	ft_putstr_fd("\t\t\t/*\\\t\033[36;1mDIBISTAN\033[0m\t", 1);
	ft_putendl_fd("/*\\\t\t(blue gradient)\t\t\t------>\t\tpress 'D'\n\n", 1);
	ft_putstr_fd("\t\t\t/*\\\t\033[30;1mRORSCHACH\033[0m\t", 1);
	ft_putendl_fd("/*\\\t\t(B&W gradient)\t\t\t------>\t\tpress 'W'\n\n", 1);
	ft_putstr_fd("\t\t\t/*\\\t\033[34;1mNIGHTSKY\033[0m\t/*\\\t\t", 1);
	ft_putendl_fd("(blue to yellow gradient)\t------>\t\tpress 'N'\n\n", 1);
	ft_putstr_fd("\t\t\t/*\\\t\033[31;1mR\033[0m", 1);
	ft_putstr_fd("\033[31;1mA\033[0m", 1);
	ft_putstr_fd("\033[33;1mI\033[0m", 1);
	ft_putstr_fd("\033[32;1mN\033[0m", 1);
	ft_putstr_fd("\033[34;1mB\033[0m", 1);
	ft_putstr_fd("\033[35;1mO\033[0m", 1);
	ft_putstr_fd("\033[35;1mW\033[0m\t\t/*\\", 1);
	ft_putendl_fd("\t\t(rainbow gradient duh)\t\t------>\t\tpress 'R'\n\n", 1);
	ft_putstr_fd("\t\t\t/*\\\t\033[33;1mGOLDEN\033[0m\t\t/*\\\t\t(it's in ", 1);
	ft_putstr_fd("the name init)\t\t------>\t\tpress 'G'\n\n\n\n\t\t\t\t", 1);
	ft_putendl_fd("\t\t\t\t\t\t\t\t\t\tFor the main menu press 'H'\n\n\n\n", 1);
}

void	help_params(t_fract *f)
{
	ft_putstr_fd("\t\t\t=========================\t\tWELCOME TO THE PARAMS", 1);
	ft_putstr_fd(" HELP CENTER\t\t=========================\n\n\n\n\t\t\t", 1);
	ft_putstr_fd("To display Julia set, write \033[36;1m\"$>./fractol 1", 1);
	ft_putendl_fd("\"\033[0m or \033[36;1m\"$>./fractol Julia\"\033[0m", 1);
	ft_putendl_fd("\t\t\t\t-  Default constant params are -0.8 and 0.2", 1);
	ft_putstr_fd("\t\t\t\t-  You can enter different params :\n\t\t\t\t\t", 1);
	ft_putstr_fd("- Enter exactly two args, which will be the real and ", 1);
	ft_putstr_fd("imaginary parts of the constant c\n\t\t\t\t\t- Both ", 1);
	ft_putendl_fd("args have to be > -2.0 and < 2.0 and include a '.'", 1);
	ft_putstr_fd("\n\n\t\t\t", 1);
	ft_putstr_fd("To display Mandelbrot set, write \033[36;1m\"$>./fractol 2", 1);
	ft_putendl_fd("\"\033[0m or \033[36;1m\"$>./fractol Mandelbrot\"\033[0m", 1);
	ft_putstr_fd("\n\n\t\t\t", 1);
	ft_putstr_fd("To display Mandelbox set, write \033[36;1m\"$>./fractol 3", 1);
	ft_putendl_fd("\"\033[0m or \033[36;1m\"$>./fractol Mandelbox\"\033[0m", 1);
	ft_putstr_fd("\n\n\t\t\t", 1);
	ft_putstr_fd("To display Burning Ship set, write \033[36;1m\"$>./fractol", 1);
	ft_putendl_fd(" 4\"\033[0m or \033[36;1m\"$>./fractol Ship\"\033[0m\n\n\n", 1);
	clean_exit(f);
}

void	help_menu(int keysym, t_fract *f)
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
	if (keysym == KEY_C)
		help_controls(keysym);
	if (keysym == KEY_F)
		help_fractals(keysym);
	if (keysym == KEY_P)
		help_palette(keysym);
}
