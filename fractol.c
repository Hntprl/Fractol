/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:18:13 by amarouf           #+#    #+#             */
/*   Updated: 2024/04/25 21:37:36 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_event_handler(int keycode, t_var *var)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	return (0);
}

unsigned int	ft_color_changer(int i)
{
	unsigned int	g;
	unsigned int	r;
	unsigned int	b;

	r = (i * 5);
	g = (i * 18);
	b = (i * 23);
	return (r << 16 | g << 8 | b);
}

void	ft_draw_pixels(t_imf *img, int color, int y, int x)
{
	unsigned int	*pxl;

	pxl = (unsigned int *)img->addr + (y * width + x);
	*pxl = ft_color_changer(color);
}

int	ft_mandelbrot(t_imf *img, t_z *c, int x, int y)
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
			return(i);
		z.img = 2 * z.real * z.img + c->img;
		z.real = zr - zi + c->real;
	}
	return (0);
}

void	ft_constfinder(t_imf *imf, t_var *var)
{
	t_z	c;
	int	x;
	int	y;

	x = -1;
	y = -1;
	c.real = 0;
	c.img = 0;
	while (++y  < high)
	{
		x = 0;
		while (++x  < width)
		{
			c.real = (x - width / 2.0) * 4.0 / width * imf->zoom;
			c.img = (y - high / 2.0) * 4.0 / high * imf->zoom;
			ft_draw_pixels(imf, ft_mandelbrot(imf, &c, x, y), y, x);
		}
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
}
int	zoom_handler(int button, int x, int y, t_imf *imf)
{
	if (button == 4)
		imf->zoom *= 0.93;
	else if  (button == 5)
		imf->zoom *= 1.3;
	else
		return (0);
	ft_constfinder(imf, imf->var);
	return (0);
}

void ft_set_window()
{
	t_var   var;
	t_imf	imf;

	imf.var = &var;
	imf.zoom = 1.0;
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, width, high, "Mandelbrot");
	var.img = mlx_new_image(var.mlx, width, high);
	imf.addr = mlx_get_data_addr(var.img, &imf.bites_per_pixel, &imf.size_line, &imf.endian);
	ft_constfinder(&imf, &var);
	mlx_mouse_hook(var.win, zoom_handler, &imf);
	mlx_hook(var.win, 17, 0, close_window, &var);
	mlx_key_hook(var.win, key_event_handler, &var);
	mlx_put_image_to_window(var.mlx, var.win, var.img, 0, 0);
	mlx_loop(var.mlx);
}

int main (int ac, char **av)
{
	if (ac == 2)
	{
		if (!ft_strnstr(av[1], "Mandelbrot", 10) || ft_strlen(av[1]) > 10)
			if (!ft_strnstr(av[1], "Julia", 10) || ft_strlen(av[1]) > 5)
				(write(1, "- Fractals:\n--> [Mandelbrot].\n--> [Julia].\n", 43), exit(1));
		ft_set_window();
	}
}