#include<stdio.h>
#define maxSize 50
int Test(char *);//ʵ��һ�����ŵ�ƥ��
int main(void)
{
	int flag = -1;
	char info[maxSize];
	gets(info);
	flag = Test(info);
	if(flag == -1)
		puts("�����޷�ƥ��");
	else
		puts("���ſ���ƥ��");
	return 0;
}

int Test(char *s)
{
	int i = 0;
	int num = 0;//�����������ž�++��������������--����;С��0ֱ�ӷ���-1  �������������0Ҳ����-1
	while(s[i] != '\0')
	{
		if(s[i] == '(')
			++num;
		else if(s[i] == ')')
		{
			if(num == 0)
				return -1;
			else
				--num;	
		}
		++i;
	}
	if(num != 0)
		return -1;
	else
		return 1;
}