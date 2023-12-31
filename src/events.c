/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:26:45 by dacortes          #+#    #+#             */
/*   Updated: 2023/07/27 16:17:37 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fractol.h"

static void	zoom(t_fractol *f, double zoom)
{
	double	cen_re;
	double	cen_im;

	cen_re = f->var.min_re - f->var.max_re;
	cen_im = f->var.max_im - f->var.min_im;
	f->var.max_re = f->var.max_re + (cen_re - zoom * cen_re) / 2;
	f->var.min_re = f->var.max_re + zoom * cen_re;
	f->var.min_im = f->var.min_im + (cen_im - zoom * cen_im) / 2;
	f->var.max_im = f->var.min_im + zoom * cen_im;
}

static void	move(t_fractol *f, double distance, char direction)
{
	double	cen_re;
	double	cen_im;

	cen_re = f->var.min_re - f->var.max_re;
	cen_im = f->var.min_im - f->var.max_im;
	if (direction == 'D')
	{
		f->var.min_re += cen_re * distance;
		f->var.max_re += cen_re * distance;
	}
	else if (direction == 'R')
	{
		f->var.min_re -= cen_re * distance;
		f->var.max_re -= cen_re * distance;
	}
	else if (direction == 'U')
	{
		f->var.min_im -= cen_im * distance;
		f->var.max_im -= cen_im * distance;
	}
	else if (direction == 'L')
	{
		f->var.min_im += cen_im * distance;
		f->var.max_im += cen_im * distance;
	}
}

int	handle_key_event(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESC)
	{
		end_fractol(f);
		return (SUCCESS);
	}
	else if (keycode == KEY_UP)
		move(f, 0.2, 'U');
	else if (keycode == KEY_LEFT)
		move(f, 0.2, 'D');
	else if (keycode == KEY_DOWN)
		move(f, 0.2, 'L');
	else if (keycode == KEY_RIGHT)
		move (f, 0.2, 'R');
	else if (keycode == KEY_T)
		change_theme_key(&f->menu.key_t);
	else
		return (TRUE);
	render(f, -1, -1);
	return (FALSE);
}

int	mouse_event(int keycode, int x, int y, t_fractol *f)
{
	if (f->var.set == JULIA && keycode == MIDDLE_CLICK)
	{
		// Map the x coordinate of the mouse cursor to the real part of the complex constant.
    	// This is done by linearly mapping the x coordinate from the pixel range to the range of real values.
    	f->mouse.posre = f->var.min_re + (double)x * (f->var.max_re - f->var.min_re) / WIDTH;

    	// Map the y coordinate of the mouse cursor to the imaginary part of the complex constant.
    	// This is done by linearly mapping the y coordinate from the pixel range to the range of imaginary values.
    	f->mouse.posim = f->var.max_im + (double)y * (f->var.min_im - f->var.max_im) / HEIGHT;
	}
	if (keycode == SCROLL_UP)
	{
		zoom(f, 1.2);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(f, (double)x * -1 / WIDTH, 'L');
		else if (x < 0)
			move(f, (double)x / WIDTH, 'R');
		else if (y < 0)
			move(f, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move(f, (double)y / HEIGHT, 'D');
	}
	else if (keycode == SCROLL_DOWN)
		zoom(f, 0.8);
	else
		return (FALSE);
	render(f, -1, -1);
	return (FALSE);
}
