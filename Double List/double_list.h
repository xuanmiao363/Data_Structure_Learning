#ifndef LLIST_H_
#define LLIST_H_
 
typedef void llist_callback(const void*);
typedef void llist_idfind(const void*,int* stuID);
 
/* ������ͨ�ڵ������ */
typedef struct llist_node_s
{
	void* data;
	struct llist_node_s* prev;
	struct llist_node_s* next;
}LIST_NODE_S;
 
/* ����ͷ�ڵ������ */
typedef struct llist_head_s
{
	int size;
	LIST_NODE_S head;
}LIST_HEAD_S;
 
/* �� ������������ĺ����������Ǵ���ͷ�ڵ� */
LIST_HEAD_S* TEST_list_Create(int initsize);
 
/* �� ����ɾ������ĺ��� */
void TEST_list_Destroy(LIST_HEAD_S * llist);
 
/* �� ������ӽڵ�ĺ��� */
int TEST_list_Insert(LIST_HEAD_S *llist,void *data);
 
/* �� ������������ڵ�ĺ��� */
void TEST_list_Display(LIST_HEAD_S *llist, llist_callback* print_Func);
 
/* �� ����ͨ��ѧ�Ų��ҽڵ�ĺ��� */
void TEST_list_Find(LIST_HEAD_S *llist,llist_idfind *idfind_Func, int* stuID);

#endif