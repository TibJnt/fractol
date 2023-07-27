/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:57:48 by tjeunet           #+#    #+#             */
/*   Updated: 2023/07/25 18:07:44 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fractol.h"

int	change_theme_key(int *theme_key)
{
	(*theme_key)++;
	if (*theme_key >= 4)
		*theme_key = 1;
	ft_printf(Y"iter one by one : %d \n"E, *theme_key);
	return (*theme_key);
}