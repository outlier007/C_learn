#define _CRT _SECURE_NO_WARNNIGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
char* my_strstr(const char* str1,const char* str2)
{
	assert(str1&&str2);
	const char* cp = str1;
	const char* s1=NULL;
	const char* s2=NULL;
	if (*str2 == '\0')
	{
		return (char*) str2;
	}
	while (*cp)
	{
		s1 = cp;
		s2 = str2;
		while (*s1&&*s2&&(*s1==*s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char*)cp;
		}
		cp++;
	}
	return NULL;
}
int main()
{
	char arr1[] = "abbbcdef";
	char arr2[] = "bbc";
	//char* str=strstr(arr1,arr2);
	char*str = my_strstr(arr1, arr2);//在一个字符串中找另一个字符串
	if (str != NULL)
	{
		printf("找到了：%s\n",str);
	}
	else
	{
		printf("没找到\n");
	}
	return 0;
}

