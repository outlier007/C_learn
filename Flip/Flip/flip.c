#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//ת������˳��
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
	int len = strlen(arr);//������ӳ���
	reverse(arr, arr + len - 1);//�������ӵ���ĸ˳��Ի�
	char *start = arr;
	while (*start)
	{
		char *end = start;
		while (*end != ' '&&*end != '\0')//��ȡ�����е�һ������
		{
			end++;
		}
		reverse(start, end - 1);//�������ȡ�ĵ��ʵ���ĸ˳����жԻ�
		if (*end = ' ')//�ж��Ƿ��Ǿ��ӽ���
			start = end + 1;
		else
			start = end;
	}

	printf("%s", arr);
	return 0;
}