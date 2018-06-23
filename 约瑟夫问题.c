#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
}Node;

Node * Create(int );
void Treaverse(Node *);
void Kill(Node *,int);
void Kill_02(Node *);


int main(void)
{
	int n,m = 3;
	Node * myNode;
	printf("������������:");
	scanf("%d",&n);
	myNode = Create(n);
	Treaverse(myNode);
	//Kill(myNode,m);
	Kill_02(myNode);
	return 0;
}

Node * Create(int n)
{
	int i;
	Node* pHead = (Node*)malloc(sizeof(Node)),*s,*p;
	
	p = pHead;
	for(i=0;i<n;i++)
	{
		s = (Node*)malloc(sizeof(Node));
		s->data = i+1;
		p->next = s;
		p = s;
	}
	s->next = pHead->next;
	free(pHead);
	return s->next;
	
}

void Treaverse(Node * myNode)
{
	Node * pHead = myNode;
	Node * next = myNode;
	printf("�������Ϊ��");
	while(next->next != pHead)
	{
		printf("%d->",next->data);
		next = next->next;
	}
	printf("%d\n",next->data);
}

void Kill(Node * myNode,int m)
{
	Node * nowNode = myNode;
	Node* temp;
	int i;
	printf("����˳��Ϊ��");
	while(nowNode->next->next != nowNode)
	{
		//forѭ���ƶ�ָ�롣ѭ����ɾ��
		for(i = 0;i < m-2;i++)
		{
			nowNode = nowNode->next;
		}
		//��ʱ��nowNode��Ҫɾ���Ľڵ�ǰһ���ڵ�
		temp = nowNode->next->next;
		printf("%d->",nowNode->next->data);
		free(nowNode->next);
		nowNode->next = temp;
		nowNode = temp;
	}
	printf("%d->%d\n",nowNode->data,nowNode->next->data);
	free(nowNode->next);
	free(nowNode);
}

void Kill_02(Node * myNode)
{
	int m,i;
	Node* nowNode = myNode;
	Node* temp;
	m = 3;
	printf("����˳��Ϊ��");
	while(nowNode->next->next != nowNode)
	{
		for(i = 0;i < m-2;i++)
		{
			nowNode = nowNode->next;
		}
		temp = nowNode->next->next;
		m = nowNode->next->data;
		printf("%d->",nowNode->next->data);
		free(nowNode->next);
		nowNode->next = temp;
		nowNode = temp;
	}
	printf("%d->%d\n",nowNode->data,nowNode->next->data);
	free(nowNode->next);
	free(nowNode);
}