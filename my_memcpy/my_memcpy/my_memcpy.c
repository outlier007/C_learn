#define _CRT _SECURE_NO_WARNNIGS 1
#include <stdio.h>
#include <assert.h>

void* my_memcpy(void* dest,void* scr,int num)
{
	char*ret = scr;
	assert(dest&&scr);
	while (num--)
	{
		*(char*)dest = *(char*)scr;
		dest=(char*)dest+1;
		scr=(char*)scr + 1;
		if (scr == '\0')
		{
			return ret;
		}
	}
}

int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[20] = {0};
	//memcpy(arr2,arr1,20);
	//将arr1数组中前20个字节的数据拷贝到arr2中
	my_memcpy(arr2,arr1,20);
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		printf("%d ", arr2[i]);
	}
	
	return 0;
}
