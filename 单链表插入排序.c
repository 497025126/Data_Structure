//1800�����Ա������30��
//�Ե�����Ԫ�ذ����뷽������
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}linknode,*link;

link Init();//��ʼ��������
void Fuzhi(link pHead);
void Treaverse(link pHead,char *info);
void Insertsort(link L);

int main(void)
{
	link pHead = Init();
	Fuzhi(pHead);
	Treaverse(pHead,"����ǰ����������Ϊ��");
	Insertsort(pHead);
	Treaverse(pHead,"��������������Ϊ��");
	return 0;
}

link Init()
{
	link pHead = (link)malloc(sizeof(linknode));
	pHead->next = NULL;
	return pHead;
}

void Fuzhi(link pHead)
{
	int value = 0;
	link p = pHead,q;
	printf("������������Ҫ��ȡ�����ݣ�����32768��������");
	scanf("%d",&value);
	while(value!=32768)
	{
		q = (link)malloc(sizeof(linknode));
		q->data = value;
		p->next =  q;
		p = q;
		scanf("%d",&value);
	}
	p->next = NULL;
}

void Treaverse(link pHead,char *info)
{
	link p = pHead->next;
	if(p != NULL)
		printf("%s",info);
	while(p!=NULL)
	{
		printf("%3d ",p->data);
		p = p->next;
	}
	putchar('\n');
}

void Insertsort(link L)
{
	link p,q,r,u;
	p = L->next;
	L->next = NULL;
	while(p!=NULL)
	{
		r = L;
		q = L->next;
		while(q!=NULL && q!=p && q->data <= p->data)
		{
			r = q;
			q = q->next;
		}
		u = p->next;
		p->next =  r->next;
		r->next = p;
		p = u;
	}
}
