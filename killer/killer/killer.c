#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char killer = 0;
	for (killer = 'A'; killer <= 'D'; killer++)
	{      //  ����A               ��C               ��D               ����D
		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)
		{    //4��������3��Ϊ��1��Ϊ��
			printf("�����ǣ�%c", killer);
		}
	}
	return 0;
}


//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4��
//���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