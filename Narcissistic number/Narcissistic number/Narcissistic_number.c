#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	int i = 0;
	int tmp = 0;
	for (i = 0; i <= 10000; i++)//����0-10000����
	{
		//����i��λ��--n
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
			sum += pow(tmp % 10, n);//����ÿһλ����n�η�֮��
			tmp = tmp / 10;
		}
		if (i == sum)
		{
			printf("%d ", i);
		}
	}
	return 0;
}