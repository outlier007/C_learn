#define _CRT _SECURE_NO_WARNNIGS 1
#include <stdio.h>
#include <assert.h>
int my_strcmp(const char* arr1,const char* arr2)
{
	int ret = 0;
	assert(arr1!=NULL);
	assert(arr2 != NULL);
	while (!(ret = *arr1 - *arr2) && *arr2)
	{      
		arr1++;
		arr2++;
	}
	return ret;
}

int main()
{
	char arr1[] = "abc";
	char arr2[] = "abc";
	int ret=my_strcmp(arr1,arr2);//比较两个字符串的大小
	if (ret > 0)
	{
		printf("arr1>arr2");
	}
	else if (ret < 0)
	{
		printf("arr1<arr2");
	}
	else
		printf("arr1=arr2");
	return 0;
}