#include<stdio.h>
#define maxSize 50
void Test(char *);
int main(void)
{
	char info[maxSize+1];
	gets(info);
	printf("ԭ�ַ���Ϊ��%s\n",info);
	Test(info);
	printf("���ַ���Ϊ��%s\n",info);
	return 0;
}
void Test(char *s)
{
	int i = 0,k = 0;
	while(s[i]!='\0')
	{
		if(s[i] == ' ')
		{
			++k;//ͳ�ƿո����
		}
		++i;
	}
	while(i > 0 || k == 0)//�Ѿ���������Ҫ�滻�Ŀո�����Ѿ��滻����ʼλ��  ע����ʵֻҪ�ж�k���ɣ�ֻ��ϰ�����ж������Ƿ�ͷ
	{
		if(s[i] != ' ')
		{//�Ӻ���ǰɨ�裬�������ַ��ŵ���ȷ��λ�ã�����'\0'��
			s[i+k*2] = s[i];
		}
		else
		{//����ǿո��ˣ�����Ӧ������λ������ֵ��ͬʱk--
			s[i+k*2] = '0';
			s[i+k*2-1] = '2';
			s[i+k*2-2] = '%';
			--k;
		}
		--i;
	}
}