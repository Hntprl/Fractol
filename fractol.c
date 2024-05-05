/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:18:13 by amarouf           #+#    #+#             */
/*   Updated: 2024/05/05 20:32:53 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_julia(t_z *c, t_var *var)
{
	t_z		julia;
	int		i;
	double	zr;
	double	zi;

	i = 0;
	julia.real = ft_atof(var->av[2]);
	julia.img = ft_atof(var->av[3]);
	while (i++ < 100)
	{
		zr = c->real * c->real;
		zi = c->img * c->img;
		if (4 < zr + zi)
			return (i);
		c->img = 2 * c->real * c->img - julia.img;
		c->real = zr - zi + julia.real;
	}
	return (0);
}

int	ft_mandelbrot(t_z *c)
{
	int		i;
	double	zr;
	double	zi;
	t_z		z;

	i = 0;
	z.real = 0;
	z.img = 0;
	while (i++ < 100)
	{
		zr = z.real * z.real;
		zi = z.img * z.img;
		if (4 < zr + zi)
			return (i);
		z.img = 2 * z.real * z.img + c->img;
		z.real = zr - zi + c->real;
	}
	return (0);
}

void	ft_constfinder(t_imf *imf, t_var *var)
{
	t_z		c;
	// t_cords	cords;

	var->cords->x = -1;
	var->cords->y = -1;
	c.real = 0;
	c.img = 0;
	// var->cords = &cords;
	while (++var->cords->y < HIGH)
	{
		var->cords->x = 0;
		while (++var->cords->x < WIDTH)
		{
			c.real = (var->cords->x - WIDTH / 2.0) * 4.0 / WIDTH * imf->zoom;
			c.img = (var->cords->y - HIGH / 2.0) * 4.0 / HIGH * imf->zoom;
			if (!ft_strncmp(var->av[1], "Julia", 6))
				ft_draw_pixels(imf, ft_julia(&c, var), var->cords->y, var->cords->x);
			else
				ft_draw_pixels(imf, ft_mandelbrot(&c), var->cords->y, var->cords->x);
		}
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
}

void	ft_set_window(t_var *var)
{
	t_imf	imf;

	imf.var = var;
	imf.zoom = 1.0;
	var->mlx = mlx_init();
	error_handling(var->mlx);
	var->win = mlx_new_window(var->mlx, WIDTH, HIGH, "Fractal");
	error_handling(var->win);
	var->img = mlx_new_image(var->mlx, WIDTH, HIGH);
	error_handling(var->img);
	imf.addr = mlx_get_data_addr(var->img, &imf.bites_per_pixel,
			&imf.size_line, &imf.endian);
	error_handling(&imf.addr);
	ft_constfinder(&imf, var);
	mlx_mouse_hook(var->win, zoom_handler, &imf);
	mlx_hook(var->win, 17, 0, close_window, var);
	mlx_key_hook(var->win, key_event_handler, var);
	mlx_loop(var->mlx);
}

int	main(int ac, char **av)
{
	t_var	var;
	t_cords	cords;

	var.cords = &cords;
	var.av = av;
	if (ac == 2)
	{
		if (!ft_strncmp(av[1], "Mandelbrot", 11))
			ft_set_window(&var);
	}
	if (ac == 4)
	{
		if (!ft_strncmp(av[1], "Julia", 6))
			if (ft_check_char(av[2]) && ft_check_char(av[3]))
				ft_set_window(&var);
	}
	(write(1, "- Fractals:\n--> [Mandelbrot].\n--> [Julia].\n", 43), exit(1));
}
