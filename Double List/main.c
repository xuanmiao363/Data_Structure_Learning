#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "list.h"
 
#define NAMESIZE 32
 
void Score_print_Func(const void* score);
void Score_idfind_Func(const void* score, int* stuID);
 
/* 声明普通节点下面挂的数据结构 */
typedef struct llist_score_s
{
	int  stuID;
	char name[NAMESIZE];
	int  math;
}LLIST_SCORE_S;
 
int main()
{
	/* 声明双向链表 */
	LIST_HEAD_S* List = NULL;
 
	/* 创建带头结点双向链表llist */
	List = TEST_list_Create(sizeof(LLIST_SCORE_S));
 
	/* 在链表上添加节点 */
	LLIST_SCORE_S student_A = {20221008,"Lihua",98};
	TEST_list_Insert(List, &student_A);
 
	/* 遍历链表 */
	TEST_list_Display(List,Score_print_Func);
 
	/* 查找节点 */
	int stuID = 20221008;
	TEST_list_Find(List,Score_idfind_Func,&stuID);
 
	/* 删除链表 */
	TEST_list_Destroy(List);
	return 0;
}
 
void Score_print_Func(const void * score)
{
	const LLIST_SCORE_S* temp = (LLIST_SCORE_S *) score;
	printf("学生的学号是%d,姓名是%s,数学成绩是%d\n",temp->stuID,temp->name,temp->math);
}
 
void Score_idfind_Func(const void *score,int *stuID)
{
	const LLIST_SCORE_S* temp = (LLIST_SCORE_S*)score;
	if (temp->stuID == *stuID)
		printf("找到了学号为%d的学生,学生姓名为%s,学生数学成绩为%d\n", temp->stuID,temp->name,temp->math);
}