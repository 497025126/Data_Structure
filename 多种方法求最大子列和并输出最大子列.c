#include<stdio.h>
#define N 8
#define Inf -32768
int Num[N] = { 1, -2, 3, 10, -4, 7, 2, -5};
//int Num[N] = {-1,-1,-1,-1,-1,-1,-1,-1};
void Print(int *a,int bIndex,int eIndex,char *p);//��ӡ�����������ֱ�Ϊ��Ҫ��ӡ�������׵�ַ����ʼ�±꣬�����±꣬��ʾ��
void Baoli(int *a);//������ٷ�  ʱ�临�Ӷ�Ϊn^2
int FenZhi(int *a,int begin,int end);//���η�  
int FenXi(int *a);//������  p[i] = a[0]+a[1]+a[2]+...+a[i]  s[i,j] = p[j]-p[i-1]  �Ƚ�p[i]ȫ������������ҵ������Ǹ�����ȥ��С���Ǹ����ǽ��
int DongTaiGuiHua(int *a);//��̬�滮��  s[i]��ʾ��a[i]��β�������к�����һ��   s[0] = a[0]  s[i+1] = max(s[i],a[i+1])


int main(void)
{
	int i =  0;
	Print(Num,0,N-1,"ԭ����Ϊ��");
	Baoli(Num);
	printf("���η����������к�Ϊ��%d\n\n",FenZhi(Num,0,N-1));
	FenXi(Num);
	DongTaiGuiHua(Num);
	return 0;
}
void Print(int *a,int bIndex,int eIndex,char *p)
{
	printf("%s",p);
	for(;bIndex <= eIndex;bIndex++)
		printf("%3d ",*(a+bIndex));
	printf("\n");
}
void Baoli(int *a)
{
	int i,j,len = N;
	int begin=0,end=0,nowValue = 0,maxValue = Inf;
	for(i = 0;i < len;i++)
	{
		nowValue = 0;
		for(j = i;j < len;j++)
		{
			nowValue += *(a+j);
			if(nowValue >= maxValue)
			{
				maxValue = nowValue;
				begin = i;
				end = j;
			}
		}
	}
	Print(a,begin,end,"������ٷ�����õ����������Ϊ");
	printf("������к�Ϊ��%d\n\n",maxValue);
}

int FenZhi(int *a,int begin,int end)
{
	//������ֳ����Σ��ֱ������ߵ����͡��ұߵ������Լ���Խ���������
	int middle = (begin+end)/2;
	int leftValue,rightValue,kuaValue=0,maxLeft=Inf,maxRight=Inf;
	int i;
	if(begin == end)
		return *(a+begin);
	leftValue = FenZhi(a,begin,middle);
	rightValue = FenZhi(a,middle+1,end);
	//�����Խ��ֵʱ�����м������߼��㡣
	for(i = middle;i>=begin;i--)
	{
		kuaValue+=*(a+i);
		if(kuaValue >= maxLeft)
		{
			maxLeft = kuaValue;
		}
	}
	kuaValue = 0;
	for(i = middle+1;i <= end;i++)
	{
		kuaValue+=a[i];
		if(kuaValue >= maxRight)
		{
			maxRight = kuaValue;
		}
	}
	kuaValue = maxLeft+maxRight;
	//����leftValue��rightValue��kuaValue�нϴ��һ��
	return leftValue>rightValue?(leftValue>kuaValue?leftValue:kuaValue):(rightValue>kuaValue?rightValue:kuaValue);
}
int FenXi(int *a)
{
	int p[N],len = N;
	int i,minValue = 0,maxValue = Inf,temp;
	int leftIndex=0,rightIndex = 0;
	p[0] = a[0];
	for(i = 1;i < len;i++)//����p[i]
		p[i] = p[i-1]+a[i];
	//ѭ��������ʱʱ������Сֵ��ͬʱ�������ȥ�����ֵ
	for(i = 0;i < len;i++)
	{
		if(p[i] < minValue)
		{
			minValue = p[i];
			leftIndex = i+1;
		}
		temp = p[i] - minValue;
		if(temp > maxValue)
		{
			maxValue = temp;
			rightIndex = i;
		}
	}
	Print(a,leftIndex,rightIndex,"����������õ����������Ϊ");
	printf("������к�Ϊ��%d\n\n",maxValue);
}
int DongTaiGuiHua(int *a)
{
	int s[N];
	int i,maxValue=a[0],leftIndex=0,rightIndex=0,flag = 0;
	s[0] = a[0];
	for(i = 1;i < N;i++)
	{
		flag = 0;
		if(s[i-1]+a[i] >= a[i])
		{
			s[i] = s[i-1]+a[i];
		}
		else
		{
			flag = 1;//֤�����s[i]����Ҫ���������±��
			s[i] = a[i];
		}
		if(s[i] > maxValue)
		{
			maxValue = s[i];
			if(1 == flag)
				leftIndex = i;
			rightIndex = i;//ֻҪ��ǰ�����Ĵ����±��ǿ϶���Ҫ���õġ�
		}
	}
	Print(a,leftIndex,rightIndex,"��̬�滮������õ����������Ϊ");
	printf("������к�Ϊ��%d\n\n",maxValue);
}