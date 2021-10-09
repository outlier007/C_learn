#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)//初始化棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisPlayBoard(char board[ROWS][COLS], int row, int col)//打印棋盘
{
	int i = 0;
	int j = 0;
	printf("-------------- 扫雷游戏 --------------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------- 扫雷游戏 --------------\n");
}
void SetMine(char mine[ROWS][COLS], int row, int col)//布置雷
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0');
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
static int get_mine_count(char mine[ROWS][COLS], int x, int y)//计算周围雷的数量
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//排查雷
{
	int x = 0;
	int y = 0;
	int win = 0;//排除的非雷格子数
	while (win < ROW*COL - EASY_COUNT)
	{
		printf("请输入要排查的坐标->:");//输入排查的坐标
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//判断坐标合法性
		{
			if (mine[x][y] == '0')//判断是否为雷
			{
				//不是雷，检查周围雷的情况
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				DisPlayBoard(show, ROW, COL);//打印棋盘信息，显示周围雷的个数
				win++;
			}
			else
			{
				printf("你个菜鸡，你被炸死了\n");//是雷
				DisPlayBoard(mine, row, col);
				break;
			}
		}
		else
			printf("输入坐标错误，请重新输入->:");
	}
	if (win == ROW * COL - EASY_COUNT)
	{
		printf("恭喜你！排雷成功！");
	}
}

