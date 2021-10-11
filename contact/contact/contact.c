#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//void InitContact(Contact*pc)//��ʼ����̬ͨѶ¼
//{
//	memset(pc->deat,0,sizeof(pc->deat));
//	pc->sz = 0;
//}

void InitContact(Contact*pc)//��ʼ����̬ͨѶ¼
{
	pc->deat=(Peoinfo*)calloc(DEFAULT_SZ,sizeof(Peoinfo));//���ٶ�̬��ͨѶ¼������ʼ��Ϊ0
	if (pc->deat == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	//��ȡ�ļ���Ϣ��ͨѶ¼
	loadContact(pc);
}
void loadContact(Contact*pc)//��ȡ�ļ���Ϣ��ͨѶ¼
{
	FILE* pf = fopen("contact.dat", "r");//��ȡ�ļ��е���Ϣ
	if (pf == NULL)
	{
		perror("loadContact");
		return;
	}
	//���ļ�
	Peoinfo tmp = { 0 };
	while (fread(&tmp, sizeof(Peoinfo), 1, pf))
	{
		CheckCapacity(pc);//�������
		pc->deat[pc->sz] = tmp;
		pc->sz++;
	}
	//�ر��ļ�
	fclose(pf);
}

void CheckCapacity(Contact*pc)//����
{
	if (pc->sz == pc->capacity)
	{
		Peoinfo*ret = (Peoinfo*)realloc(pc->deat, (pc->capacity + INC_SZ) * sizeof(Peoinfo));
		if (ret == NULL)
		{
			perror("AddContact");
			printf("����ʧ�ܣ������ϵ��ʧ�ܣ�\n");
			return;
		}
		else
		{
			pc->deat = ret;
			pc->capacity += INC_SZ;
			printf("���ݳɹ���\n");
		}
	}
}

//��̬-������ϵ��
//void AddContact(Contact*pc)//�����˵���Ϣ
//{
//	if (pc->sz == MAX)
//	{
//		printf("ͨѶ¼�������޷������Ϣ��\n");
//		return ;
//	}
//	printf("����������:>");
//	scanf("%s",pc->deat[pc->sz].name);
//	printf("�������Ա�:>");
//	scanf("%s",pc->deat[pc->sz].sex);
//	printf("����������:>");
//	scanf("%d", &(pc->deat[pc->sz].age));
//	printf("������绰:>");
//	scanf("%s", pc->deat[pc->sz].tele);
//	printf("�������ַ:>");
//	scanf("%s", pc->deat[pc->sz].addr);
//	pc->sz++;
//	printf("��ӳɹ�\n");
//}

//��̬--������ϵ��
void AddContact(Contact*pc)//�����˵���Ϣ
{
	//����
	CheckCapacity(pc);
	//�����ϵ��
	printf("����������:>");
	scanf("%s", pc->deat[pc->sz].name);
	printf("�������Ա�:>");
	scanf("%s", pc->deat[pc->sz].sex);
	printf("����������:>");
	scanf("%d", &(pc->deat[pc->sz].age));
	printf("������绰:>");
	scanf("%s", pc->deat[pc->sz].tele);
	printf("�������ַ:>");
	scanf("%s", pc->deat[pc->sz].addr);
	pc->sz++;
	printf("��ӳɹ�\n");
}


void SaveContact(Contact*pc)//�����ļ�
{
	FILE* pf=fopen("contact.dat", "w");//���ļ�
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}
	//д�ļ�
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->deat + i, sizeof(Peoinfo),1,pf);
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}


void DestoryContact(Contact*pc)//����ͨѶ¼
{
	free(pc->deat);
	pc->deat = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}

void PrintContact(const Contact*pc)//��ӡͨѶ¼
{
	printf("%-10s\t%-10s\t%-10s\t%-15s\t%-20s\t\n","����","�Ա�","����","�绰","��ַ");
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
static int FindByContact(Contact*pc)//����
{
	int i = 0;
	char name[MAX_NAME];
	scanf("%s", &name);
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->deat[i].name, name) == 0)
		{
			return i;//�ҵ��ˣ��±�Ϊi
		}
	}
	return -1;//�Ҳ���
}
void SearchContact(Contact*pc)//�����ֲ���
{
	printf("������Ҫ���ҵ�����:>");
	int pos=FindByContact(pc);//����
	 if (pos< 0)
	{
	printf("���ҵ��˲�����\n");
	}
	else 
	{
		 printf("%-10s\t%-10s\t%-10s\t%-15s\t%-20s\t\n", "����", "�Ա�", "����", "�绰", "��ַ"); 
		 printf("%-10s\t%-10s\t%-10d\t%-15s\t%-20s\t\n",
				 pc->deat[pos].name,
				 pc->deat[pos].sex,
				 pc->deat[pos].age,
				 pc->deat[pos].tele,
				 pc->deat[pos].addr);
	}
}

void DeleteContact(Contact*pc)//ɾ��������Ϣ
{
	printf("������Ҫɾ��������:>");
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ɾ��\n");
		return;
	}
	int pos = FindByContact(pc);//����
	if (pos== -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
		int i = 0;
		for (i = pos; i < pc->sz - 1; i++)
		{
			pc->deat[i] = pc->deat[i + 1];
		}
		pc->sz--;
	printf("ɾ���ɹ���\n");
}
void MosifyCotact(Contact*pc)//�޸���Ϣ
{
	printf("������Ҫ�޸��˵�����:>");
	int pos=FindByContact(pc);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����");
	}

	printf("����������:>");
	scanf("%s", pc->deat[pos].name);
	printf("�������Ա�:>");
	scanf("%s", pc->deat[pos].sex);
	printf("����������:>");
	scanf("%d", &(pc->deat[pos].age));
	printf("������绰:>");
	scanf("%s", pc->deat[pos].tele);
	printf("�������ַ:>");
	scanf("%s", pc->deat[pos].addr);
	printf("�޸ĳɹ���\n");
}

void SortContact(Contact*pc)//��ͨѶ¼��������
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
	printf("����ɹ���\n");
}