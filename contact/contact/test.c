#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


//1、通讯录可以存放1000个人的信息；
//2、每个人的信息是：
//姓名、性别、年龄、电话、地址
//3、增加人的信息
//4、删除人的信息
//5、修改人的信息
//6、查找
//7、排序

menu()
{
	printf("*****************************************\n");
	printf("********  1.ADD        2.DEL     ********\n");
	printf("********  3.SEARCH     4.MODIFY  ********\n");
	printf("********  5.SORT       6.PRINT   ********\n");
	printf("********  0.EXIT                 ********\n");
	printf("*****************************************\n");
}
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	FRINT,
};
int main()
{
	int input = 0;
	Contact con ;//通讯录
	InitContact(&con);//初始化通讯录
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d",&input);
		switch(input)
		{
		case ADD://增加
			AddContact(&con);
			break;
		case DEL://删除
			DeleteContact(&con);//删除个人信息
			break;
		case SEARCH://查找
			SearchContact(&con);//按名字查找
			break;
		case MODIFY://修改
			MosifyCotact(&con);//修改信息
			break;
		case SORT://排序
			SortContact(&con);
			break;
		case FRINT://打印
			PrintContact(&con);//打印通讯录
			break;
		case EXIT://退出
			SaveContact(&con);//保存文件
			DestoryContact(&con);//销毁通讯录
			printf("退出通讯录!\n");
			break;
		default:
			printf("输入错误，请从新输入:\n");
		}
	} while (input);

	return 0;
}