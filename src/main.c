/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:27:49 by tjeunet           #+#    #+#             */
/*   Updated: 2023/07/25 17:27:50 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fractol.h"

static void	get_set(t_fractol *f, int check)
{
	if (check == MANDELBROT)
	{
		ft_printf(G"Mandelbrot fractal generated correctly👍\n"E);
			f->var.set = MANDELBROT;
	}
	else if (check == JULIA)
	{
		ft_printf(G"Julia fractal generated correctly👍\n"E);
		f->var.set = JULIA;
	}
	else if (check == BURNING_SHIP)
	{
		ft_printf(G"Burning Ship fractal generated correctly👍\n"E);
		f->var.set = BURNING_SHIP;
	}
}

int	main(int argc, char **argv)
{
	t_fractol	f;
	int			check;

	check = parse_args(argc, argv[1]);
	if (check == ERROR)
		exit(E_EXIT);
	init_var(&f);
	get_set(&f, check);
	init(&f, check);
	render(&f, -1, -1);
	mlx_hook(f.win.win, BTN_X, 0, end_fractol, &f);
	mlx_key_hook(f.win.win, key_event, &f);
	mlx_mouse_hook(f.win.win, mouse_event, &f);
	mlx_loop(f.win.mlx);
	return (SUCCESS);
}
