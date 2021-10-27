#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
	//Januay February  March April May June July August September October November December 
	char m1[10] = "Januay";
	char m2[10] = "February";
	char m3[10] = "March";
	char m4[10] = "April";
	char m5[10] = "May";
	char m6[10] = "June";
	char m7[10] = "July";
	char m8[10] = "August";
	char m9[10] = "September";
	char m10[10] = "October";
	char m11[10] = "November";
	char m12[10] = "December";
	//指针数组实现
    char * mo[13] = { 0,m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12 };
	int input = 0;
	
	while (scanf("%d", &input))
	{
		int sz = strlen(mo[input]);
		int i = 0;
		for (i = 0; i < sz; i++)
		{
			printf("%c", mo[input][i]);
		}
		printf("\n");
	}
	return 0;
}
