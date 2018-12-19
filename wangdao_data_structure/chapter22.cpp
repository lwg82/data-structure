#include "chapter22.h"

#include <iostream>

void delete_by_value(LinkList &node, ElemType x)
{
	if (node == nullptr)
		return;

	if (node->data == x)
	{
		LinkNode *pos = node->next;

		node = node->next; // 注意这里

		delete pos;

		delete_by_value(node, x); // 注意这里
	}
	else
		delete_by_value(node->next, x);
}


void delete_by_value_not_unique(LinkList &L, ElemType x)
{
	LinkNode *prefix = L;
	LinkNode *node = L->next;

	while (node != nullptr)
	{
		if (node->data == x)
		{
			LinkNode *p = node;
		
			prefix->next = node->next;

			node = node->next;

			delete p;
		}
		else
		{
			prefix = node;
			node = node->next;
		}
			
	}
}


void print_reverse(LinkList &L)
{
	if (L->next != nullptr)
	{
		print_reverse(L->next);
	}

	std::cout << L->data; // 注意它的位置
}


void delete_min_value(LinkList &L)
{
	LinkNode *node = L->next;
	LinkNode *node_prefix = L;

	LinkNode *min = L->next;  // 最小值
	LinkNode *min_prefix = L; // 最小值前驱

	while (nullptr != node)
	{
		if (node->data < min->data)
		{
			min = node;
			min_prefix = node_prefix;
		}
		
		node_prefix = node;
		node = node->next;
	}

	if (nullptr != min)
	{// 删除结点
		min_prefix->next = min->next;

		delete min; min = nullptr;
	}
}

void reverse_list(LinkList &L)
{
	LinkNode *node = L->next;

	L->next = nullptr; // 不能忘记这步

	while (node)
	{
		LinkNode *next = node->next; // 后继结点
		// 前插法
		node->next = L->next;
		L->next = node;

		node = next;
	}
}

void list_increase(LinkList L)
{
	LinkNode *node = L->next;

	LinkNode *head = L;
	head->next = nullptr;

	while (node)
	{
		LinkNode *next = node->next; // 保存后继结点
		//
		LinkNode *new_node = head->next;
		LinkNode *new_node_prefix = head;

		while (new_node) // 这有问题，如果
		{
			if (new_node->data < node->data)
			{
				new_node_prefix = new_node;
				new_node = new_node->next;
			}
			else
			{
				// 找到插入位置
				node->next = new_node;
				new_node_prefix->next = node;

				break;
			}
		}

		//
		node = next;
	}
}

void list_delete_range(LinkList L, ElemType min, ElemType max)
{
	LinkNode *cur = L->next;
	LinkNode *prefix = L;

	while (nullptr != cur)
	{
		if (cur->data > min && cur->data < max)
		{
			prefix->next = cur->next;

			delete cur;

			cur = prefix->next;
		}
		else
		{
			prefix = cur;
			cur = cur->next;
		}
	}
}


LinkNode* serach_uniform_node(LinkList L1, LinkList L2)
{
	// 遍历单链表 1, 计算链表1长度
	int len1 = 0;
	LinkNode *cur1 = L1->next;
	LinkNode *prefix1 = L1;

	while (cur1)
	{
		len1++;
		prefix1 = cur1; // 保留1前驱
		cur1 = cur1->next;
	}

	// 遍历单链表 2, 计算链表2长度
	int len2 = 0;
	LinkNode *cur2 = L2->next;
	LinkNode *prefix2 = L2;

	while (cur2)
	{
		len2++;
		prefix2 = cur2; // 保留2前驱
		cur2 = cur2->next;
	}

	// 判断尾结点是否重合，如不重合，说明没有重合
	// 指针不相同，说明不重合
	if (prefix1 != prefix2)
		return NULL;
	
	// 求两个链表长度差
	int diff = (len1 > len2) ? (len1 - len2) : (len2 - len1);

	// 优先遍历长度更长的链表

	cur1 = L1->next;
	cur2 = L2->next;

	if (len1 > len2)
	{
		while (diff > 0)
		{
			cur1 = cur1->next;
			diff--;
		}
	}
	else
	{
		while (diff > 0)
		{
			cur2 = cur2->next;
			diff--;
		}
	}

	//
	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1 == cur2)
		{
			return cur1; // 重合结点指针
		}

		cur1 = cur1->next;
		cur2 = cur2->next;
	}

	return NULL;
}


