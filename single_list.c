#include <stdio.h>
#include <stdlib.h>
 
// 定义链表节点结构体
typedef struct tagLinkedListNode 
{
    int data;                             // 数据域
    struct tagLinkedListNode* next;       // 指针域，指向下一个节点
}List_Node_S, List_Head_S;
 
/* 创建含头节点的单链表 */
List_Head_S*  LinkedList_CreateList(void)
{
    List_Head_S* pstListHeadNode;
 
    /* 头节点 */
    pstListHeadNode = (List_Node_S*) malloc (sizeof(List_Node_S));
    if(NULL != pstListHeadNode)
    {
        pstListHeadNode->data = 0; 
        pstListHeadNode->next = NULL; 
    }
    return pstListHeadNode;
}
 
/* 尾部插入普通节点 */
void LinkedList_InserNode (List_Head_S* pstList,  int idata)
{
    /* 查找尾节点 */
    List_Node_S* pstHeadNode = pstList;
    List_Node_S* pstLastNode = pstHeadNode;
    while(NULL != pstLastNode->next)
    {
        pstLastNode = pstLastNode->next;
    }
 
    /* 申请新普通节点 */
    List_Node_S* pstNewNode;
    pstNewNode =  (List_Node_S*) malloc (sizeof(List_Node_S));
    pstNewNode->data = idata;
    pstNewNode->next =  NULL;
 
    /* 尾插 */
    pstLastNode->next = pstNewNode;
}
 
/* 打印普通节点 */
void LinkedList_PrintList (List_Head_S* List)
{
    List_Head_S* pstListHead = List;
    List_Node_S* pstPrintNode = pstListHead->next;
 
    while(NULL != pstPrintNode)
    {
        printf("%d \n",pstPrintNode->data);
        pstPrintNode = pstPrintNode->next;
    }   
}
 
int main(void)
{  
    List_Head_S* List;
 
    /*创建头节点--->创建单向链表*/
    List = LinkedList_CreateList();
 
    /*尾部添加普通节点*/
    printf("添加节点数据10, 11, 12\n");
    LinkedList_InserNode(List, 10);
    LinkedList_InserNode(List, 11);
    LinkedList_InserNode(List, 12);
 
    /* 打印普通节点 */
    printf("单链表中普通节点数据：\n");
    LinkedList_PrintList(List);    
    return 0;
}
