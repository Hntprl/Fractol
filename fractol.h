/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:18:47 by amarouf           #+#    #+#             */
/*   Updated: 2024/05/01 23:07:26 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <mlx.h>

# define HIGH 900
# define WIDTH 900

typedef struct s_cords
{
	double	y;
	double	x;
}	t_cords;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**av;
	t_cords	*cords;
}			t_var;

typedef struct s_imf
{
	char	*addr;
	int		bites_per_pixel;
	int		size_line;
	int		endian;
	double	zoom;
	t_var	*var;
}			t_imf;

typedef struct s_z
{
	double	img;
	double	real;
}	t_z;

char			*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
double			ft_atof(char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
int				close_window(t_var *var);
int				zoom_handler(int button, int x, int y, t_imf *imf);
int				ft_check_char(char *num);
int				key_event_handler(int keycode, t_var *var);
void			ft_constfinder(t_imf *imf, t_var *var);
void			ft_draw_pixels(t_imf *img, int color, int y, int x);
unsigned int	ft_color_changer(int i);
#endif