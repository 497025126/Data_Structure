#include<stdio.h>
#include<malloc.h>
#define maxSize 20
typedef struct node
{
	char c;
	struct node *lC,*rC;
}Tree,*pTree;

pTree PreGetValue(pTree p);
int DiGui(pTree p,char c,int *i);//�ݹ������ڲ�
int NotDiGui(pTree p,char c);//�ǵݹ������ڲ�

int main(void)
{
	int ceil = 1;
	Tree tree;// ABD##E##CF###
	PreGetValue(&tree);
	ceil = DiGui(&tree,'F',&ceil);
	printf("%d\n",ceil);
	ceil = NotDiGui(&tree,'C');
	printf("%d\n",ceil);
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
int DiGui(pTree p,char c,int *i)
{
	int temp = *i,item = temp;
	if(p)
	{
		if(p->c == c)//����ˣ�ֱ�ӷ��ص�ǰ�����Ŀ
			return temp;
		else
		{
			//��������������������������i��ֵ  ÿ�ν�ȥ����iֵ��1��ÿ�γ�������iֵ��1����Ϊ�����ȣ����ᵽ��1����������ˣ�֤���϶������
			if(p->lC)
			{
				(*i)++;
				item = DiGui(p->lC,c,i);
				if(item != temp)
					return item;
			}
			if(p->rC)
			{
				(*i)++;
				item = DiGui(p->rC,c,i);
				if(item != temp)
					return item;
			}
		}
	}
	else
		(*i)--;
	return --(*i);
}
int NotDiGui(pTree p,char c)
{
	pTree A[maxSize],temp,flag = p;
	int top = -1;
	int nowCeil = 1;
	A[++top] = p;
	while(top != -1)
	{
		temp = A[top--];
		if(temp->c == c)
			return nowCeil;
		if(temp == flag)
			nowCeil++;
		if(temp->lC)
		{
			A[++top] = temp->lC;
			flag = temp->lC;
		}
		if(temp->rC)
		{
			A[++top] = temp->rC;
			flag = temp->rC;
		}
	}
	return -1;
}