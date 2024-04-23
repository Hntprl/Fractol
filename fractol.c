/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:18:13 by amarouf           #+#    #+#             */
/*   Updated: 2024/04/23 20:50:37 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_event_handler(int keycode, t_var *var)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	return (0);
}

void ft_draw_pixels(t_imf *img, int color, int y, int x)
{
	unsigned int	*pxl;

	pxl = (unsigned int *)img->addr + (x + 800 * y);
	*pxl = color;
}

void	ft_mandelbrot(t_imf *img, t_c *c)
{
	double	i;
	double	x;
	double	y;
	t_z	z;

	i = 0;
	z.real = 0;
	z.img = 0;
	while (i++ < 100)
	{
		x = z.real * z.real;
		y = z.img * z.img;
		if (4 < x + y)
			return(ft_draw_pixels(img, 255, c->img, c->real));
		z.real = x * y - c->real;
		z.img = 2 * z.real * z.img + c->img;
	}
}

void ft_constfinder(t_imf *imf)
{
	t_c		c;
	
	c.real = 0;
	c.img = 0;
	while (c.img < 600)
	{
		while (c.real < 800)
		{
			ft_mandelbrot(imf, &c);
			c.real ++;
		}
		c.real = 0;
		c.img ++;
	}
	
}

void ft_set_window()
{
	t_var   var;
	t_imf	imf;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 800, 600, "Mandelbrot");
	var.img = mlx_new_image(var.mlx, 800, 600);
	imf.addr = mlx_get_data_addr(var.img, &imf.bites_per_pixel, &imf.size_line, &imf.endian);
	ft_constfinder(&imf);
	// ft_draw_pixels(&imf, 255);
	mlx_put_image_to_window(var.mlx, var.win, var.img, 0, 0);
	mlx_key_hook(var.win, key_event_handler, &var);
	mlx_loop(var.mlx);
}

int main (int ac, char **av)
{
	if (ac == 2)
	{
		if (!ft_strnstr(av[1], "Mandelbrot", 10) || ft_strlen(av[1]) > 10)
			(write(1, "Mandelbrot\n", 11), exit(1));
		ft_set_window();
	}
}