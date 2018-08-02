#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char c;
	int lTag,rTag;
	struct node *lC,*rC;
}Tree,*pTree;
#define maxSize 50
pTree Pre = NULL;

void Init(pTree p);
pTree PreGetValue(pTree p);
void LastPrint(pTree p);


void MidLine(pTree);//�ݹ�����������
void MidLines(pTree);//��װ�˵ݹ������������������������˵ݹ鵽�����Ǹ�ָ��
void MidLinePrint1(pTree);//�����������������1��
void MidLinePrint2(pTree);//�����������������2��


void PreLineZiXie(pTree);//�Լ�����д��
void PreLine(pTree);//�ο����
void PreLines(pTree);//��װ���Լ�д�ġ�
void PreLinePrint(pTree);//ǰ�����������

void LastLine(pTree);
void LastLinePrint(pTree);
pTree GetNext(pTree,pTree);
pTree FindPar(pTree,pTree);


int main(void)
{// ABD##E##CF###
	Tree tree;
	Init(&tree);
	PreGetValue(&tree);
	LastPrint(&tree);//�����������������������ȷ��
	putchar('\n');

	//����������
	//MidLines(&tree);
	//putchar('\n');
	//MidLinePrint1(&tree);
	//putchar('\n');
	//MidLinePrint2(&tree);
	//putchar('\n');

	//ǰ��������
	//PreLine(&tree);   //PreLines(&tree);  //�����ú������ַ���
	//PreLinePrint(&tree);
	//putchar('\n');

	LastLine(&tree);
	//printf("%c",FindPar(&tree,(&tree)->lC->lC)->c);
	LastLinePrint(&tree);
	return 0;
}
void Init(pTree p)
{
	p->c = '\0';
	p->lC = p->rC = NULL;
	p->lTag = p->rTag = 0;
}

pTree PreGetValue(pTree p)
{
	char c;
	pTree temp;
	c = getchar();
	if(c != '#')
	{
		p->lTag = p->rTag = 0;
		p->c = c;
		temp = (pTree)malloc(sizeof(Tree));
		p->lC = PreGetValue(temp);
		temp = (pTree)malloc(sizeof(Tree));
		p->rC = PreGetValue(temp);
	}
	else
		p = NULL;
	return p;
}

void LastPrint(pTree p)
{
	pTree A[maxSize];
	int top = -1;
	int B[maxSize] = {0};
	while(p != NULL || top != -1)
	{
		while(p)
		{
			A[++top] = p;
			B[top] = 0;
			p = p->lC;
		}
		if(top != -1)
		{
			p = A[top];
			if(B[top] == 0)
			{
				B[top] = 1;
				p = p->rC;
			}
			else if(B[top] == 1)
			{
				top--;
				putchar(p->c);
				p = NULL;
			}
			
		}
	}
}

