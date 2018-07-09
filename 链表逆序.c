//��ͷ�ڵ�ĵ��������򣬽����󷵻�ͷ�ڵ㣬ͷ�ڵ�ָ�������ĵ�һ���ڵ�
//��ʼ��һ����ͷ�ڵ������
/*
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node* next;
}Node;

Node* Init();//��ʼ��������
void Fuzhi(Node *pHead);
void Treaverse(Node * pHead,char *info);
Node* Inverse(Node * pHead);

int main(void)
{
	Node* pHead = Init();
	Fuzhi(pHead);
	Treaverse(pHead,"����ǰ����������Ϊ��");
	pHead = Inverse(pHead);
	Treaverse(pHead,"��������������Ϊ��");
	return 0;
}

Node* Init()
{
	Node* pHead = (Node*)malloc(sizeof(Node));
	pHead->next = NULL;
	return pHead;
}

void Fuzhi(Node *pHead)
{
	int value = 0;
	Node* p = pHead,*q;
	printf("������������Ҫ��ȡ�����ݣ�����32768��������");
	scanf("%d",&value);
	while(value!=32768)
	{
		q = (Node*)malloc(sizeof(Node));
		q->data = value;
		p->next =  q;
		p = q;
		scanf("%d",&value);
	}
	p->next = NULL;
}
void Treaverse(Node * pHead,char *info)
{
	Node* p = pHead->next;
	if(p != NULL)
		printf("%s",info);
	while(p!=NULL)
	{
		printf("%3d ",p->data);
		p = p->next;
	}
	putchar('\n');
}

Node* Inverse(Node * pHead)
{
	Node *p= pHead->next,*q = NULL;
	while(p!=NULL)
	{
		pHead->next = p;
		p = p->next;
		pHead->next->next = q;
		q = pHead->next;
	}
	return pHead;
}
*/

//���򲻴�ͷ�ڵ�ĵ����������󷵻������ĵ�һ���ڵ�ָ��
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node * next;
}Node;

Node* Fuzhi(Node *pHead);
void Treaverse(Node * pHead,char *info);
Node* Inverse(Node * pHead);


int main(void)
{
	Node* pHead = NULL;
	pHead = Fuzhi(pHead);
	
	Treaverse(pHead,"����ǰ����������Ϊ��");
	pHead = Inverse(pHead);
	Treaverse(pHead,"��������������Ϊ��");
	return 0;
}

Node* Fuzhi(Node* pHead)
{
	int value = 0;
	Node* p = pHead,*q;
	printf("������������Ҫ��ȡ�����ݣ�����32768��������");
	scanf("%d",&value);
	while(value!=32768)
	{
		if(pHead == NULL)
		{//���Ϊ�գ��򴴽�һ���ڵ㱣��ֵ����ʹָ��pҲָ������ڵ�
			pHead = (Node*)malloc(sizeof(Node));
			pHead->data = value;
			p = pHead;
		}
		else
		{//����һ���µĽڵ㣬��ʹpָ������ڵ�
			q = (Node*)malloc(sizeof(Node));
			q->data = value;
			p->next = q;
			p = q;
		}
		scanf("%d",&value);
	}
	p->next = NULL;
	return pHead;
}

void Treaverse(Node * pHead,char *info)
{
	Node* p = pHead;
	if(p != NULL)
		printf("%s",info);
	while(p!=NULL)
	{
		printf("%3d ",p->data);
		p = p->next;
	}
	puts("");
}

Node* Inverse(Node * pHead)
{
	Node* p ,*q = NULL;
	if(pHead == NULL)
		return pHead;
	p = pHead->next;
	while(p!=NULL)
	{
		pHead->next = q;
		q = pHead;
		pHead = p;
		p = p->next;
	}
	pHead->next = q;
	return pHead;
}