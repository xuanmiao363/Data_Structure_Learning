#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "list.h"
 
#define NAMESIZE 32
 
void Score_print_Func(const void* score);
void Score_idfind_Func(const void* score, int* stuID);
 
/* ������ͨ�ڵ�����ҵ����ݽṹ */
typedef struct llist_score_s
{
	int  stuID;
	char name[NAMESIZE];
	int  math;
}LLIST_SCORE_S;
 
int main()
{
	/* ����˫������ */
	LIST_HEAD_S* List = NULL;
 
	/* ������ͷ���˫������llist */
	List = TEST_list_Create(sizeof(LLIST_SCORE_S));
 
	/* ����������ӽڵ� */
	LLIST_SCORE_S student_A = {20221008,"Lihua",98};
	TEST_list_Insert(List, &student_A);
 
	/* �������� */
	TEST_list_Display(List,Score_print_Func);
 
	/* ���ҽڵ� */
	int stuID = 20221008;
	TEST_list_Find(List,Score_idfind_Func,&stuID);
 
	/* ɾ������ */
	TEST_list_Destroy(List);
	return 0;
}
 
void Score_print_Func(const void * score)
{
	const LLIST_SCORE_S* temp = (LLIST_SCORE_S *) score;
	printf("ѧ����ѧ����%d,������%s,��ѧ�ɼ���%d\n",temp->stuID,temp->name,temp->math);
}
 
void Score_idfind_Func(const void *score,int *stuID)
{
	const LLIST_SCORE_S* temp = (LLIST_SCORE_S*)score;
	if (temp->stuID == *stuID)
		printf("�ҵ���ѧ��Ϊ%d��ѧ��,ѧ������Ϊ%s,ѧ����ѧ�ɼ�Ϊ%d\n", temp->stuID,temp->name,temp->math);
}