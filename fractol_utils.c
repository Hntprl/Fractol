/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:05:23 by amarouf           #+#    #+#             */
/*   Updated: 2024/05/04 17:14:57 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i ++;
	}
	return (i);
}

double	ft_atof_2(char *str, int i, double s)
{
	int		j;
	double	dbl;
	double	a;

	dbl = 1.0;
	a = 0.0;
	while ((str[i] <= '9' && str[i] >= '0') || str[i] == '.')
	{
		if (str[i] == '.')
		{
			j = ++ i;
			while (str[j ++])
			{
				dbl *= 10.0;
				if (str[j] == '.')
					(write(1, "- Fractals:\n--> [Mandelbrot].\n--> [Julia].\n", 43), exit(1));
			}
		}
		a = (str[i] - '0') + (a * 10.0);
		i ++;
	}
	return (a / dbl * s);
}

double	ft_atof(char *str)
{
	int		i;
	double	s;
	double	a;

	s = 1.0;
	i = 0;
	a = 0.0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1.0;
		i ++;
	}
	a = ft_atof_2(str, i, s);
	return (a);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		c1 = s1[i];
		c2 = s2[i];
		if (c1 != c2)
		{
			return (c1 - c2);
		}
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && i + j < len)
			{
				if (needle[j + 1] == '\0')
					return ((char *)haystack + i);
				j ++;
			}
			j = 0;
		}
		i ++;
	}
	return (NULL);
}
