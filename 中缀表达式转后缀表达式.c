#include<stdio.h>
#include<struct.h>
int main(void)
{//9+(3-1)*3+8/2  
	char input[100] = {'\0'},c,temp;
	int i;
	PCS p = InitC();
	scanf("%s",input);
	for(i = 0;(c = input[i]) != '\0';++i)
	{
		if(c>='0' && c<= '9')
			putchar(c);
		else
		{
			//�жϵ�ǰ������ջ���������ȼ����Լ���
			if(c == '(')
				PushC(p,c);
			else if(c == ')')
			{
				while((c = PopC(p))!='(')
					putchar(c);
			}
			else
			{
				//�ж��Լ���ջ���������ȼ�ǿ�������Լ�����������������ջ������Լ���ջ
				if(EmptyC(p))//����ǿ�ջ��ֱ����ջ
					PushC(p,c);
				else 
				{
					temp = GetC(p);
					if((c == '*'||c == '/') && (temp == '+'|| temp == '-'))
						PushC(p,c);
					else if(temp == '(')
						PushC(p,c);
					else
					{
						temp = PopC(p);
						putchar(temp);
						PushC(p,c);
					}
				}
			}
		}
	}
	while((c = PopC(p)) != '\0')
		putchar(c);
	putchar('\n');
	return 0;
}