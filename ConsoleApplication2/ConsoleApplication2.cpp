// ConsoleApplication2.cpp : 定義主控台應用程式的進入點。
//
#include "stdafx.h"
#include <math.h>
struct point
{
	double x, y, z;
};
int main()
{
	FILE *f = fopen("data.txt", "r");
	point tmp[3][22];
	int now = 0;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 22; i++)
		{
			if (fscanf(f, "%lf %lf %lf", &tmp[j][i].x, &tmp[j][i].y, &tmp[j][i].z) != 3)
				break;
			if (i == 21)
				now++;
		}
		
	}
	now--;
	int turn=0;
	int num = 0;
	while (now == 2)
	{
		int dot_num = 0;
		for (int i = 0; i < 22; i++)
		{

			double dot=(tmp[now - 2][i].x - tmp[now - 1][i].x)*(tmp[now][i].x - tmp[now - 1][i].x) + (tmp[now - 2][i].y - tmp[now - 1][i].y)*(tmp[now][i].y - tmp[now - 1][i].y) + (tmp[now - 2][i].z - tmp[now - 1][i].z)*(tmp[now][i].z - tmp[now - 1][i].z);
			double scalar_1 = sqrt((tmp[now - 2][i].x - tmp[now - 1][i].x)*(tmp[now - 2][i].x - tmp[now - 1][i].x) + (tmp[now - 2][i].y - tmp[now - 1][i].y)*(tmp[now - 2][i].y - tmp[now - 1][i].y) + (tmp[now - 2][i].z - tmp[now - 1][i].z)*(tmp[now - 2][i].z - tmp[now - 1][i].z));
			double scalar_2 = sqrt((tmp[now][i].x - tmp[now - 1][i].x)*(tmp[now][i].x - tmp[now - 1][i].x) + (tmp[now][i].y - tmp[now - 1][i].y)*(tmp[now][i].y - tmp[now - 1][i].y) + (tmp[now][i].z - tmp[now - 1][i].z)*(tmp[now][i].z - tmp[now - 1][i].z));
			double angle=dot / (scalar_1*scalar_2);
			if (angle>0.5)
			{
				dot_num++;
		//		printf(" i=%d angle=%f \n",i,dot/(scalar_1*scalar_2));
		//		printf("%f %f %f\n%f %f %f \n%f %f %f \n\n", tmp[now - 2][i].x, tmp[now - 2][i].y, tmp[now - 2][i].z, tmp[now - 1][i].x, tmp[now - 1][i].y, tmp[now - 1][i].z, tmp[now][i].x, tmp[now][i].y, tmp[now][i].z);
			}

		}
		if (dot_num > 11)
		{
			turn++;
		}
		num++;
		printf("dot: %d  ", dot_num);
		if (num % 5 == 0)
		{
			printf("\n");
		}
			
		for (int j = 0; j < 2; j++)
		{
			for (int i = 0; i < 22; i++)
			{
				tmp[j][i].x = tmp[j+1][i].x;
				tmp[j][i].y = tmp[j+1][i].y;
				tmp[j][i].z = tmp[j+1][i].z;
			}
		}
		now--;
		for (int i = 0; i < 22; i++)
		{
			if (fscanf(f, "%lf %lf %lf", &tmp[now+1][i].x, &tmp[now+1][i].y, &tmp[now+1][i].z) != 3)
				break;
			if (i == 21)
				now++;
			
		}
	}
	printf("turn =%d \n", turn);
	return 0;
}