void print_increase(LinkList &L)
{
	// 拿出头节点，依次向后遍历，采用头插法，依次插入到头结点后面，一次遍历后就得到递增单链表
	// 再次遍历单链表，依次输入即可
	LinkList prefix = L; // 保存头节点指针

	LinkNode *cur = L->next;

	L->next = NULL;

	while (cur != NULL)
	{
		// 保留原单链表的后继
		LinkNode *suffix = cur->next;

		// 找前驱
		prefix = L;
		while (prefix->next && prefix->next->data < cur->data)
			prefix = prefix->next;

		// 插入
		cur->next = prefix->next;
		prefix->next = cur;

		// 
		cur = suffix;
	}

	// 打印输出
	cur = L->next;
	while (cur)
	{
		std::cout << cur->data << std::endl;
		cur = cur->next;
	}
}


void list_branch(LinkList L, LinkList L1, LinkList L2)
{
	// L1使用L的头结点，L2新建一个头结点
	// 
	L1 = L; 
	L2 = new LinkNode;
	L2->next = NULL;

	LinkNode *head = L;

	// 查找前驱结点
	int pos = 0;
	LinkNode *prefix = L;
	// 保持相对位置不变，采用尾插法
	LinkNode *rear1 = L1;
	LinkNode *rear2 = L2;
	while (prefix->next)
	{
		++pos;

		LinkNode *cur = prefix->next; // 当前结点
		LinkNode *suffix = cur->next; // 当前结点的后继
		
		if (pos % 2 == 0)
		{// 偶数
			rear1->next = cur;
			rear1 = cur;
		}
		else
		{// 奇数
			rear2->next = cur;
			rear2 = cur;
		}

		prefix = suffix;
	}

	rear1->next = NULL;
	rear2->next = NULL;
}


void list_branch2(LinkList L, LinkList L1, LinkList L2)
{
	L1 = L;
	L2 = new LinkNode;
	L2->next = NULL;

	LinkNode *prefix = L;

	while (prefix->next)
	{
		// 采用头插法
		LinkNode *cur = prefix->next;
		LinkNode *suffix = cur->next;

		// 插入 A
		cur->next = L1->next;
		L1->next = cur;

		//prefix->next = suffix;

		// 插入 B
		cur = suffix;
		suffix = cur->next;
		if (cur)
		{
			cur->next = L2->next;
			L2->next = cur;

			prefix->next = suffix;// 跳过两个结点
		}
		else
		{
			// 已经到结尾，结束循环
			return;
		}

		

	}
}

void list_remove_same_node(LinkList L)
{
	// 不需要前驱结点
	// 也不讲究效率
	LinkNode *cur = L->next;

	while (cur)
	{
		LinkNode *suffix = cur->next;

		if (suffix == NULL)
			return;

		if (cur->data == suffix->data)
		{
			cur->next = suffix->next;
			
			delete suffix;
		}
		else
		{
			cur = suffix;
		}
	}
}

void list_add(LinkList L1, LinkList L2)
{
	/*
		原来是递增的，两个链表合并为一个递减链表，
		合并后的链表保存在L1当中
		采用头插法
	*/
	LinkNode *head1 = L1;
	LinkNode *head2 = L2;

	LinkNode *cur1 = L1->next;
	LinkNode *cur2 = L2->next;

	L1->next = NULL;

	while (cur1 && cur2)
	{
		if (cur1->data < cur2->data)
		{
			LinkNode *suffix = cur1->next;

			cur1->next = L1->next;
			L1->next = cur1;

			cur1 = suffix;
		}
		else
		{
			LinkNode *suffix = cur2->next;

			cur2->next = L2->next;
			L2->next = cur2;

			cur2 = suffix;
		}
	}

	// 插入剩余的链表
	while (cur1)
	{
		LinkNode *suffix = cur1->next;

		cur1->next = L1->next;
		L1->next = cur1;

		cur1 = suffix;
	}

	while (cur2)
	{
		LinkNode *suffix = cur2->next;

		cur2->next = L2->next;
		L2->next = cur2;

		cur2 = suffix;
	}

	L2->next = NULL;
}


