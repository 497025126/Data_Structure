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

void Sort(int *arr)
{
	int i,j;
	int low = 1,high = 1,mid,temp;
	for(i = 1;i < maxSize;++i)
	{
		//����i��λ���ϵ������뵽һ���Ѿ��ź����������  �ǵݼ�
		temp = arr[i];
		low = 0,high = i-1;
		while(low <= high)
		{
			mid = (low+high)/2;
			if(arr[mid] > arr[i])//�����  ���Ҫȥ��ǰ��
			{
				high = mid-1;
			}
			else if(arr[mid] < arr[i])
				low = mid+1;
			else
				break;
		}
		//mid����Ҫ�ŵ�λ��
		for(j = i-1;j>=high+1;--j)
			arr[j+1] = arr[j];
		arr[high+1] = temp;
	}
}