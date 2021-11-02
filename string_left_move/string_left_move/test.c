#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void string_left_move(char*set, int k)
{
	int len = strlen(set);
	int i = 0;
	char tmp = 0;
	for (i = 0; i <k; i++)
	{
		tmp = *set;
		int j = 0;
		for (j = 0; j < len - 1; j++)
		{
			*(set + j) = *(set + j + 1);
		}
		*(set + len - 1) = tmp;
	}
}
int main()
{
	char arr[10] = "ABCDEFG";
	int k = 0;
	scanf("%d",&k);
	string_left_move(arr,k);
	printf("%s",arr);
	return 0;
}