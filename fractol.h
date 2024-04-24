/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:18:47 by amarouf           #+#    #+#             */
/*   Updated: 2024/04/24 20:51:33 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <mlx.h>

#define high 900
#define width 1000
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
	double	zoom;
}   t_imf;

typedef	struct s_c
{
	double	img;
	double	real;
}	t_c;

typedef struct s_z
{
	double	img;
	double	real;
}	t_z;

// utils
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlen(const char *s);
int		close_window(t_var *var);
#endif