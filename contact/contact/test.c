#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


//1��ͨѶ¼���Դ��1000���˵���Ϣ��
//2��ÿ���˵���Ϣ�ǣ�
//�������Ա����䡢�绰����ַ
//3�������˵���Ϣ
//4��ɾ���˵���Ϣ
//5���޸��˵���Ϣ
//6������
//7������

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
	Contact con ;//ͨѶ¼
	InitContact(&con);//��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d",&input);
		switch(input)
		{
		case ADD://����
			AddContact(&con);
			break;
		case DEL://ɾ��
			DeleteContact(&con);//ɾ��������Ϣ
			break;
		case SEARCH://����
			SearchContact(&con);//�����ֲ���
			break;
		case MODIFY://�޸�
			MosifyCotact(&con);//�޸���Ϣ
			break;
		case SORT://����
			SortContact(&con);
			break;
		case FRINT://��ӡ
			PrintContact(&con);//��ӡͨѶ¼
			break;
		case EXIT://�˳�
			SaveContact(&con);//�����ļ�
			DestoryContact(&con);//����ͨѶ¼
			printf("�˳�ͨѶ¼!\n");
			break;
		default:
			printf("����������������:\n");
		}
	} while (input);

	return 0;
}