#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int  camp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

//打印
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

void swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

//模仿qsort函数写一个通用冒泡排序函数
void bubble_sort(void*base, int sz, int width, int(*cmp)(const void*e1, const void*e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)//一次冒泡排序
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1)*width) > 0)
			{
				swap((char*)base + j * width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}

void test3()
{
	int arr[] = { 1,3,2,4,7,5,8,0,9,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), camp_int);
	print(arr, sz);
}

int main()
{
	
	test3();

	return 0;
}