/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:24:46 by tjeunet           #+#    #+#             */
/*   Updated: 2023/07/25 17:24:49 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/fractol.h"

int	mandelbrot(double cr, double ci, t_fractol *f)
{
	double	zx;
	double	zy;
	double	tmp;
	int		i;

	zx = 0;
	zy = 0;
	i = -1;
	while (zx * zx + zy * zy <= 4.0 && ++i < f->iter_max)
	{
		tmp = zx * zx - zy * zy + cr;
		zy = 2 * zx * zy + ci;
		zx = tmp;
	}
	return (i);
}
