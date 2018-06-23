#include<stdio.h>
#include<stdlib.h>


typedef struct treeNode
{
	char data;
	struct treeNode * lChild;
	struct treeNode * rChild;
}TreeNode,*pTreeNode;


pTreeNode CreatStaticTree(void);
void PreTraverseTree(pTreeNode );//ǰ�����
void MiddleTraverseTree(pTreeNode );//�������
void LastTraverseTree(pTreeNode );//��������

int main(void)
{
	pTreeNode myTree = CreatStaticTree();
	PreTraverseTree(myTree);
	putchar('\n');
	MiddleTraverseTree(myTree);
	putchar('\n');
	LastTraverseTree(myTree);
	putchar('\n');
	return 0;
}


pTreeNode CreatStaticTree()
{
	pTreeNode pA = (pTreeNode)malloc(sizeof(TreeNode));
	pTreeNode pB = (pTreeNode)malloc(sizeof(TreeNode));
	pTreeNode pC = (pTreeNode)malloc(sizeof(TreeNode));
	pTreeNode pD = (pTreeNode)malloc(sizeof(TreeNode));
	pTreeNode pE = (pTreeNode)malloc(sizeof(TreeNode));
	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';
	pA->lChild = pB;
	pA->rChild = pC;
	pB->lChild = pB->rChild = NULL;
	pC->lChild = pD;
	pC->rChild = NULL;
	pD->lChild = NULL;
	pD->rChild = pE;
	pE->lChild = pE->rChild = NULL;
	return pA;
}

void PreTraverseTree(pTreeNode pTree)
{//���ڵݹ�ǳ��˷��ڴ棬Ҳ�����������ڵ���֮ǰ���ж�һ��
	if(pTree != NULL)
	{
		printf("%c ",pTree->data);
		if(NULL != pTree->lChild)
			PreTraverseTree(pTree->lChild);
		if(NULL != pTree->rChild)
			PreTraverseTree(pTree->rChild);
		/*
		printf("%c ",pTree->data);
		PreTraverseTree(pTree->lChild);
		PreTraverseTree(pTree->rChild);
		*/
	}

	//�ȴ�ӡ���ڵ㣬�ٴ�ӡ��ڵ㣬�ٴ�ӡ�ҽڵ�
	/*
	if(pTree != NULL)
	{
		printf("%c ",pTree->data);
	}
	if(pTree->lChild != NULL)
	{
		PreTraverseTree(pTree->lChild);
	}
	if(pTree->rChild != NULL)
	{
		PreTraverseTree(pTree->rChild);
	}
	*/
}

void MiddleTraverseTree(pTreeNode pTree)
{
	if(pTree != NULL)
	{
		MiddleTraverseTree(pTree->lChild);
		printf("%c ",pTree->data);
		MiddleTraverseTree(pTree->rChild);
	}
	/*
	//�ȴ�ӡ�������������м�ڵ㣬����������
	if(pTree->lChild != NULL)
	{
		MiddleTraverseTree(pTree->lChild);
	}
	printf("%c ",pTree->data);
	if(pTree->rChild != NULL)
	{
		MiddleTraverseTree(pTree->rChild);
	}
	*/
}

void LastTraverseTree(pTreeNode pTree)
{
	//����ڵ㣬���ҽڵ㣬�ٸ��ڵ�

	if(pTree != NULL)
	{
		LastTraverseTree(pTree->lChild);
		LastTraverseTree(pTree->rChild);
		printf("%c ",pTree->data);
	}
	/*
	if(pTree->lChild != NULL)
	{
		LastTraverseTree(pTree->lChild);
	}
	if(pTree->rChild != NULL)
	{
		LastTraverseTree(pTree->rChild);
	}
	putchar(pTree->data);
	putchar(' ');
	*/
}