LinkList list_search_common(LinkList L1, LinkList L2)
{
	LinkNode *cur1 = L1->next;
	LinkNode *cur2 = L2->next;

	LinkList L3 = new LinkNode;
	L3->next = NULL;
	L3->data = 0;

	LinkNode *rear3 = L3;

	while (cur1 && cur2)
	{
		if (cur1->data  == cur2->data)
		{// 找到公共结点
			LinkNode *new_node = new LinkNode;
			new_node->data = cur1->data;
			new_node->next = NULL;

			rear3->next = new_node;
			rear3 = new_node;
			
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		else if (cur1->data < cur2->data)
		{// 因为是递增单链表，所以先移动数据小的单链表
			cur1 = cur1->next;
		}
		else
		{
			cur2 = cur2->next;
		}
	}

	return L3;
}

void list_mix(LinkList La, LinkList Lb)
{
	/*
		求交集，也是值相等
		对原链表可以进行删除操作
	*/
	LinkNode *heada = La;
	LinkNode *headb = Lb;

	LinkNode *cura = La->next;
	LinkNode *curb = Lb->next;

	La->next = NULL;

	while (cura && curb)
	{
		if (cura->data == curb->data)
		{
			LinkNode *suffix = cura->next;

			cura->next = La->next;
			La->next = cura;

			cura = suffix;

			suffix = curb->next;

			delete curb;
			curb = suffix;
		}
		else if (cura->data < curb->data)
		{ // 优先释放结点小的数据
			LinkNode *suffix = cura->next;
			delete cura;
			cura = suffix;
		}
		else
		{
			LinkNode *suffix = curb->next;
			delete curb;
			curb = suffix;
		}
	}
	// 释放剩余结点
	while (cura)
	{
		LinkNode *suffix = cura->next;
		delete cura;
		cura = suffix;
	}

	while (curb)
	{
		LinkNode *suffix = curb->next;
		delete curb;
		curb = suffix;
	}

	delete headb;
}

bool dlist_symmetry(DLinkList L)
{
	/*
		查看是否对称，
		从头结点出发，前驱与后继指针分别移动一个单位，然后查看是否相等
		当链表个数为奇数，前驱与后继指向同一个结点
		当链表个数为偶数，前驱与后继指向不同结点，prior->prior == next; 或 next->next == prior
	*/
	DLinkNode *cur_prior = L->prior;
	DLinkNode *cur_next = L->next;

	while (cur_prior && cur_next)
	{
		if (cur_prior->data != cur_next->data)
			return false;
		// 奇数
		if (cur_prior == cur_next)
			return true;
		// 偶数
		if (cur_prior->prior == cur_next && cur_next->next == cur_prior)
			return true;
		
		cur_prior = cur_prior->prior;
		cur_next = cur_next->next;
	}


	return false;
}

bool list_sub(LinkList La, LinkList Lb)
{
	/*
		两个单链表无头结点
	*/

	LinkNode *cura = La;
	LinkNode *cura_pos = cura;

	LinkNode *curb = Lb;

	while (cura && curb)
	{
		if (cura_pos->data == curb->data)
		{
			cura_pos = cura_pos->next;
			curb = curb->next;
		}
		else
		{
			cura = cura->next; // A 表继续向后移动一个单位
			cura_pos = cura;

			curb = Lb; // 重置B链表
		}
	}
	// 链表 B 已经走到最后，连续子序列
	if (curb == NULL)
		return true;
	else
		return false;
}

void slist(CircleLinkList L1, CircleLinkList L2)
{
	LinkNode *rear1 = L1;
	LinkNode *rear2 = L2;

	while (rear1->next != L1)
	{
		rear1 = rear1->next;
	}

	while (rear2->next != L2)
	{
		rear2 = rear2->next;
	}

	// 开始链接
	rear1->next = L2->next;
	rear2->next = L1;

	delete L2;
}

void find_and_delete(CircleLinkList L1)
{
	LinkList L2 = new LinkNode;
	L2->next = L2;
	L2->data = -1;

	// 先排序
	LinkNode *prefix = L1;
	LinkNode *cur = NULL;
	
	LinkNode *cur2 = L2;

	while (prefix->next != L1)
	{
		// 将 cur 结点从单循环链表 L1 中拿出
		cur = prefix->next;
		prefix->next = cur->next;

		// 单链表2
		cur2 = L2;
		while (cur2->next != NULL && cur2->next->data < cur->data)
			cur2 = cur2->next;

		// 找到插入位置
		cur->next = cur2->next;
		cur2->next = cur;
	}

	// 循环遍历 环链表2
	cur2 = L2;
	while (cur2->next != NULL)
	{
		LinkNode *min = cur2->next;
		cur2->next = min->next;

		printf("%d", min->data);

		delete min;
	}

	delete L1;
}

void find_and_delete2(CircleLinkList L1)
{
	LinkNode *min = L1->next;
	LinkNode *min_prefix = L1;

	L1->data = -1;
	LinkNode *cur = L1;

	while (cur->next != L1)
	{
		while (cur->next != L1)
		{
			if (cur->next->data > min->data)
			{
				min = cur->next;
				min_prefix = cur;
			}
			// 向后移动一个单位
			cur = cur->next;
			
		}

		// 找到最小值
		min_prefix->next = min->next;
		printf("min:%d", min->data);
		delete min;

		cur = L1;
	}

	delete L1;
	
}