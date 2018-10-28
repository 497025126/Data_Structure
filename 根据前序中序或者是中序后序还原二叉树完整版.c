#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *lc;
	struct node *rc;
}Node;

int GetIndex(int *a,int value);
Node *GetTree(int *pre,int *mid,int *now,int l,int r);
Node *GetTree1(int *las,int *mid,int *now,int l,int r);
void MidTreaver(Node *p);
int main(void)
{
	int begin = 0,end = 7;
	int Pre[] = {12,9,7,11,35,21,54,43};
	int Mid[] = {7,9,11,12,21,35,43,54};
	int Las[] = {7,11,9,21,43,54,35,12};
	Node *p = NULL;
	p = GetTree(Pre,Mid,&begin,begin,end);
	//p = GetTree1(Las,Mid,&end,begin,end);
	MidTreaver(p);
	putchar('\n');
	return 0;
}

void MidTreaver(Node *p)
{
	Node *t;
	Node *stack[20];
	int top = -1;
	t = p;
	while(top != -1 || t)
	{
		while(t)
		{
			stack[++top] = t;
			t = t->lc;
		}
		if(top != -1)
		{
			t = stack[top--];
			printf("%3d",t->data);
			t = t->rc;
		}
	}
}
int GetIndex(int *a,int value)
{
	//���ȱ�֤�����ֵ�϶����������������������ֵ����ͬ
	int i = 0;
	while(a[i] != value)
		++i;
	return i;
}
Node *GetTree(int *pre,int *mid,int *now,int l,int r)
{
	//��l < r  �������ڴ����ֵ������ֱ������ΪNULL
	Node *p = NULL;
	int k = 0;
	if(l <= r)
	{
		p = (Node *)malloc(sizeof(Node));//����һ���ڵ� ��Ϊ���ڵ�
		p->data = pre[*now];
		k = GetIndex(mid,pre[*now]);//��ȡǰ���е�ǰλ�õ�ֵ��������ĸ�λ��
		//�������������now++
		//��ô�ж���û���������أ�
		if(k > l)
			*now = *now +1,p->lc = GetTree(pre,mid,now,l,k-1);
		else
			p->lc = NULL;
		if(k < r)
			*now = *now +1,p->rc = GetTree(pre,mid,now,k+1,r);
		else
			p->rc = NULL;
	}
	return p;
}
Node *GetTree1(int *las,int *mid,int *now,int l,int r)
{
	int k;
	Node *p = NULL;
	if(l <= r)
	{
		p = (Node *)malloc(sizeof(Node));
		p->data = las[*now];
		k = GetIndex(mid,las[*now]);
		if(k < r)
			*now -= 1,p->rc = GetTree1(las,mid,now,k+1,r);
		else
			p->rc = NULL;
		if(k > l)
			*now -= 1,p->lc = GetTree1(las,mid,now,l,k-1);
		else
			p->lc = NULL;
	}
	return p;
}