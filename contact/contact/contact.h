#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX 1000
#define DEFAULT_SZ 3//��ʼʱͨѶ¼����
#define INC_SZ 2//ÿ���������ӵ�����


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Peoinfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}Peoinfo;

//��̬ͨѶ¼����
//typedef struct Contact
//{
//	Peoinfo deat[MAX];//����ͨѶ¼
//	int sz;//ͨѶ¼���м���Ԫ��
//}Contact;

//��̬ͨѶ¼����
typedef struct Contact
{
	Peoinfo * deat;//����ͨѶ¼
	int sz;//ͨѶ¼���м���Ԫ��
	int capacity;//ͨѶ¼����
}Contact;

void InitContact(Contact*pc);//��ʼ��ͨѶ¼
void AddContact(Contact*pc);//�����˵���Ϣ
void PrintContact(const Contact*pc);//��ӡͨѶ¼
void SearchContact(Contact*pc);//�����ֲ���
void DeleteContact(Contact*pc);//ɾ��������Ϣ
void MosifyCotact(Contact*pc);//�޸���Ϣ
void SortContact(Contact*pc);//��ͨѶ¼��������
void DestoryContact(Contact*pc);//����ͨѶ¼
void SaveContact(Contact*pc);//�����ļ�
void loadContact(Contact*pc);//��ȡ�ļ���Ϣ��ͨѶ¼
void CheckCapacity(Contact*pc);//����


