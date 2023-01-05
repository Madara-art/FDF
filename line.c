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



void draw_line(t_mlx *v,double x1,double y1,double x2,double y2, int z)
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
			my_mlx_pixel_put(v,i,round_it(i*a + b),16777215, z);
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
				my_mlx_pixel_put(v,round_it((i-b)/a),i,16777215, z);
			else
				my_mlx_pixel_put(v,x1,i,16777215, z);

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
	i = 0;
	int j;
	while(i < x)
	{
		j = 0;
		while (j < y)
		{
			map[i][j].x = j;
			map[i][j].y = i;
			map[i][j].z = 0;
			j++;

		}
		i++;
	}
	map[3][3].z = 100;
	map[3][4].z = 100;
	// map[1][1].x = (sqrt(2)/2)*(map[1][1].x - map[1][1].y)+10;
	// map[1][1].y = sqrt(2/3) * 10 - (1/sqrt(6))*(map[1][1].x + map[1][1].y)+10;
	// map[1][2].x += 5;
	// map[1][2].y += 5;
	// map[1][3].x += 5;
	// map[1][3].y += 5;
	// map[2][2].x += 5;
	// map[2][2].y += 5;
	// map[2][3].x += 5;
	// map[2][3].y += 5;
	// map[3][2].x += 5;
	// map[3][2].y += 5;
	// map[3][3].x += 5;
	// map[3][3].y += 5;
	i = 0;
	// while (i < x)
	// {
	// 	j = 0;
	// 	while (j < y - 1)
	// 	{
	// 		//printf("(%d %d)\n", map[i][j].x * 50 , map[i][j].y * 50);
	// 		draw_line(var->mlx, map[i][j].x * 50, map[i][j].y * 50, map[i][j + 1].x * 50, map[i][j + 1].y * 50, 0);
	// 		j++;

	// 	}
	// 	// printf("\n");
	// 	i++;
	// }

	j = -1;
	i = -1;
	while(++i<x)
	{
		j = -1;
		while(++j<y-1)
		draw_line(var,map[i][j].x * 100, map[i][j].y * 100, map[i][j + 1].x * 100, map[i][j + 1].y * 100, map[i][j].z);
	}
	j = -1;
	i = -1;
	while(++i<x-1)
	{
		j = -1;
		while(++j<y)
		draw_line(var,map[i][j].x * 100, map[i][j].y * 100, map[i+1][j].x * 100, map[i+1][j].y * 100, map[i][j].z);
	}
	// i++;
	// printf("(%d %d)\n", map[i][j].x * 50 , map[i][j].y * 50);
	// draw_line(var,map[i][j].x * 50, map[i][j].y * 50, map[i][j + 1].x * 50, map[i][j + 1].y * 50, 0);

	return (map);
}

int main(int argc, char const *argv[])
{
	t_mlx *var;
	int height = 1000;
	int width = 1000;
	var = malloc(sizeof(t_mlx));
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx,width,height,"Hi!");
	var->img = mlx_new_image(var->mlx,width,height);
	var->data = mlx_get_data_addr(var->img,&(var->bpp),&(var->size_line),&(var->endian));
	xyz **s = mh(var);
	// draw_line(var,100 , 100 , 100 ,400 , 0);
	// draw_line(var,100 , 100 , 400 ,100 , 0);
	// draw_line(var,400 , 100 , 400 ,400 , 0);
	// draw_line(var,100 , 400 , 400 ,400 , 0);
	// int e = 0;
	// draw_line(var,100+ e , 100 + e, 100+ e ,400 + e, 600);
	// draw_line(var,100 + e, 100 + e, 400+ e ,100+ e , 600);
	// draw_line(var,400 + e, 100 + e, 400 + e,400 + e, 600);
	// draw_line(var,100 + e, 400 + e, 400 + e,400 + e, 600);
	// draw_line(var,400 , 400 , 400 ,700 );
	// draw_line(var,400 , 400 , 700 ,400 );
	// draw_line(var,700 , 400 , 700 ,700 );
	// draw_line(var,400 , 700 , 700 ,700 );

	// draw_line(var,400 , 100 , 700 ,100 );
	// draw_line(var,400 , 100 , 400 ,400 );
	// draw_line(var,400 , 400 , 700 ,400 );
	// draw_line(var,700 , 400 , 700 ,100 );
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
// int main(int argc, char const *argv[])
// {
// 	mh();
// 	return 0;
// }
