#include "h_line.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color, int z)
{
	char	*dst;
	int x1 = (sqrt(2)/2)*(x - y) + 500;
	int y1 = sqrt(2/3) * z - (1/sqrt(6))*(x + y);
	// printf("%d\n", y1);
	y1 *= -1;
	// if(y1<0)
	// 	y1 += 500;
	dst = data->data + (y1 * data->size_line + x1 * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
