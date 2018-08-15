#include<stdio.h>
#include<malloc.h>
#define maxSize 20
#define Inf 32768
typedef struct ArcNode
{
	int adjVex;
	struct ArcNode *nextArc;
	int w;
}ArcNode;
typedef struct
{
	int data;
	ArcNode *firstArc;
}VNode;
typedef struct
{
	VNode adjList[maxSize];
	int e,n;
}AGraph;


typedef struct 
{
	int data;
}vertexType;

typedef struct
{
	vertexType vex[maxSize];
	int edges[maxSize][maxSize];
	int n,e;
}MGraph;


void CreateAGraph(AGraph *G);
void CreateMGraph(MGraph *G);
void Conversion(AGraph *AG,MGraph *MG);
void DFS(MGraph *MG,int v);

int main(void)
{
	AGraph AG;
	MGraph MG;
	CreateAGraph(&AG);
	Conversion(&AG,&MG);
	DFS(&MG,1);
	putchar('\n');
	return 0;
}



void CreateAGraph(AGraph *G)
{
	int i,j,k,w;
	ArcNode *p;
	scanf("%d%d",&G->n,&G->e);
	for(i = 0;i < G->n;++i)
	{
		scanf("%d",&G->adjList[i].data);//���붥����
		G->adjList[i].firstArc = NULL;//������ָ��ı��ÿ�
	}
	//�����
	for(i = 0;i < G->e;++i)
	{
		scanf("%d%d%d",&j,&k,&w);
		//j��kȨֵΪw
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->w = w;//Ȩֵ
		p->adjVex = k;
		p->nextArc = G->adjList[j].firstArc;
		G->adjList[j].firstArc = p;
	}
}

void CreateMGraph(MGraph *G)
{
	int i,j,k,w;
	scanf("%d%d",&G->n,&G->e);//����G�ı����͵���
	//��ʼ���ڽӾ���
	for(i = 0;i < G->n;++i)
		for(j = 0;j < G->n;++j)
		{
			G->edges[i][j] = Inf;
		}
	//ѭ������ÿ�������Ϣ
	for(i = 0;i < G->n;++i)
	{
		scanf("%d",&G->vex[i].data);
	}
	//ѭ������ÿ����
	for(i = 0;i < G->e;++i)
	{//�����������Լ����ǵ�Ȩֵ
		scanf("%d%d%d",&j,&k,&w);
		G->edges[j][k] = w;
		G->edges[k][j] = w;
	}
}

void Conversion(AGraph *AG,MGraph *MG)
{
	//��һ�����ڽӱ�ʽ�洢��ͼ���ڽӾ����
	int i = 0,k;
	ArcNode *p;
	MG->n = AG->n;
	MG->e = AG->e;
	for(i = 0;i < AG->n;++i)
		MG->vex[i].data = AG->adjList[i].data;
	for(i = 0;i < MG->n;++i)//��ʼ��Ȩֵ����
		for(k = 0;k < MG->n;++k)
			MG->edges[i][k] = Inf;
	for(i = 0;i < AG->n;++i)
	{
		p = AG->adjList[i].firstArc;
		while(p)
		{
			k = p->adjVex;//ȡ�ö�����
			MG->edges[i][k] = p->w;//ȡ��Ȩֵ
			p = p->nextArc;
		}
	}
}
void DFS(MGraph *MG,int v)
{
	int set[maxSize] = {0};
	int stack[maxSize];
	int top = -1,n,j = 0;
	set[v] = 1;
	stack[++top] = v;
	while(top != -1)
	{
		n = stack[top--];
		printf("%2d",n);
		for(j = 0;j < MG->n;++j)
		{
			if(set[j] == 0 && MG->edges[n][j]  != Inf)
			{
				set[j] = 1;
				stack[++top] = j;
			}
		}
	}
}

/*
7 12
0 1 2 3 4 5 6
0 1 4
0 2 6
0 3 6
1 2 1
1 4 7
2 4 6
2 5 4
3 2 2
3 5 5
4 6 6
5 4 1
5 6 8
*/
