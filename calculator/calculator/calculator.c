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
//		printf("请选择>:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入要运算的值>:");
//			scanf("%d %d", &x,&y);
//			ret=Add(x,y);
//			printf("ret=%d\n",ret);
//			break;
//		case 2:
//			printf("请输入要运算的值>:");
//			scanf("%d %d", &x, &y);
//			ret=Sub(x,y);
//			printf("ret=%d\n", ret);
//			break;
//		case 3:
//			printf("请输入要运算的值>:");
//			scanf("%d %d", &x, &y);
//			ret = Mul(x, y);
//			printf("ret=%d\n", ret);
//			break;
//		case 4:
//			printf("请输入要运算的值>:");
//			scanf("%d %d", &x, &y);
//			ret=Div(x, y);
//			printf("ret=%d\n", ret);
//			break;
//		case 0:
//			printf("退出程序");
//			break;
//		default :
//				printf("输入错误，请重新输入\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}




//用指针数组实现
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
//		printf("请选择>:");
//		scanf("%d", &input);
//		if(input>=1&&input<=4)
//		{
//		printf("请输入要运算的值>:");
//		scanf("%d %d", &x, &y);
//		ret = (Parr[input])(x,y);
//		printf("ret=%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出程序");
//			break;
//		}
//		else
//		{
//			printf("输入错误，请重新输入\n");
//		}
//		
//	} while (input);
//	return 0;
//}



//用回调函数实现
int Calc(int(*pf)(int x, int y))
{
	int x;
	int y;
	printf("请输入要运算的值>:");
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
		printf("请选择>:");
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
			printf("退出程序");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}