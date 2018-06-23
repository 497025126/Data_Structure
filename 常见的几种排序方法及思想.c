//ð������  һ��һ���������α�֤ǰ����ʣ�µ���������
//��������  ͨ��ĳ�ַ��������ν�����һ�����ݲ嵽ǰ�����ݵ�ĳ��λ�ã���֤ǰ������������ġ�
//ѡ������  ͨ��ĳ�ַ������Ӻ����������ѡ��һ�����������͵�һ�����������ٴӺ���������У�ѡ��һ������������ڶ�����������
//��������
//�鲢����  ������������  ���ĸ��ĸ���  �ٰ˸��˸���
#include<stdio.h>

//��������
void QuickSort(int* ,int ,int );
int FindPos(int* ,int ,int );

//ð������
void MaoPaoSort(int *,int );

//��������
void InsertSort(int* ,int);

//ѡ������
void SelectSort(int*,int);
int main(void)
{
	int a[6]  = {2,-6,0,7,3,4};
	int i = 0;
	//QuickSort(a,0,5);
	//MaoPaoSort(a,6);
	//InsertSort(a,6);
	SelectSort(a,6);

	for(i = 0;i < 6;i++)
		printf("%d ",a[i]);
	printf("\n");


	return 0;
}

void QuickSort(int* a,int low,int high)
{
	int pos;
	if(low < high)
	{
		//�ҵ�һ��λ�ã���ߵİ�ͬ�����㷨�ţ��ұ�Ҳ��ͬ�����㷨��
		pos = FindPos(a,low,high);
		QuickSort(a,low,pos-1);
		QuickSort(a,pos+1,high);
	}
}
int FindPos(int* a,int low,int high)
{
	int val = a[low];
	while(low<high)
	{
		while(low < high && a[high] >= val)
			high--;
		a[low] = a[high];
		while(low < high && a[low] <= val)
			low++;
		a[high] = a[low];
	}
	//�����λ���Ѿ����ˡ�
	a[low] = val;
	return low;
}


void MaoPaoSort(int* a,int len)
{
	int val;
	int i,j;
	for(i = 0;i < len-1;i++)
	{
		for(j = i+1;j < len;j++)
		{
			if(a[i] > a[j])
			{
				val = a[i];
				a[i] = a[j];
				a[j] = val;
			}
		}
	}
}

void InsertSort(int* a,int len)
{
	int i,j,val;
	for(j = 1;j < len;j++)
	{
		for(i = 0;i < j;i++)
		{
			if(a[j] < a[i])
			{
				val = a[j];
				a[j] = a[i];
				a[i] = val;
			}
		}
	}
}

void SelectSort(int* a,int len)
{
	int i,j,index,val;
	for(i = 0;i < len-1;i++)
	{
		for(j = index = i;j < len-1;j++)
		{
			//�ҵ�ʣ�µ��������(����С)�����±�
			if(a[j+1] < a[index])
				index = j+1;
		}
		val = a[i];
		a[i] = a[index];
		a[index] = val;
	}
}