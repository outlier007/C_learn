#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Tower_of_Hanoi(int n, char A, char B, char C)
{
	if (n == 1)//һ��Բ�̣�ֱ�Ӵ�A�ƶ���C
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
	scanf("%d", &n);//����һ��������ȷ��Բ�̿���
	Tower_of_Hanoi(n, 'A', 'B', 'C');//ʹ�ú�����'A'��'B'��'C'�ֱ������������
	return 0;
}