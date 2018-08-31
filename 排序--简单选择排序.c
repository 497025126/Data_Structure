#include<stdio.h>
#define maxSize 8
void Sort(int *);
void Print(int * arr,char info[]);
int main(void)
{
	int num[maxSize] = {49,38,65,97,76,13,27,49};
	Print(num,"ԭ����Ϊ��");
	Sort(num);
	Print(num,"�����Ϊ��");
	return 0;
}

void Print(int *arr,char info[])
{
	int i;
	printf("%s",info);
	for(i = 0;i < maxSize;++i)
		printf("%3d",arr[i]);
	putchar('\n');
}

void Sort(int *a)
{
	int i,j,k,temp;
	for(i = 0;i < maxSize-1;++i)
	{
		k = i;
		for(j = i+1;j < maxSize;++j)
		{
			if(a[j] < a[k])
				k = j;
		}
		temp = a[k];
		a[k] = a[i];
		a[i] = temp;
	}
}