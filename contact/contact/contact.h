#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX 1000
#define DEFAULT_SZ 3//初始时通讯录容量
#define INC_SZ 2//每次扩容增加的容量


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

//静态通讯录开辟
//typedef struct Contact
//{
//	Peoinfo deat[MAX];//创建通讯录
//	int sz;//通讯录中有几个元素
//}Contact;

//动态通讯录开辟
typedef struct Contact
{
	Peoinfo * deat;//创建通讯录
	int sz;//通讯录中有几个元素
	int capacity;//通讯录容量
}Contact;

void InitContact(Contact*pc);//初始化通讯录
void AddContact(Contact*pc);//增加人的信息
void PrintContact(const Contact*pc);//打印通讯录
void SearchContact(Contact*pc);//按名字查找
void DeleteContact(Contact*pc);//删除个人信息
void MosifyCotact(Contact*pc);//修改信息
void SortContact(Contact*pc);//对通讯录进行排序
void DestoryContact(Contact*pc);//销毁通讯录
void SaveContact(Contact*pc);//保存文件
void loadContact(Contact*pc);//读取文件信息到通讯录
void CheckCapacity(Contact*pc);//扩容


