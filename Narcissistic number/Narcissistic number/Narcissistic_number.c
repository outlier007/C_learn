#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	int i = 0;
	int tmp = 0;
	for (i = 0; i <= 10000; i++)//产生0-10000的数
	{
		//计算i的位数--n
		tmp = i;
		int n = 1;
		while (tmp / 10)
		{
			n++;
			tmp = tmp / 10;
		}
		tmp = i;
		int sum = 0;
		while (tmp)
		{
			sum += pow(tmp % 10, n);//计算每一位数的n次方之和
			tmp = tmp / 10;
		}
		if (i == sum)
		{
			printf("%d ", i);
		}
	}
	return 0;
}