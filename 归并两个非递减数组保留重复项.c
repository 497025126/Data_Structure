#include<stdio.h>
#define M 15
#define N 8
int Count = 0;
void GuiBing(int *,int *,int *);
void GuiBing2(int *,int*,int*);

void Print(int *,int ,char * );
void Init(int *,int );
int main(void)
{
	int a[M],b[N],c[M+N],i;
	srand((unsigned)time(NULL));
	//���������ǵݼ�����
	Init(a,M);
	Init(b,N);
	Print(a,M,"A");
	Print(b,N,"B");

	GuiBing(a,b,c);
	Print(c,M+N,"��ȥ�ع鲢��");
	Count = 0;

	GuiBing2(a,b,c);
	Print(c,Count,"ȥ�ع鲢���");
	printf("��ȥ�س���Ӧ��Ϊ%d������Ϊ%d\n",M+N,Count);
	return 0;
}
void Print(int *a,int len,char *name)
{
	int i = 0;
	printf("%s����Ϊ��",name);
	for(i = 0;i < len;i++)
		printf("%3d ",*(a+i));
	printf("\n");
}
void Init(int *a,int len)
{
	int i = 0;
	for(i = 0;i < len;i++)
		if(0 == i)
			a[i] = rand()%45;
		else
			//a[i] = a[i-1]+rand()%10;
			a[i] = a[i-1]+rand()%10+1;
}
void GuiBing(int *A,int *B,int *C)
{
	int aI=0,bI=0,cI = 0;//�ж����������Ƿ����
	int aLen =M,bLen = N;
	for(;aI < aLen || bI < bLen;)
	{
		if(aI < aLen && bI < bLen)
		{
			if(*(A+aI) < *(B+bI))
				*(C+cI++) = *(A+aI++);
			else
				*(C+cI++) = *(B+bI++);
		}
		else if(aI < aLen)
			*(C+cI++) = *(A+aI++);
		else
			*(C+cI++) = *(B+bI++);
	}
}


//�鲢ab���鵽c��ȥ���ظ��ġ�
void GuiBing2(int *A,int *B,int *C)
{
	int aI = 0,bI = 0;
	for(;aI < M || bI < N;)
	{
		if(aI < M && bI < N)
		{
			if(A[aI] < B[bI])
				C[Count++] = A[aI++];
			else if(A[aI] > B[bI])
				C[Count++] = B[bI++];
			else
				C[Count++] = B[bI++],aI++;
		}
		else if(aI < M)
			C[Count++] = A[aI++];
		else
			C[Count++] = B[bI++];
	}
}