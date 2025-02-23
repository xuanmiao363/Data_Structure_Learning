#ifndef LLIST_H_
#define LLIST_H_
 
typedef void llist_callback(const void*);
typedef void llist_idfind(const void*,int* stuID);
 
/* 定义普通节点的类型 */
typedef struct llist_node_s
{
	void* data;
	struct llist_node_s* prev;
	struct llist_node_s* next;
}LIST_NODE_S;
 
/* 定义头节点的类型 */
typedef struct llist_head_s
{
	int size;
	LIST_NODE_S head;
}LIST_HEAD_S;
 
/* ① 声明创建链表的函数，本质是创建头节点 */
LIST_HEAD_S* TEST_list_Create(int initsize);
 
/* ② 声明删除链表的函数 */
void TEST_list_Destroy(LIST_HEAD_S * llist);
 
/* ③ 声明添加节点的函数 */
int TEST_list_Insert(LIST_HEAD_S *llist,void *data);
 
/* ④ 声明遍历链表节点的函数 */
void TEST_list_Display(LIST_HEAD_S *llist, llist_callback* print_Func);
 
/* ⑤ 声明通过学号查找节点的函数 */
void TEST_list_Find(LIST_HEAD_S *llist,llist_idfind *idfind_Func, int* stuID);

#endif