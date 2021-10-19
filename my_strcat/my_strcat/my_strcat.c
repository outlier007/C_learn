#define _CRT _SECURE_NO_WARNNIGS 1
#include <stdio.h>
#include <assert.h>
char* my_strcat(char*dest, char*src)
{
	char*set = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return set;
}
int main()
{
	char arr1[15] = "hello ";
	char arr2[] = "word";
	my_strcat(arr1,arr2);
	printf("%s",arr1);
	return 0;
}