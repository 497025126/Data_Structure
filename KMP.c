#include<stdio.h>
#include<string.h>
int Calculate(char *target,char *match);
void GetNext(char *info,int *next);
int main(void)
{
	char target[100],match[20];
	int flag = -1;
	gets(target);
	gets(match);
	flag = Calculate(target,match);
	if(-1 == flag)
		printf("û����Ŀ�괮���ҵ����Ӵ���\n");
	else
		printf("��Ŀ�괮���ҵ����Ӵ���λ��%d��λ��\n",flag);
	return 0;
}
int Calculate(char *target,char *match)
{
	int len1,len2;
	int i = 0,j = 0;
	int next[21];
	len1 = strlen(target);
	len2 = strlen(match);
	GetNext(match,next);
	while(i < len1 && j < len2)
	{
		//�˴�j���ж�������Ҫ����next�����ֵ��ͬ
		if(j == -1 || target[i] == match[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];	
		}
	}
	if(j == len2)//����ĩβ�˳�����
		return i - len2;
	else
		return -1;
}
void GetNext(char *info,int *next)
{
	int i = 0,j = -1;//j�ĳ�ֵ��next��һ��ֵ��ͬ��iҪ��j��һ���ұ������next[i]�ĳ�ֵ
	int len = strlen(info);
	next[0] = -1;
	while(i < len)
	{
		if(j == -1 || info[j] == info[i])
		{
			++i;
			++j;
			//�Ľ� //�����������ʧ���ʱ��Ӧ�û�����λ�ã����Ǽ�Ȼ������ȣ������Ǹ�λ�ÿ϶�Ҳ�Ǵ���ģ�����ֱ�ӻ����Ǹ�λ�ñ����λ��
			if(info[i]==info[j])
				next[i] = next[j];
			else
				next[i] = j;
		}
		else
			j = next[j];
	}
	for(i = 0;i < len;++i)
		printf("%d",next[i]);
	putchar('\n');
}