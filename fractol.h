/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:18:47 by amarouf           #+#    #+#             */
/*   Updated: 2024/04/19 20:43:50 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <mlx.h>

typedef struct s_var
{
	void    *mlx;
	void    *win;
	void    *img;
}       t_var;

typedef struct s_imf
{
	char	*addr;
	int		bites_per_pixel;
	int		size_line;
	int		endian;
}   t_imf;

// utils
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlen(const char *s);
#endif