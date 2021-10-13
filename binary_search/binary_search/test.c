#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//���ֲ���

int binary_search(int arr[], int k, int sz)
{
	int left = 0;
	int right = sz-1;
	
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (k < arr[mid])
		{
			right = mid-1;
		}
		if (k > arr[mid])
		{
			left = mid+1;
		}
		else
			return mid;
	}
	if (left > right)
	{
		return -1;
	}
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int k = 0;
	scanf("%d",&k);
	int sz = sizeof(arr) / sizeof(arr[0]);
	int set=binary_search(arr, k, sz);
	if (set == -1)
	{
		printf("�Ҳ�����Ӧ������\n");
	}
	else
	{
		printf("�ҵ��ˣ��±��� %d\n", set);
	}
	return 0;
}