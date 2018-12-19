#pragma once

#define ElemType int

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LinkNode, *LinkList, *CircleLinkList;

typedef struct DLNode
{
	ElemType data;
	struct DLNode *prior;
	struct DLNode *next;
}DLinkNode, *DLinkList;

// 1
void delete_by_value(LinkList &node, ElemType x);
// 2
void delete_by_value_not_unique(LinkList &L, ElemType x);
// 3
void print_reverse(LinkList &L);
// 4
void delete_min_value(LinkList &L);
// 5
void reverse_list(LinkList &L);
// 6
void list_increase(LinkList L);
// 7
void list_delete_range(LinkList L, ElemType min, ElemType max);
// 8
LinkNode* serach_uniform_node(LinkList L1, LinkList L2);
// 9
void print_increase(LinkList &L);
// 10 保留原有顺序
void list_branch(LinkList L, LinkList L1, LinkList L2);
// 11 无序
void list_branch2(LinkList L, LinkList L1, LinkList L2);
// 12
void list_remove_same_node(LinkList L);
// 13
void list_add(LinkList L1, LinkList L2);
// 14
LinkList list_search_common(LinkList L1, LinkList L2);
// 15
void list_mix(LinkList La, LinkList Lb);
// 16
bool list_sub(LinkList La, LinkList Lb);
// 17
bool dlist_symmetry(DLinkList L);
// 18
void slist(CircleLinkList L1, CircleLinkList L2);
// 19
void find_and_delete(CircleLinkList L1);
void find_and_delete2(CircleLinkList L1);

