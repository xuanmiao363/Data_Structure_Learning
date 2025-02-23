#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "list.h"
 
/* ① 定义创建链表的函数 */
LIST_HEAD_S* TEST_list_Create(int initsize)
{
	LIST_HEAD_S* pstHeadNode = NULL;
 
	pstHeadNode = (LIST_HEAD_S*)malloc(sizeof(LIST_HEAD_S));
	if (NULL == pstHeadNode)
	{
		return NULL;
    }

	pstHeadNode->size = initsize;
	pstHeadNode->head.data = NULL;
	pstHeadNode->head.prev = &pstHeadNode->head;
	pstHeadNode->head.next = &pstHeadNode->head;

	return pstHeadNode;
}
 
/* ② 定义删除链表的函数 */
void TEST_list_Destroy(LIST_HEAD_S* pstList)
{
	LIST_NODE_S* pstCurNode;
	LIST_NODE_S* pstNextNode = NULL;
 
	for (pstCurNode = pstList->head.next; pstCurNode != &pstList->head; 
          pstCurNode = pstNextNode)
	{
		pstNextNode = pstCurNode->next;
		free(pstCurNode->data);
		free(pstCurNode);
	}
	free(pstList);
}
 
/* ③ 定义链表添加节点的函数 */
int TEST_list_Insert(LIST_HEAD_S* List, void * data)
{
	LIST_NODE_S* pstNewnode;
	pstNewnode = (LIST_NODE_S *)malloc(sizeof(*pstNewnode));
    pstNewnode->data = malloc(List->size);
    
	memcpy(pstNewnode->data, data, List->size);

	/* 以首部插入方式 */
	pstNewnode->next = List->head.next;
	pstNewnode->prev = &List->head;
	pstNewnode->prev->next = pstNewnode;
	pstNewnode->next->prev = pstNewnode;
 
	return 0;
}
 
/* ④ 定义遍历链表节点的函数 */
void TEST_list_Display(LIST_HEAD_S* pstList, llist_callback* print_Func)
{
	LIST_NODE_S* pstCurNode;
	
	for (pstCurNode = pstList->head.next; &pstList->head != pstCurNode; pstCurNode = pstCurNode->next)
	{
		print_Func(pstCurNode->data);
	}
}
 
/* ⑤ 定义查找节点的函数 */
void TEST_list_Find(LIST_HEAD_S* llist, llist_idfind* idfind_Func,int *stuID)
{
	LIST_NODE_S* curnode;
 
	for (curnode = llist->head.next; &llist->head != curnode; curnode = curnode->next)
	{
		idfind_Func(curnode->data,stuID);
	}
}