void MidLine(pTree p)
{
	if(p != NULL)
	{
		MidLine(p->lC);
		if(p->lC == NULL)
		{
			p->lTag = 1;
			p->lC = Pre;
		}
		if(Pre != NULL && Pre->rC == NULL)
		{
			Pre->rC = p;
			Pre->rTag = 1;
		}
		Pre = p;
		putchar(p->c);
		MidLine(p->rC);
	}
}
void MidLines(pTree p)
{
	if(p)
	{
		MidLine(p);//��������ɺ󣬴���һ�����һ���ڵ�
		Pre->rTag = 1;
		Pre->rC =  NULL;
	}
}
void MidLinePrint1(pTree p)
{
	while(p)
	{//������ڵ�ָ����Ǻ��ӣ���������ң�֪���ҵ��Ǹ����Ǻ��ӵģ���ʱ�Լ�ΪҪ����Ľڵ�
		while(p->lTag == 0)
			p = p->lC;
		putchar(p->c);//����Լ����Һ�����ָ��ֱ�Ӻ�̵ģ��������ֱ��ת����ֱ�Ӻ��.���Լ��ұ���ָ���ӵ�ʱ������ȥ��������p
		while(p->rTag == 1 && p->rC != NULL)
		{
			p = p->rC;
			putchar(p->c);
		}
		p = p->rC;	//��ͷ�������Լ��������
	}
}
void MidLinePrint2(pTree p)
{
	if(!p)
		return ;
	while(p->lTag == 0)//��õ�һ��Ҫ����Ľڵ�
		p = p->lC;
	while(p)
	{
		putchar(p->c);//�����ǰ�ڵ��ֵ��
		if(p->rTag == 1)//�����ָ��ֱ�Ӻ�̣�ֱ�Ӹ��¾�����
			p = p->rC;
		else//������ǣ��ҵ������
		{
			p = p->rC;
			while(p->lTag == 0)
				p = p->lC;
		}
	}
}
//�Լ�д��ǰ���������ݹ����
void PreLineZiXie(pTree p)
{
	if(p)
	{
		if(p->lC != NULL)
		{
			if(Pre != NULL && Pre->rC == NULL)
			{
				Pre->rTag  = 1;
				Pre->rC = p;
			}
			Pre =  p;
			p->lTag = 0;
			PreLineZiXie(p->lC);			
		}
		else
		{
			p->lC = Pre;
			p->lTag = 1;
			if(Pre != NULL && Pre->rC == NULL)
			{
				Pre->rTag = 1;
				Pre->rC = p;
			}
			Pre = p;	
		}
		if(p->rTag == 0 && p->rC != NULL)
		{
			p->rTag =  0;
			PreLineZiXie(p->rC);
		}
		else
		{
			if(p->lTag == 0)
			{
				p->rC = p->lC;
				p->rTag = 0;
			}
		}
	}
}
void PreLine(pTree p)
{
	if(p)
	{
		if(p->lC == NULL)
		{
			p->lTag = 1;
			p->lC = Pre;
		}//������ǰ��ڵ�
		if(Pre != NULL && Pre->rC == NULL)
		{
			Pre->rC = p;
			Pre->rTag = 1;
		}
		Pre = p;
		if(p->lTag != 1)
			PreLine(p->lC);
		if(p->rTag != 1)
			PreLine(p->rC);
	}
}
void PreLines(pTree p)
{
	if(p)
	{
		PreLineZiXie(p);
		Pre->rTag = 1;
		Pre->rC = NULL;
	}
}
void PreLinePrint(pTree p)
{
	while(p)
	{
		putchar(p->c);
		while(p->lTag == 0)
		{
			p = p->lC;
			putchar(p->c);
		}
		p = p->rC;
	}
}

void LastLine(pTree p)
{
	if(p)
	{
		LastLine(p->lC);
		LastLine(p->rC);
		//putchar(p->c);
		if(p->lC == NULL)
		{
			p->lC = Pre;
			p->lTag = 1;
		}
		if(Pre != NULL && Pre->rC == NULL)
		{
			Pre->rC = p;
			Pre->rTag = 1;
		}
		Pre = p;
	}
}
pTree GetNext(pTree p1,pTree p2)
{
	pTree temp;
	if(p1 == p2)//�Ǹ��ڵ㣬û��ֱ�Ӻ��
		return NULL;
	else
	{
		if(p2->rTag == 1)
			return p2->rC;
		//�ҵ����ڵ�  �ж���û��������
		temp = FindPar(p1,p2);
		if(temp != NULL && temp->rC == NULL)
			;
		else if(temp != NULL && temp->rC != NULL)//���ڵ������������ҵ��������������µ���һ���ڵ�
		{
			temp = temp->rC;//�����߻��У��ͼ���
			while(temp->lTag == 0)
				temp =  temp->lC;
		}
		return temp;
	}
}
pTree FindPar(pTree p,pTree p2)
{
	pTree temp = NULL;
	if(p)
	{
		if(p->lTag == 0 && p->lC == p2)
		{
			temp = p;
		}
		if(temp != NULL)
			return temp;
		if(p->lTag == 0)
			temp = FindPar(p->lC,p2);
		if(p->rTag == 0)
			if(temp == NULL)
				FindPar(p->rC,p2);
	}
	return temp;
}
void LastLinePrint(pTree p)
{
	pTree temp = p;
	while(temp->lTag == 0)
			temp = temp->lC;
	while(temp)
	{
		putchar(temp->c);
		temp = GetNext(p,temp);
	}
}
