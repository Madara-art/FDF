#include "h_line.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
