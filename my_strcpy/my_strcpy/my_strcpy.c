#define _CRT _SECURE_NO_WARNNIGS 1
#include <stdio.h>
#include <assert.h>
char* my_strcpy(char*dest,const char*src)
{
	char* ret = dest;
	assert(dest!=NULL);
	assert(src!=NULL);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[] = "abc######";
	char arr2[] = "love";
	my_strcpy(arr1,arr2);//把arr2的内容拷贝到arr1
	//strcpy(arr1,arr2);
	printf("%s",arr1);
	return 0;
}