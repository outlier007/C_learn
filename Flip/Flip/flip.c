#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//转换单词顺序
void reverse(char* left, char* right)
{
	char tmp = 0;
	while (left < right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
int main()
{
	char arr[100] = { 0 };
	gets(arr);
	int len = strlen(arr);//计算句子长度
	reverse(arr, arr + len - 1);//整个句子的字母顺序对换
	char *start = arr;
	while (*start)
	{
		char *end = start;
		while (*end != ' '&&*end != '\0')//获取句子中的一个单词
		{
			end++;
		}
		reverse(start, end - 1);//对上面获取的单词的字母顺序进行对换
		if (*end = ' ')//判断是否是句子结束
			start = end + 1;
		else
			start = end;
	}

	printf("%s", arr);
	return 0;
}