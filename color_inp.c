/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_inp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:39:37 by amarouf           #+#    #+#             */
/*   Updated: 2024/04/29 19:07:59 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	ft_color_changer(int i)
{
	unsigned int	g;
	unsigned int	r;
	unsigned int	b;

	r = (i * 9) % 236;
	g = (i * 19) % 236;
	b = (i * 29) % 234;
	return (r << 16 | g << 8 | b);
}

int	ft_check_char(char *num)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (num[0] == '\0')
		return (0);
	while (num[i])
	{
		if ((num[i] > '0' || num[i] < '9')
			&& (num[i + 1] == '+' || (num[i + 1] == '-')))
			return (0);
		if (num[i] == '-' || num[i] == '+' || num[i] == '.')
			i ++;
		if (num[i] < '0' || num[i] > '9')
			return (0);
		i ++;
	}
	return (1);
}

void	ft_draw_pixels(t_imf *img, int color, int y, int x)
{
	unsigned int	*pxl;

	pxl = (unsigned int *)img->addr + (y * WIDTH + x);
	*pxl = ft_color_changer(color);
}
