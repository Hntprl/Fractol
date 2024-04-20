#include "fractol.h"

typedef struct s_data
{
	void    *mlx;
	void    *win;
	void    *img;
}   t_data;

typedef struct s_ddrs
{
	char	*addr;
	int		endian;
	int		size_line;
	int		bites_per_pixel;
}	t_ddrs;

void ft_mlx_pixel_set(t_ddrs *addrs)
{
	char	*pxl;
	int		color;
	int		i = 0;

	color = 255;
	pxl = addrs->addr;

	while (i < 500)
	{
		*(int*)pxl = color;
		pxl += 4;
		i ++;
	}
}

void ft_window_set()
{
	t_data  var;
	t_ddrs		addrs;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 500, 500, "TITEL");
	var.img = mlx_new_image(var.mlx, 500, 500);
	addrs.addr = mlx_get_data_addr(var.img, &addrs.bites_per_pixel, &addrs.size_line, &addrs.endian);
	printf ("%d\n%d", addrs.bites_per_pixel, addrs.size_line);
	ft_mlx_pixel_set(&addrs);

	mlx_loop(var.mlx);
}


int main()
{
	ft_window_set();
}