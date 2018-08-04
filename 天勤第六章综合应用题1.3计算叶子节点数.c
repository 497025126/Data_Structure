#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char c;
	struct node *lC,*rC;
}Tree,*pTree;

pTree PreGetValue(pTree p);
int CalculateLeafNum(pTree p);



int main(void)
{
	Tree tree;// ABD##E##CF###
	int count = 0;
	PreGetValue(&tree);
	count = CalculateLeafNum(&tree);
	printf("��%d��Ҷ�ӽڵ�\n",count);
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
int CalculateLeafNum(pTree p)
{//��Ҷ�ӽڵ��������������Ҷ�ӽڵ������������Ҷ�ӽڵ����
	int l = 0,r = 0;
	if(p == NULL)//���Ϊ�գ������Ϊ0
		return 0;
	else
	{//������������Һ��Ӷ�û�У����Լ�ΪҶ�ڵ㣬����1  ���򣬱������Һ���  Ҳ�����жϲ����ٱ���������ע��Ҫ��ʼ��Ϊ0
		if(p->lC == NULL && p->rC == NULL)
			return 1;
		else
		{
			l = CalculateLeafNum(p->lC);
			r = CalculateLeafNum(p->rC);
		}
	}
	return l+r;
}