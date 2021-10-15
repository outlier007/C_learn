#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//冒泡排序
void bubble_sort(int arr[], int sz)
{
	int i = 0;//确定冒泡排序的趟数
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;//假设这一趟要排序的数据已经有序
		int j = 0;//每一趟冒泡排序
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//本趟数据其实不完全有序
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}
int main()
{
	int arr[] = { 6,9,2,4,10,5,7,3,8,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//对arr[]进行排序，排成升序
	bubble_sort(arr, sz);//arr是数组，对arr进行传参，其实传的是arr的第一个元素的地址&arr[0]
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}