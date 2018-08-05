#include<stdio.h>
#include<malloc.h>
#define maxSize 20
typedef struct node
{
	char c;
	struct node *lC,*rC;
}Tree,*pTree;
//˼·������һ��ջ������һ���ڵ��ѹջ������Ҷ�ӽڵ㣬�ʹ�ջ�ױ�����ջ��   ����һ���ڵ㷵�غ�Ӧ�ó�ջ
pTree stack[maxSize];
int top = 0;

void GetPath(pTree p);

pTree PreGetValue(pTree p);
int main(void)
{//   ABD##E##CF###
	Tree tree;
	PreGetValue(&tree);
	GetPath(&tree);
	return 0;
}

pTree PreGetValue(pTree p)
{
	char c;
	c = getchar();
	if(c != '#')
	{
		p->c = c;
		p->lC = PreGetValue((pTree)malloc(sizeof(Tree)));
		p->rC = PreGetValue((pTree)malloc(sizeof(Tree)));
	}
	else
		p = NULL;
	return p;
}

void GetPath(pTree p)
{
	int i = 0;
	if(p)
	{
		stack[top++] = p;
		if(p->lC == NULL && p->rC == NULL)
		{
			for(i = 0;i < top;++i)
				putchar(stack[i]->c);
			putchar('\n');
			//top--;//������ջ
			return ;
		}
		if(p->lC)
		{//�������ӣ��ű������ڽ�������ջ
			GetPath(p->lC);
			top--;
		}
		if(p->rC)
		{
			GetPath(p->rC);
			top--;
		}
	}
}