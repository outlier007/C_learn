#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
int my_strlen(const char* len)
{
	int count = 0;
	assert(len != '\0');
	while (*len != '\0')
	{
		count++;
		len++;
	}
	return count;
}
int main()
{
	char arr[] = "hello bit";
	printf("%d", my_strlen(arr));
	return 0;
}