#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 100

//二叉树 三叉链表
typedef struct BinaryTree
{
	char data;
	struct BinaryTree* parent, * lchild, * rchild;
}BinaryTree, * pBinaryTree;

//队列
typedef struct Queue
{
	pBinaryTree data;
	struct Queue* next;
}Queue, * pQueue;

//队列指针
typedef struct
{
	pQueue front, rear;//头、尾指针
}LinkQueue;

//生成空树
int CreateBinaryTreeNULL(pBinaryTree* T)
{
	*T = NULL;
	return 1;
}

//销毁树
void DelBinaryTree(pBinaryTree* T)
{
	if (*T)
	{
		if ((*T)->lchild)
		{
			DelBinaryTree(&(*T)->lchild);
		}
		if ((*T)->rchild)
		{
			DelBinaryTree(&(*T)->rchild);
		}
		free(*T);
		*T = NULL; //防野
	}
}

//先序输入 无双亲指针的二叉树 完整的三叉列表需要调用这个函数
void CreateBinaryTree1(pBinaryTree* T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == ' ') //空
	{
		*T = NULL;
	}
	else
	{
		*T = (pBinaryTree)malloc(sizeof(BinaryTree));
		if (!*T)
			exit(0);
		(*T)->data = ch; //生成根结点
		CreateBinaryTree1(&(*T)->lchild); //生成左子树
		CreateBinaryTree1(&(*T)->rchild); //生成右子树
	}
}

int main()
{
	int i;
	pBinaryTree T, c, q;
	char e1, e2, z;

	while (1)
	{
		CreateBinaryTreeNULL(&T);
		printf("请按先序输入二叉树(如:ab三个空格表示a为根结点,b为左子树的二叉树)\n");
		CreateBiTree2(&T);
		e1 = ReturnRoot(T);
		if (e1 != ' ')
			printf("二叉树的根为: %c\n", e1);
		else
			printf("树空，无根\n");

		printf("\n\n");

		printf("先序递归遍历二叉树:\n");
		PreOrderTraverse(T, visitT);

		printf("\n\n");

		printf("中序递归遍历二叉树:\n");
		InOrderTraverse(T, visitT);

		printf("\n\n");

		printf("后序递归遍历二叉树:\n");
		PostOrderTraverse(T, visitT);

		printf("\n\n");

		printf("层序遍历二叉树:\n");
		LevelOrderTraverse(T, visitT);

		printf("\n\n");

		printf("先序非递归遍历二叉树:\n");
		PreOrder(T, visitT);

		printf("\n\n");

		printf("中序非递归遍历二叉树:\n");
		InOrder(T, visitT);

		printf("\n\n");

		printf("后序非递归遍历二叉树:\n");
		PostOrder(T, visitT);

		printf("\n\n");

		while (1)
		{
			printf("请输入一个结点的值: ");
			scanf("%*c");
			scanf("%c%*c", &e1);
			c = ReturnPoint(T, e1); // c为e1的指针
			if (c == NULL)
			{
				printf("树中不存在该节点\n");
				printf("\n\n");

				printf("\n\n是否继续查询？ Y/N\n");
				scanf("%c", &z);
				if (z == 'N')
				{
					break;
				}
			}
			else
			{
				printf("结点的值为%c\n", ReturnNode(c));
				printf("\n\n");

				e2 = e1;
				AssignmentNode(c, e2);
				e1 = ReturnParent(T, e2);
				if (e1 != ' ')
				{
					printf("%c的双亲是%c\n", e2, e1);
				}
				else
				{
					printf("%c没有双亲\n", e2);
				}
				e1 = ReturnLeftChild(T, e2);
				if (e1 != ' ')
				{
					printf("%c的左孩子是%c\n", e2, e1);
				}
				else
				{
					printf("%c没有左孩子\n", e2);
				}
				e1 = ReturnRightChild(T, e2);
				if (e1 != ' ')
				{
					printf("%c的右孩子是%c\n", e2, e1);
				}
				else
				{
					printf("%c没有右孩子\n", e2);
				}

				printf("\n\n是否继续查询？ Y/N\n");
				scanf("%c", &z);
				if (z == 'N')
				{
					break;
				}
			}
		}

		DelBinaryTree(&T);

		printf("\n\n输入另一棵树还是结束？ Y/N\n");
		scanf("%*c");
		scanf("%c%*c", &z);
		if (z == 'N')
		{
			break;
		}
	}

	return 0;
}