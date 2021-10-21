#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void move(int arr[], int sz)//�������е���������ǰ��ż�����ں���
{
	int left = 0;
	int right = sz - 1;
	int mtp = 0;
	while (left < right)
	{
		while (left < right&&arr[left] % 2 == 1)//Ѱ������
		{
			left++;//������������
		}
		while (left < right&&arr[right] % 2 == 0)//Ѱ��ż��
		{
			right--;//��ż��������
		}
		mtp = arr[left];
		arr[left] = arr[right];
		arr[right] = mtp;
	}
}
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz ; i++)
//	{
//		printf("%d", arr[i]);
//	}
//}

void print(int* p, int sz)//��ӡ����
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(p + i));
	}
}

int main()
{
	int arr[] = { 1,2,4,3,5,7,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	move(arr, sz);
	print(arr, sz);

	return 0;
}