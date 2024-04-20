/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:18:13 by amarouf           #+#    #+#             */
/*   Updated: 2024/04/19 21:59:17 by amarouf          ###   ########.fr       */
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

void ft_draw_pixels(t_imf *img)
{
	int i = 0;
	int color = 65280;
	char *pxl;

	pxl = img->addr;
		*(int*) pxl = color;
}

void ft_set_window()
{
	t_var   var;
	t_imf	imf;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 1920, 1080, "Mandelbrot");
	var.img = mlx_new_image(var.mlx, 1920, 1080);
	imf.addr = mlx_get_data_addr(var.img, &imf.bites_per_pixel, &imf.size_line, &imf.endian);
	printf("%d\n%d", imf.bites_per_pixel, imf.size_line);
	ft_draw_pixels(&imf);
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