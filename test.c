#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#if 0
#if 0
int main()
{
    char s[101];
	while (scanf("%s", s) != EOF) {
		printf("%s\n", s);
	}
    
    printf("The program is over.\n");
    
    return 0;
}
#endif

struct A {
	char t : 4;
	char k : 4;
	unsigned short i : 9;
	//unsigned long m;
};

int main()
{
	char *ptr;
	if ((ptr = (char *)malloc(0)) == NULL)
	puts("Gota null pointer");
	else
	puts("Gota valid pointer");
	return 0;
}
#else

struct Node
{
	int data;
	struct Node *pNext;
};

struct Node *CreateList(void)
{
	int len;
	int i;
	int val;

	//分配了一个不存放有效数据的头结点
	struct Node *pHead = (struct Node *)malloc(sizeof(struct Node));
	if (NULL == pHead)
	{
		printf("分配失败，程序终止!\n");
		exit(-1);
	}
	struct Node * pTail = pHead;
	pTail->pNext = NULL;

	printf("请输入您需要生成的链表节点的个数：len = ");
	scanf("%d",&len);

	for (i = 0; i < len; ++i)
	{
		printf("请输入第%d个节点的值：", i+1);
		scanf("%d", &val);

		struct Node *pNew = (struct Node *)malloc(sizeof(struct Node));
		if (NULL == pNew)
		{
			printf("分配失败，程序终止!\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}

bool empty_list(struct Node *pHead)
{
	if (pHead->pNext == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void TraverseList(struct Node *pHead)
{
	if (empty_list(pHead))
	{
		printf("链表为空");
	}

	struct Node *p = pHead->pNext;

	while (NULL != p)
	{
		printf ("%d\n", p->data);
		p = p->pNext;
	}
}

int main(void)
{
	struct Node *pHead = NULL;

	pHead = CreateList();
	TraverseList(pHead);

	return 0;
}

#endif