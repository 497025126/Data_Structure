#include<stdio.h>
int Zong = 0;

void transport(int count,char start,char temp,char end)
{
	/*
	��start�ϵ�n�����ӽ���temp�ƶ���end��
	���ֻʣ��һ��
		ֱ�Ӵ�start���ƶ���end��
	����
		�Ƚ�start�ϵ�n-1�����ӽ���end�ƶ���temp
		�ٽ�1������ֱ�Ӵ�start�ƶ���end
		���temp�ϵ�n-1�����ӽ���start�ƶ���end��
	*/
	if(1 == count)
	{
		Zong++;
		printf("�����Ϊ%d�����Ӵ�%c�����Ƶ�%c����\n",count,start,end);
	}
	else
	{
		transport(count-1,start,end,temp);
		Zong++;
		printf("�����Ϊ%d�����Ӵ�%c�����Ƶ�%c����\n",count,start,end);
		transport(count-1,temp,start,end);
	}
}
int main(void)
{
	char start = 'A';
	char temp = 'B';
	char end  = 'C';
	int count;
	printf("�����뺺ŵ���ĸ�����");
	scanf("%d",&count);
	transport(count,start,temp,end);
	printf("�ܹ��ƶ���%d��\n",Zong);
	return 0;
}