#include <stdio.h>
#include <stdlib.h>
 
// ��������ڵ�ṹ��
typedef struct tagLinkedListNode 
{
    int data;                             // ������
    struct tagLinkedListNode* next;       // ָ����ָ����һ���ڵ�
}List_Node_S, List_Head_S;
 
/* ������ͷ�ڵ�ĵ����� */
List_Head_S*  LinkedList_CreateList(void)
{
    List_Head_S* pstListHeadNode;
 
    /* ͷ�ڵ� */
    pstListHeadNode = (List_Node_S*) malloc (sizeof(List_Node_S));
    if(NULL != pstListHeadNode)
    {
        pstListHeadNode->data = 0; 
        pstListHeadNode->next = NULL; 
    }
    return pstListHeadNode;
}
 
/* β��������ͨ�ڵ� */
void LinkedList_InserNode (List_Head_S* pstList,  int idata)
{
    /* ����β�ڵ� */
    List_Node_S* pstHeadNode = pstList;
    List_Node_S* pstLastNode = pstHeadNode;
    while(NULL != pstLastNode->next)
    {
        pstLastNode = pstLastNode->next;
    }
 
    /* ��������ͨ�ڵ� */
    List_Node_S* pstNewNode;
    pstNewNode =  (List_Node_S*) malloc (sizeof(List_Node_S));
    pstNewNode->data = idata;
    pstNewNode->next =  NULL;
 
    /* β�� */
    pstLastNode->next = pstNewNode;
}
 
/* ��ӡ��ͨ�ڵ� */
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
 
    /*����ͷ�ڵ�--->������������*/
    List = LinkedList_CreateList();
 
    /*β�������ͨ�ڵ�*/
    printf("��ӽڵ�����10, 11, 12\n");
    LinkedList_InserNode(List, 10);
    LinkedList_InserNode(List, 11);
    LinkedList_InserNode(List, 12);
 
    /* ��ӡ��ͨ�ڵ� */
    printf("����������ͨ�ڵ����ݣ�\n");
    LinkedList_PrintList(List);    
    return 0;
}