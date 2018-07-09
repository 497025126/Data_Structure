//2018��7��9�� 20:31:35
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *prior;
	struct node *next;
}BNODETP;

BNODETP * Init();
void Fuzhi(BNODETP* pHead);
void Treaverse(BNODETP *L,char *info);
void unknown(BNODETP *L);


int main(void)
{
	BNODETP * pHead = NULL;
	pHead = Init();
	Fuzhi(pHead);
	Treaverse(pHead,"δ���������Ϊ��");
	unknown(pHead);
	Treaverse(pHead,"����������Ϊ��");
	return 0;
}


BNODETP * Init()
{
	BNODETP * pHead = (BNODETP *)malloc(sizeof(BNODETP));
	pHead->next = pHead;
	pHead->prior = pHead;
	return pHead;
}

void Fuzhi(BNODETP* pHead)
{
	int value = 0;
	BNODETP *p = pHead,*q;
	printf("������������Ҫ��ȡ�����ݣ�����32768��������");
	scanf("%d",&value);
	while(value!=32768)
	{
		q = (BNODETP *)malloc(sizeof(BNODETP));
		q->data = value;
		q->prior = p;
		q->next = pHead;
		p->next = q;
		p = q;
		scanf("%d",&value);
	}
	pHead->prior = p;
}
void Treaverse(BNODETP *L,char *info)
{
	BNODETP *p = L->next;
	if(L == NULL)
		return ;
	else
		printf("%s",info);
	while(p != L)
	{
		printf("%3d ",p->data);
		p = p->next;
	}
	putchar('\n');
}

void unknown(BNODETP *L)
{
	BNODETP *p,*q,*r;
	p = L->next;
	q = p->next;
	r = q->next;
	while(q!=L)
	{
		while((p!=L) && (p->data>q->data))
		{
			p = p->prior;
		}//���ǲ������򣬴�β����ͷ�����Һ��ʵ�λ��
		q->prior->next = r;//�ȰѴ�����Ľڵ��ǰһ���ڵ����������ĺ�һ���ڵ�
		r->prior = q->prior;//1���Ѵ�����ڵ�ĺ�һ���ڵ�ǰָ����ָ���Լ���ǰһ���ڵ�
		q->next = p->next;//���Լ��ĺ�ָ����ָ��Ҫ�����λ���ϵĽڵ�ĺ�һ���ڵ㣬
		q->prior = p;//���Լ�ǰָ����ָ��Ҫ�����λ���ϵĽڵ�
		p->next->prior=q;//2����Ҫ�����λ���ϵĽڵ��һ���ڵ�ǰָ����ָ���Լ�
		p->next=q;//3����Ҫ�����λ���ϵĽڵ��ָ����ָ���Լ�
		q = r;
		p = q->prior;
		r = q->next;//4����rָ��q�ĺ���һ���ڵ�
	}
}