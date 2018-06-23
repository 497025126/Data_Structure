#include<stdio.h>
#include<malloc.h>
//�ȹ���һ���ַ�ջ���������洦������е�����
//����һ���ַ���������������������ɣ�()[]  �����Ƿ�Ϸ�

typedef struct Node
{
	char c;
	struct Node * next;
}NODE;

typedef struct Stack
{
	NODE * top;
	NODE * button;
}STACK;

void init(STACK *);
void push(STACK *,char);
char pop(STACK *);
int isEmpty(STACK *);
int calculate(char *);

int main(void)
{
	int result = 0;
	char zifu[50];
	scanf("%s",zifu);
	result = calculate(zifu);
	if(1 == result)
		printf("�Ϸ�\n");
	else 
		printf("���Ϸ�\n");
	return 0;
}

void init(STACK * pS)
{
	pS->top = (NODE *)malloc(sizeof(NODE));
	pS->button = pS->top;
	pS->top->next = NULL;
}


void push(STACK * pS,char c)
{
	NODE * temp = (NODE *)malloc(sizeof(NODE));
	temp->c = c;
	temp->next = pS->top;
	pS->top = temp;
}


int isEmpty(STACK * pS)
{
	if(pS->top == pS->button)
		return 1;
	else 
		return 0;
}


char pop(STACK * pS)
{
	char c;
	if(1 == isEmpty(pS))
		return '#';
	else
	{
		c = pS->top->c;
		pS->top = pS->top->next;
	}
	return c;
}

int calculate(char *str)
{
	char *s = str,c,c1;
	STACK S;
	init(&S);
	c = *s;
	while(c != '\0')
	{
		//�ж�c��ʲô���͵����ţ�����������ţ����׳�һ�������ж��Ƿ�ƥ��
		if(c == '(' || c == '[')
		{
			push(&S,c);
		}
		else if(c == ')')
		{
			c1 = pop(&S);
			if(c1 != '(')
				return 0;
		}
		else if(c == ']')
		{
			c1 = pop(&S);
			if(c1 != '[')
				return 0;
		}
		else 
			return 0;
		s++;
		c = *s;
	}
	if(1 == isEmpty(&S))
		return 1;
	return 0;
}
