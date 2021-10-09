#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void mnue()
{
	printf("*******************************\n");
	printf("*******     1.play      *******\n");
	printf("*******     0.exit      *******\n");
	printf("*******************************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };//存放布置雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查雷的信息 
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');//初始化为‘0’
	InitBoard(show, ROWS, COLS, '*');//初始化为‘*’
	//打印一下棋盘
	DisPlayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//排查雷
	FindMine(mine, show, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input;
	do
	{
		mnue();
		printf("请选择-->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("选择错误，请重新选择-->");
		}
	} while (input);
	return 0;
}