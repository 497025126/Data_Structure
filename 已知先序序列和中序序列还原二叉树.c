#include<stdio.h>
#include<malloc.h>
#define maxSize 7
typedef struct node
{
	char c;
	struct node *lC,*rC;
}Tree,*pTree;

char Pre[maxSize] = "ABDECF";
char Mid[maxSize] = "BDEACF";
int nowIndex = 0;

pTree Creat(pTree tree,char *p2,int l,int r);
int FindIndex(char *p,char c);
void PreTreaverse(pTree p);
int main(void)
{
	Tree tree;
	Creat(&tree,Mid,0,5);//������֪������������Ѷ�����������������ǰ�����
	PreTreaverse(&tree);
	putchar('\n');
	return 0;
}

pTree Creat(pTree tree,char *p2,int l,int r)
{
	int i;
	i = FindIndex(p2,Pre[nowIndex]);//�ҵ���ǰ��ĸ�������е��±�
	tree->c =  Pre[nowIndex];
	if(i > l)//��i����߽������ҵ�ǰ��ĸ����һ������
	{
		++nowIndex;
		tree->lC = Creat((pTree)malloc(sizeof(Tree)),p2,l,i-1);
	}
	else//��С����û�����ӡ���ͬ
		tree->lC = NULL;
	if(i < r)
	{
		++nowIndex;
		tree->rC = Creat((pTree)malloc(sizeof(Tree)),p2,i+1,r);
	}
	else
		tree->rC = NULL;
	return tree;
}

int FindIndex(char *p,char c)
{
	int i = 0;
	while(p[i] != '\0')
		if(p[i] == c)
			return i;
		else
			++i;
	return -1;
}

void PreTreaverse(pTree p)
{
	if(p!= NULL)
	{
		printf("%c",p->c);
		if(p->lC)
			PreTreaverse(p->lC);
		if(p->rC)
			PreTreaverse(p->rC);
	}
}