#include "h_line.h"

int round_it(double x)
{
	if(x-(int)x>0.5)
		return (int)x +1;
	else
		return (int) x;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct s_coordinates {
	int x;
	int y;
	int z;
} xyz;



void draw_line(t_mlx *v,double x1,double y1,double x2,double y2)
{
	double a;
	int i,max;
	a = (y1 - y2)/(x1 - x2);
	double b = y1 - a*x1;
	// printf("%fx + %f\n",a,b);
	if(a <= 1 && a >= -1)
	{
		if(x1<x2)
		{
			max = x2;
			i = x1 - 1;
		}
		else
		{
			max = x1;
			i = x2 - 1;
		}
		while(i++ < max)
		{
			my_mlx_pixel_put(v,i,round_it(i*a + b),16777215);
		}
	}
	else
	{
		if(y1<y2)
		{
			max = y2;
			i = y1 - 1;
		}
		else
		{
			max = y1;
			i = y2 - 1;
		}
		while(i++ < max)
		{
			if(x1!=x2)
				my_mlx_pixel_put(v,round_it((i-b)/a),i,16777215);
			else
				my_mlx_pixel_put(v,x1,i,16777215);

		}
	}
}

xyz **mh(t_mlx *var)
{
	int x = 5;
	int y = 8;
	int i = 0;
	xyz **map;
	map = malloc(sizeof(xyz*) * x);

	while (i < x)
	{
		map[i] = malloc(sizeof(xyz) * y);
		i++;
	}
	i = 2;
	int j;
	while(i < x + 2)
	{
		j = i;
		while (j < y + i)
		{
			map[i - 2][j - i].x = j;
			map[i - 2][j - i].y = i;
			j++;

		}
		i++;
	}
	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			printf("(%d %d)\t", map[i][j].x * 10 , map[i][j].y * 10);
			//draw_line(var->mlx, map[i][j].x * 30, map[i][j].y * 30, map[i][j + 1].x * 30, map[i][j + 1].y * 30);
			j++;

		}
		printf("\n");
		i++;
	}
	return (map);
}

int main(int argc, char const *argv[])
{
	t_mlx *var;
	int height = 700;
	int width = 1000;
	var = malloc(sizeof(t_mlx));
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx,width,height,"Hi!");
	var->img = mlx_new_image(var->mlx,width,height);
	var->data = mlx_get_data_addr(var->img,&(var->bpp),&(var->size_line),&(var->endian));
	// xyz **s = mh(var);
	draw_line(var,100 , 100 , 100 ,500 );
	draw_line(var,100 , 100 , 500 ,100 );
	draw_line(var,500 , 100 , 500 ,500 );
	draw_line(var,100 , 500 , 500 ,500 );

	// int a;
	// int x1=10,x2=20,y1=10,y2=30;
	// a = (x1-x2)/(y1-y2);
	// int i = x1-1;
	// while(i++<x2)
	// 	my_mlx_pixel_put(var,i,i*a,150);
	mlx_put_image_to_window(var->mlx,var->win,var->img,0,0);
	mlx_loop(var->mlx);
	return 0;
}
