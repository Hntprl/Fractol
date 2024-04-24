/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:18:13 by amarouf           #+#    #+#             */
/*   Updated: 2024/04/24 20:06:24 by amarouf          ###   ########.fr       */
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

unsigned int ft_color_changer(int i)
{
	unsigned int g;
	unsigned int r;
	unsigned int b;

	r = (i * 7) % 236;
	g = (i * 14) % 246;
	b = (i * 20) % 238;
	return (r << 16 | g << 8 | b);
}

void ft_draw_pixels(t_imf *img, int color, int y, int x)
{
	unsigned int	*pxl;

	pxl = (unsigned int *)img->addr + (y * width + x);
	*pxl = ft_color_changer(color);
}

void	ft_mandelbrot(t_imf *img, t_c *c, int x, int y)
{
	int		i;
	double	zr;
	double	zi;
	t_z	z;

	i = 0;
	z.real = 0;
	z.img = 0;
	while (i++ < 100)
	{
		zr = z.real * z.real;
		zi = z.img * z.img;
		if (4 < zr + zi)
			return(ft_draw_pixels(img, i, y, x));
		z.img = 2 * z.real * z.img + c->img;
		z.real = zr - zi + c->real;
	}
}

void ft_constfinder(t_imf *imf, double zoom)
{
	t_c		c;
	int		x;
	int		y;
	
	x = -1;
	y = -1;
	c.real = 0;
	c.img = 0;
	while (++y  < high)
	{
		x = 0;
		while (++x  < width)
		{
			c.real = (x - width / 2.0) * 4.0 / width * zoom;
			c.img = (y - high / 2.0) * 4.0 / high * zoom;
			ft_mandelbrot(imf, &c, x, y);
		}
	}
	
}
int	zoom_handler(int button, int x, int y, t_imf *imf)
{
	if (button == 4)
	{
		ft_constfinder(imf, 800);
		printf("HI im here !");
	}
	return (0);
}

void ft_set_window()
{
	t_var   var;
	t_imf	imf;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, width, high, "Mandelbrot");
	var.img = mlx_new_image(var.mlx, width, high);
	imf.addr = mlx_get_data_addr(var.img, &imf.bites_per_pixel, &imf.size_line, &imf.endian);
	ft_constfinder(&imf, 1);
	mlx_put_image_to_window(var.mlx, var.win, var.img, 0, 0);
	mlx_hook(var.win, 17, 0, close_window, &var);
	mlx_key_hook(var.win, key_event_handler, &var);
	mlx_mouse_hook(var.win, zoom_handler, &imf);
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