#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include <stdio.h>
typedef struct s_mlx
{
	void *mlx;
	void *win;
	void *img;
	int key;
	int i_o;
	int scale;
	char **matrix;
	int x;
	int y;
	int bpp;
	int size_line;
	int endian;
	char *data;
}t_mlx;
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

#endif
