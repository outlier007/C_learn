#define _CRT _SECURE_NO_WARNNIGS 1
#include <stdio.h>
#include <assert.h>
void* my_memmove(void* dest,void*src,int num)
{
	void* ret = dest;
	assert(dest&&src);
	if (dest > src)//从后往前移，避免将前面的数据覆盖了
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
		return ret;
	}
	else
	{        //从前往后移
		while (num--)
		{
			*((char*)dest) = *((char*)src);
			*((char*)dest)++;
			*((char*)src)++;
		}
		return ret;
	}
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[] = { 5,6,7,8,9,10 };
	//memmove(arr1 + 2, arr1, 20);
	my_memmove(arr1,arr1+2,20);
	//my_memmove(arr1+2, arr1, 20);
	//my_memmove(arr1, arr2, 20);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ",arr1[i]);
	}
	return 0;
}

