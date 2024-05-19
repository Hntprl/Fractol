/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:33:57 by amarouf           #+#    #+#             */
/*   Updated: 2024/05/19 13:38:29 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mouse_hook(int button, int x, int y, t_imf *imf)
{
	(void) y;
	(void) x;
	if (button == 4)
	{
		imf->zoom *= 0.93;
		imf->adj = 0.1 * imf->zoom;
	}
	else if (button == 5)
		imf->zoom *= 1.3;
	else
		return (0);
	ft_constfinder(imf, imf->var);
	return (0);
}

int	key_event_hook(int keycode, t_imf *imf)
{
	if (keycode == 65362)
		imf->var->u_d -= imf->adj;
	else if (keycode == 65364)
		imf->var->u_d += imf->adj;
	else if (keycode == 65363)
		imf->var->l_r += imf->adj;
	else if (keycode == 65361)
		imf->var->l_r -= imf->adj;
	else if (keycode == 65307)
		ft_destroy(imf->var);
	else
		return (0);
	ft_constfinder(imf, imf->var);
	return (0);
}

void	error_handling(void *ptr)
{
	if (!ptr)
		exit(1);
}

int	close_window(t_var *var)
{
	ft_destroy(var);
	return (0);
}

void	ft_destroy(t_var *var)
{
	mlx_destroy_image(var->mlx, var->img);
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_display(var->mlx);
	free(var->mlx);
	exit(0);
}
