#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "list.h"
 
/* �� ���崴������ĺ��� */
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
 
/* �� ����ɾ������ĺ��� */
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
 
/* �� ����������ӽڵ�ĺ��� */
int TEST_list_Insert(LIST_HEAD_S* List, void * data)
{
	LIST_NODE_S* pstNewnode;
	pstNewnode = (LIST_NODE_S *)malloc(sizeof(*pstNewnode));
    pstNewnode->data = malloc(List->size);
    
	memcpy(pstNewnode->data, data, List->size);

	/* ���ײ����뷽ʽ */
	pstNewnode->next = List->head.next;
	pstNewnode->prev = &List->head;
	pstNewnode->prev->next = pstNewnode;
	pstNewnode->next->prev = pstNewnode;
 
	return 0;
}
 
/* �� �����������ڵ�ĺ��� */
void TEST_list_Display(LIST_HEAD_S* pstList, llist_callback* print_Func)
{
	LIST_NODE_S* pstCurNode;
	
	for (pstCurNode = pstList->head.next; &pstList->head != pstCurNode; pstCurNode = pstCurNode->next)
	{
		print_Func(pstCurNode->data);
	}
}
 
/* �� ������ҽڵ�ĺ��� */
void TEST_list_Find(LIST_HEAD_S* llist, llist_idfind* idfind_Func,int *stuID)
{
	LIST_NODE_S* curnode;
 
	for (curnode = llist->head.next; &llist->head != curnode; curnode = curnode->next)
	{
		idfind_Func(curnode->data,stuID);
	}
}