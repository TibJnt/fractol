/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:26:52 by tjeunet           #+#    #+#             */
/*   Updated: 2023/07/25 17:26:54 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fractol.h"

void	clean_win(int code, t_fractol *f)
{
	if (!f)
		exit(code);
	if (f->win.img)
		mlx_destroy_image(f->win.mlx, f->win.img);
	if (f->win.mlx)
		mlx_destroy_window(f->win.mlx, f->win.win);
	exit(code);
}

int	msg_err(char *str, int error)
{
	ft_printf(R"Fractol :\n"E);
	ft_printf("%s", str);
	return (error);
}

int	end_fractol(t_fractol *f)
{
	ft_printf(B"--> The End.\n"E);
	clean_win(0, f);
	return (SUCCESS);
}
