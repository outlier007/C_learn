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
	char mine[ROWS][COLS] = { 0 };//��Ų����׵���Ϣ
	char show[ROWS][COLS] = { 0 };//����Ų��׵���Ϣ 
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');//��ʼ��Ϊ��0��
	InitBoard(show, ROWS, COLS, '*');//��ʼ��Ϊ��*��
	//��ӡһ������
	DisPlayBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	//�Ų���
	FindMine(mine, show, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input;
	do
	{
		mnue();
		printf("��ѡ��-->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("ѡ�����������ѡ��-->");
		}
	} while (input);
	return 0;
}