/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:24:28 by tjeunet           #+#    #+#             */
/*   Updated: 2023/07/25 17:24:31 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/fractol.h"

int	burning_ship(t_fractol *f, double cr, double ci)
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
		zy = fabs(2.0 * zx * zy) + ci;
		zx = tmp;
	}
	return (i);
}
