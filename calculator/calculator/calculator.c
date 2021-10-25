#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void menu()
{
	printf("************************\n");
	printf("****1.Add   2.Sub*******\n");
	printf("****3.Mul   4.Div*******\n");
	printf("********0.exit**********\n");
	printf("************************\n");
}

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}




//int main()
//{
//	int x;
//	int y;
//	int ret;
//	int input;
//	do
//	{
//		menu();
//		printf("��ѡ��>:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("������Ҫ�����ֵ>:");
//			scanf("%d %d", &x,&y);
//			ret=Add(x,y);
//			printf("ret=%d\n",ret);
//			break;
//		case 2:
//			printf("������Ҫ�����ֵ>:");
//			scanf("%d %d", &x, &y);
//			ret=Sub(x,y);
//			printf("ret=%d\n", ret);
//			break;
//		case 3:
//			printf("������Ҫ�����ֵ>:");
//			scanf("%d %d", &x, &y);
//			ret = Mul(x, y);
//			printf("ret=%d\n", ret);
//			break;
//		case 4:
//			printf("������Ҫ�����ֵ>:");
//			scanf("%d %d", &x, &y);
//			ret=Div(x, y);
//			printf("ret=%d\n", ret);
//			break;
//		case 0:
//			printf("�˳�����");
//			break;
//		default :
//				printf("�����������������\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}




//��ָ������ʵ��
//int main()
//{
//	int x;
//	int y;
//	int ret;
//	int input;
//	int(*Parr[5])(int, int) = { NULL,Add,Sub,Mul,Div };
//	do
//	{
//		menu();
//		printf("��ѡ��>:");
//		scanf("%d", &input);
//		if(input>=1&&input<=4)
//		{
//		printf("������Ҫ�����ֵ>:");
//		scanf("%d %d", &x, &y);
//		ret = (Parr[input])(x,y);
//		printf("ret=%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�˳�����");
//			break;
//		}
//		else
//		{
//			printf("�����������������\n");
//		}
//		
//	} while (input);
//	return 0;
//}



//�ûص�����ʵ��
int Calc(int(*pf)(int x, int y))
{
	int x;
	int y;
	printf("������Ҫ�����ֵ>:");
	scanf("%d %d", &x, &y);
	return pf(x, y);
}
int main()
{

	int ret;
	int input;
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			ret = Calc(Add);
			printf("ret=%d\n", ret);
			break;
		case 2:
			ret = Calc(Sub);
			printf("ret=%d\n", ret);
			break;
		case 3:
			ret = Calc(Mul);
			printf("ret=%d\n", ret);
			break;
		case 4:
			ret = Calc(Div);
			printf("ret=%d\n", ret);
			break;
		case 0:
			printf("�˳�����");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}