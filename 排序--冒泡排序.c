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
{//�������ڱȽ�
	int i,j,temp,flag = 0;
	for(i = 0;i < maxSize-1;++i)
	{
		flag = 0;
		for(j = maxSize-1;j > i;--j)
		{
			//�ǵݼ�  ��Ѵ�ķź���ȥ   ��ÿ��ѡȡһ�����ķ������    ���ÿ��ѡȡ��С�ķ�ǰ�棬���ܻᵼ��һ��������С�����ŵ��ܺ���
			if(a[j] < a[j-1])
			{
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
				flag = 1;
			}
		}
		if(flag == 0)
			break;
	}
}