#include<stdio.h>
#include<malloc.h>
#define maxSize 5
typedef struct node
{
	int data;
	struct node *lC,*rC,*parent;
}Tree,*pTree;

int Find(int *,int *,int *);
int IsOver(int *);
pTree Creat(pTree p,int *num);
void PreTreaverse(pTree p);
int GetValue(pTree p);


int main(void)
{
	int num[maxSize] = {2,5,7,9,13},sum = 0;
	Tree tree;
	Creat(&tree,num);
	PreTreaverse(&tree);
	putchar('\n');
	sum = GetValue(&tree);
	printf("��Ȩ·������Ϊ��%d\n",sum);
	return 0;
}

int Find(int *num,int *a,int *b)
{
	int i = 0,j = 32768,k = 32768;
	*a = *b = -1;
	for(i = 0;i < maxSize;++i)
	{
		//�ҵ���С�ķŵ�a��ڶ�С�ķŵ�b����
		if(num[i] != 32768)
		{
			if(num[i] <= j)
			{
				*b = *a;
				*a = i;
				k = j;
				j = num[i];
			}
			else if(num[i] <= k)
			{
				*b = i;
				k = num[i];
			}
		}
	}
	return 1; 
}
int IsOver(int *num)
{
	//�ж��Ƿ��Ѿ������ˡ���������������Ҫ�������,���ֻ��һ���ˣ�ֱ�ӷ��������±�
	int i = 0,flag = -1;
	for(i = 0;i < maxSize;++i)
		if(num[i] != 32768)
			if(flag == -1)
				flag = i;
			else
				return maxSize+1;
	if(flag != -1)
		return flag;
	else
		return -1;
}
pTree Creat(pTree p,int *num)
{
	pTree p1,p2,p3;
	int temp = IsOver(num);
	pTree flag[maxSize] = {NULL};
	int a = 0,b = 0;
	//�������������ʱ��֤����ʱ������ֻʣ���һ���ڵ��ˣ�������ڵ�������ĸ��ڵ�
	while(temp == maxSize + 1)
	{
		//����Ҫ�������
		Find(num,&a,&b);
		//���������ڵ㣬������ԭ����ֵ��һ������Ͻڵ��ֵ�����������ֵ�޸�һ��
		//����Ӧλ�����Ѿ��нڵ��ˣ��Ͳ������ˣ�ֱ�ӵ���
		p1 = (pTree)malloc(sizeof(Tree));
		if(flag[a] != NULL)//��Ӧ���Ǹ��������Ѿ������ˣ���Ϊ�ϳɵĽڵ㣩����ֱ���ó����ã�������������һ��
			p2 = flag[a];
		else
		{
			p2 = (pTree)malloc(sizeof(Tree));
			p2->lC = p2->rC = NULL;
			flag[a] =  p1;
		}
		if(flag[b] != NULL)
			p3 = flag[b];
		else
		{
			p3 = (pTree)malloc(sizeof(Tree));
			p3->lC = p3->rC = NULL;//��Ϊ�¹����Ҷ�ӽڵ㣬����Ҫ������ָ����NULL  ����տ�ʼ��ûע�⣬ȫ����NULL��
			flag[b] = p1;
		}
		//���½ڵ�����
		p2->data = num[a];
		p2->parent = p1;
		p3->data = num[b];
		
		p3->parent = p1;
		p1->data = num[a]+num[b];
		p1->lC = p2;
		p1->rC = p3;
		p1->parent = NULL;
		num[a] = p1->data;
		num[b] = 32768;
		temp = IsOver(num);
	}
	//��ʱtemp���������һ�����ڵ���±꣬flag[temp]�򱣴����Ǹ��ڵ����Ϣ�����ǽ������ĸ��ڵ㻻����
	p->data = p1->data;
	p->lC = p1->lC;
	p->rC = p1->rC;
	p->parent = NULL;
	free(p1);
	return p;
}
void PreTreaverse(pTree p)
{
	if(p)
	{
		printf("%3d",p->data);
		PreTreaverse(p->lC);
		PreTreaverse(p->rC);
	}
}

int GetValue(pTree p)
{//��α�������Ҷ�ӽڵ���������ԣ���ǰ����-1��
	int sum = 0;
	pTree queue[3*maxSize],lastNode = p,temp = p;
	int front = 0,rear = 0;
	int nowCeil = 1;
	if(temp == NULL)
		return 0;
	queue[rear++] = temp;
	while(rear != front)
	{
		temp = queue[front++];//ÿ��ȡ��һ��
		if(temp->lC == NULL && temp->rC == NULL)//�����Ҷ�ӽڵ��ˣ�ֱ�Ӱ��Լ���Ȩֵ���ԣ�·�����ȼ�һ��
			sum = sum + temp->data*(nowCeil-1);
		if(temp->lC)
		{
			queue[rear++] = temp->lC;
		}
		if(temp->rC)
		{
			queue[rear++] = temp->rC;
		}
		if(temp == lastNode)//���ҵ���ǰ������һ��Ԫ��ʱ�����²�������ʹ���µ����Ԫ��ָ�����β��
		{
			nowCeil++;
			lastNode = queue[rear-1];
		}
	}
	return sum;
}