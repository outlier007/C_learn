#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Tower_of_Hanoi(int n, char A, char B, char C)
{
	if (n == 1)//一个圆盘，直接从A移动到C
		printf("%c-->%c\n", A, C);
	else
	{
		Tower_of_Hanoi(n - 1, A, C, B);
		printf("%c-->%c\n", A, C);
		Tower_of_Hanoi(n - 1, B, A, C);
	}
}
int main()
{
	int n;
	scanf("%d", &n);//输入一个整数，确定圆盘块数
	Tower_of_Hanoi(n, 'A', 'B', 'C');//使用函数，'A'、'B'、'C'分别代表三根柱子
	return 0;
}