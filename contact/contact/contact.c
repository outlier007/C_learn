#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//void InitContact(Contact*pc)//初始化静态通讯录
//{
//	memset(pc->deat,0,sizeof(pc->deat));
//	pc->sz = 0;
//}

void InitContact(Contact*pc)//初始化动态通讯录
{
	pc->deat=(Peoinfo*)calloc(DEFAULT_SZ,sizeof(Peoinfo));//开辟动态的通讯录，并初始化为0
	if (pc->deat == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	//读取文件信息到通讯录
	loadContact(pc);
}
void loadContact(Contact*pc)//读取文件信息到通讯录
{
	FILE* pf = fopen("contact.dat", "r");//读取文件中的信息
	if (pf == NULL)
	{
		perror("loadContact");
		return;
	}
	//读文件
	Peoinfo tmp = { 0 };
	while (fread(&tmp, sizeof(Peoinfo), 1, pf))
	{
		CheckCapacity(pc);//检测容量
		pc->deat[pc->sz] = tmp;
		pc->sz++;
	}
	//关闭文件
	fclose(pf);
}

void CheckCapacity(Contact*pc)//扩容
{
	if (pc->sz == pc->capacity)
	{
		Peoinfo*ret = (Peoinfo*)realloc(pc->deat, (pc->capacity + INC_SZ) * sizeof(Peoinfo));
		if (ret == NULL)
		{
			perror("AddContact");
			printf("扩容失败！添加联系人失败！\n");
			return;
		}
		else
		{
			pc->deat = ret;
			pc->capacity += INC_SZ;
			printf("扩容成功！\n");
		}
	}
}

//静态-增加联系人
//void AddContact(Contact*pc)//增加人的信息
//{
//	if (pc->sz == MAX)
//	{
//		printf("通讯录已满，无法存放信息！\n");
//		return ;
//	}
//	printf("请输入性名:>");
//	scanf("%s",pc->deat[pc->sz].name);
//	printf("请输入性别:>");
//	scanf("%s",pc->deat[pc->sz].sex);
//	printf("请输入年龄:>");
//	scanf("%d", &(pc->deat[pc->sz].age));
//	printf("请输入电话:>");
//	scanf("%s", pc->deat[pc->sz].tele);
//	printf("请输入地址:>");
//	scanf("%s", pc->deat[pc->sz].addr);
//	pc->sz++;
//	printf("添加成功\n");
//}

//动态--增加联系人
void AddContact(Contact*pc)//增加人的信息
{
	//扩容
	CheckCapacity(pc);
	//添加联系人
	printf("请输入性名:>");
	scanf("%s", pc->deat[pc->sz].name);
	printf("请输入性别:>");
	scanf("%s", pc->deat[pc->sz].sex);
	printf("请输入年龄:>");
	scanf("%d", &(pc->deat[pc->sz].age));
	printf("请输入电话:>");
	scanf("%s", pc->deat[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->deat[pc->sz].addr);
	pc->sz++;
	printf("添加成功\n");
}


void SaveContact(Contact*pc)//保存文件
{
	FILE* pf=fopen("contact.dat", "w");//打开文件
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}
	//写文件
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->deat + i, sizeof(Peoinfo),1,pf);
	}
	//关闭文件
	fclose(pf);
	pf = NULL;
}


void DestoryContact(Contact*pc)//销毁通讯录
{
	free(pc->deat);
	pc->deat = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}

void PrintContact(const Contact*pc)//打印通讯录
{
	printf("%-10s\t%-10s\t%-10s\t%-15s\t%-20s\t\n","姓名","性别","年龄","电话","地址");
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-10s\t%-10d\t%-15s\t%-20s\t\n",
			pc->deat[i].name,
			pc->deat[i].sex,
			pc->deat[i].age,
			pc->deat[i].tele,
			pc->deat[i].addr);
	}
}
static int FindByContact(Contact*pc)//查找
{
	int i = 0;
	char name[MAX_NAME];
	scanf("%s", &name);
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->deat[i].name, name) == 0)
		{
			return i;//找到了，下标为i
		}
	}
	return -1;//找不到
}
void SearchContact(Contact*pc)//按名字查找
{
	printf("请输入要查找的姓名:>");
	int pos=FindByContact(pc);//查找
	 if (pos< 0)
	{
	printf("查找的人不存在\n");
	}
	else 
	{
		 printf("%-10s\t%-10s\t%-10s\t%-15s\t%-20s\t\n", "姓名", "性别", "年龄", "电话", "地址"); 
		 printf("%-10s\t%-10s\t%-10d\t%-15s\t%-20s\t\n",
				 pc->deat[pos].name,
				 pc->deat[pos].sex,
				 pc->deat[pos].age,
				 pc->deat[pos].tele,
				 pc->deat[pos].addr);
	}
}

void DeleteContact(Contact*pc)//删除个人信息
{
	printf("请输入要删除的姓名:>");
	if (pc->sz == 0)
	{
		printf("通讯录为空，无需删除\n");
		return;
	}
	int pos = FindByContact(pc);//查找
	if (pos== -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
		int i = 0;
		for (i = pos; i < pc->sz - 1; i++)
		{
			pc->deat[i] = pc->deat[i + 1];
		}
		pc->sz--;
	printf("删除成功！\n");
}
void MosifyCotact(Contact*pc)//修改信息
{
	printf("请输入要修改人的姓名:>");
	int pos=FindByContact(pc);
	if (pos == -1)
	{
		printf("要修改的人不存在");
	}

	printf("请输入性名:>");
	scanf("%s", pc->deat[pos].name);
	printf("请输入性别:>");
	scanf("%s", pc->deat[pos].sex);
	printf("请输入年龄:>");
	scanf("%d", &(pc->deat[pos].age));
	printf("请输入电话:>");
	scanf("%s", pc->deat[pos].tele);
	printf("请输入地址:>");
	scanf("%s", pc->deat[pos].addr);
	printf("修改成功！\n");
}

void SortContact(Contact*pc)//对通讯录进行排序
{
	int j = 0;
		for (j = 0; j < pc->sz - j - 1; j++)
		{
			if (strcmp(pc->deat[j].name, pc->deat[j+ 1].name) > 0)
			{
				Peoinfo tmp = pc->deat[j];
				pc->deat[j] = pc->deat[j + 1];
				pc->deat[j + 1] = tmp;
			}
		}
	printf("排序成功！\n");
}