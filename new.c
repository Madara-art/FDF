#include<stdio.h>
void f(int x1,double y1, double x2, double y2)
{
	double a = (y1 - y2)/(x1 - x2);
	double b = y1 - a*x1;
	printf("%fx + %f\n",a,b);
}
int main(int argc, char const *argv[])
{
	f(1,1,1,3);
	return 0;
}

