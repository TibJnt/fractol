/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:25:10 by tjeunet           #+#    #+#             */
/*   Updated: 2023/07/25 17:25:24 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fractol.h"

static int	clear_free(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return (ERROR);
}

static char	*conv_low(char *tmp, char *agv)
{
	int	i;

	tmp = ft_calloc(ft_strlen(agv) + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	ft_strlcpy(tmp, agv, ft_strlen(agv) + 1);
	while (tmp[i])
	{
		tmp[i] = ft_tolower(tmp[i]);
		i++;
	}
	return (tmp);
}

static void	args_error_menu(void)
{
	ft_printf(B"Error-->Usage: ./fractol [fractal]\n"E);
	ft_printf(B"Fractals :\n1.Mandelbrot\n2.Julia\n3.Burning ship\n"E);
}

static int	check_arg(char *tmp)
{
	if (ft_strncmp(tmp, "mandelbrot", 10) != 0
		&& ft_strncmp(tmp, "julia", 5) != 0
		&& ft_strncmp(tmp, "burning ship", 12) != 0
		&& ft_strncmp(tmp, "union", 5) != 0)
	{
		ft_printf(R"Error-->Wrong fractal name\n"E);
		args_error_menu();
		return (FALSE);
	}
	else
	{
		if (ft_strncmp(tmp, "mandelbrot", 10) == 0)
			return (MANDELBROT);
		else if (ft_strncmp(tmp, "julia", 5) == 0)
			return (JULIA);
		else if (ft_strncmp(tmp, "burning ship", 12) == 0)
			return (BURNING_SHIP);
		else if (ft_strncmp(tmp, "union", 5) == 0)
			return (UNION);
	}
	return (FALSE);
}

int	parse_args(int argc, char *argv)
{
	char	*tmp;
	int		f;

	tmp = NULL;
	f = 0;
	if (argc != 2)
	{
		ft_printf(R"Error-->Wrong number of arguments\n"E);
		args_error_menu();
		free(tmp);
		return (ERROR);
	}
	else
	{
		tmp = conv_low(tmp, argv);
		if (!tmp)
			return (clear_free(tmp));
		f = check_arg(tmp);
		if (f == FALSE)
			return (clear_free(tmp));
		free(tmp);
	}
	return (f);
}
