#include<stdio.h>
#include<string.h>
#define maxSize 40
void Print(char *A,int l,int r);
int nowIndex = 0;
int main(void)
{
	int len = 0,i = 0;
	char array[maxSize+1] = "ABDECFG";
	len = strlen(array);
	for(i = 0;i < len;++i)
	{
		putchar(array[i]);
	}
	putchar('\n');
	Print(array,0,len-1);
	putchar('\n');
	for(i = 0;i < len;++i)
	{
		putchar(array[i]);
	}
	putchar('\n');
	return 0;
}

void Print(char *A,int l,int r)
{
	//˼·����lλΪ��ǰ�����ĸ��ڵ㣬��l+2 == r,ֱ�����l+1 �� l+2�ϵ�ֵ  �����l��ֵ�����򣬾���Print����ǰһ��ģ�����Print�����һ��ģ�������Լ�
	char t1 = A[l],t2 = A[l+1],t3 = A[l+2];
	if(l+2 == r)
	{
		A[nowIndex++] = t2;
		A[nowIndex++] = t3;
		A[nowIndex++] = t1;
		putchar(t2);
		putchar(t3);
		putchar(t1);
	}
	else
	{
		Print(A,l+1,(r-l)/2);
		Print(A,(r-l)/2+1,r);
		putchar(t1);
		A[nowIndex++] = t1;
	}
}