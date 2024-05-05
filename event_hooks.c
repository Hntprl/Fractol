/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:33:57 by amarouf           #+#    #+#             */
/*   Updated: 2024/05/01 23:09:56 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom_handler(int button, int x, int y, t_imf *imf)
{
	(void) y;
	(void) x;
	if (button == 4)
		imf->zoom *= 0.93;
	else if (button == 5)
		imf->zoom *= 1.3;
	else
		return (0);
	ft_constfinder(imf, imf->var);
	return (0);
}

int	key_event_handler(int keycode, t_var *var)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	return (0);
}

void	error_handling(void *ptr)
{
	if (!ptr)
		exit(1);
}

int	close_window(t_var *var)
{
	mlx_destroy_window(var->mlx, var->win);
	exit(0);
}
