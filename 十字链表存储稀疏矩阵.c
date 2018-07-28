#include<stdio.h>
#include<malloc.h>
#define M 4
#define N 4
typedef struct OLNode
{
	int row,col;
	struct OLNode *right,*down;
	float val;
}OLNode;
typedef struct
{
	OLNode *rhead,*chead;
	int m,n,k;//�С��С�����Ԫ
}CrossList;

void Init(CrossList *T);
void Print(CrossList *T);
int Create(float A[][N],int m,int n,int k,CrossList *T);
int main(void)
{
	float num[M][N] = {
		{0,0,0,1},
		{0,0,3,2},
		{1,0,0,0},
		{0,2,0,0}
	};
	CrossList T;
	Init(&T);
	Create(num,M,N,5,&T);
	Print(&T);
	return 0;
}

void Init(CrossList *T)
{
	T->rhead = T->chead = NULL;
	T->m = T->n = T->k = 0;
}
void Print(CrossList *T)
{
	OLNode *p = NULL;
	int i = 0,j = 0;
	for(i = 0;i < M;++i)
	{
		p = &(T->rhead[i]);
		for(j = 0;j < N;++j)
		{//��ǰ�е�pָ��Ĳ�Ϊ�գ����ұ��Ǹ��ڵ��б����j���������������p
			if(p->right != NULL && p->right->col == j)
			{//%.0������ĸ�ʽ��0λС��
				printf("%.0f ",T->rhead[i].right->val);
				p = p->right;
			}
			else//������ζ����0
				printf("%.0f ",0);
		}
		printf("\n");
	}
}
int Create(float A[][N],int m,int n,int k,CrossList *T)
{
	int i,j;
	OLNode *c = NULL,*p = NULL;
	OLNode *temp[N];//��������ָ������
	if(!(T->rhead = (OLNode*)malloc(sizeof(OLNode)*M)))
		return 0;
	if(!(T->chead = (OLNode*)malloc(sizeof(OLNode)*N)))
		return 0;
	//�Ƚ�ͷ�ڵ�right�����down�����ÿ�
	for(i = 0;i < M;++i)
	{
		T->rhead[i].right = NULL;
		T->rhead[i].down = NULL;
	}
	for(i = 0;i < N;++i)
	{
		T->chead[i].right = NULL;
		T->chead[i].down = NULL;
	}	
	for(i = 0;i < N;++i)
		temp[i] = &(T->chead[i]);
	for(i = 0;i < M;++i)
	{
		c = &T->rhead[i];
		for(j = 0;j < N;++j)
		{
			if(A[i][j] != 0)
			{//����һ���½ڵ㲢��ֵ��ʹ�Ҳ�ڵ���ϲ�ڵ�ָ�������������Ҳ�ڵ���ϲ�ڵ㡣
				T->k++;
				p = (OLNode *)malloc(sizeof(OLNode));
				p->row = i;
				p->col = j;
				p->val = A[i][j];
				p->down = p->right = NULL;
				c->right = p;
				c = p;
				temp[j]->down = p;
				temp[j] = p;
			}
		}
	}
	return 1;
}