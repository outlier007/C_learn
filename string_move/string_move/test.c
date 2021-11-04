#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int string_move(char*arr1, char*arr2)//判断arr2是否是arr1旋转所得
{
	if (strlen(arr1) != strlen(arr2))
	{
		return 0;
	}
	int len = strlen(arr1);
	strncat(arr1,arr2,len);//将arr2追加到arr1中
	char* ret = strstr(arr1, arr2);//在arr1中找arr2
	return ret != NULL;
}
int main()
{
	char arr1[20] = "ABCDA";
	char arr2[10] = "CDAAB";
	int ret = string_move(arr1,arr2);
	if (ret == 1)
	{
		printf("yes");
	}
	else if (ret == 0)
	{
		printf("no");
	}
	return 0;
}