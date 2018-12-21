#include "chapter22.h"

#include <iostream>

void delete_by_value(LinkList &node, ElemType x)
{
	if (node == nullptr)
		return;

	if (node->data == x)
	{
		LinkNode *pos = node->next;

		node = node->next; // ע������

		delete pos;

		delete_by_value(node, x); // ע������
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

	std::cout << L->data; // ע������λ��
}


void delete_min_value(LinkList &L)
{
	LinkNode *node = L->next;
	LinkNode *node_prefix = L;

	LinkNode *min = L->next;  // ��Сֵ
	LinkNode *min_prefix = L; // ��Сֵǰ��

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
	{// ɾ�����
		min_prefix->next = min->next;

		delete min; min = nullptr;
	}
}

void reverse_list(LinkList &L)
{
	LinkNode *node = L->next;

	L->next = nullptr; // ���������ⲽ

	while (node)
	{
		LinkNode *next = node->next; // ��̽��
		// ǰ�巨
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
		LinkNode *next = node->next; // �����̽��
		//
		LinkNode *new_node = head->next;
		LinkNode *new_node_prefix = head;

		while (new_node) // �������⣬���
		{
			if (new_node->data < node->data)
			{
				new_node_prefix = new_node;
				new_node = new_node->next;
			}
			else
			{
				// �ҵ�����λ��
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
	// ���������� 1, ��������1����
	int len1 = 0;
	LinkNode *cur1 = L1->next;
	LinkNode *prefix1 = L1;

	while (cur1)
	{
		len1++;
		prefix1 = cur1; // ����1ǰ��
		cur1 = cur1->next;
	}

	// ���������� 2, ��������2����
	int len2 = 0;
	LinkNode *cur2 = L2->next;
	LinkNode *prefix2 = L2;

	while (cur2)
	{
		len2++;
		prefix2 = cur2; // ����2ǰ��
		cur2 = cur2->next;
	}

	// �ж�β����Ƿ��غϣ��粻�غϣ�˵��û���غ�
	// ָ�벻��ͬ��˵�����غ�
	if (prefix1 != prefix2)
		return NULL;
	
	// �����������Ȳ�
	int diff = (len1 > len2) ? (len1 - len2) : (len2 - len1);

	// ���ȱ������ȸ���������

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
			return cur1; // �غϽ��ָ��
		}

		cur1 = cur1->next;
		cur2 = cur2->next;
	}

	return NULL;
}


void print_increase(LinkList &L)
{
	// �ó�ͷ�ڵ㣬����������������ͷ�巨�����β��뵽ͷ�����棬һ�α�����͵õ�����������
	// �ٴα����������������뼴��
	LinkList prefix = L; // ����ͷ�ڵ�ָ��

	LinkNode *cur = L->next;

	L->next = NULL;

	while (cur != NULL)
	{
		// ����ԭ������ĺ��
		LinkNode *suffix = cur->next;

		// ��ǰ��
		prefix = L;
		while (prefix->next && prefix->next->data < cur->data)
			prefix = prefix->next;

		// ����
		cur->next = prefix->next;
		prefix->next = cur;

		// 
		cur = suffix;
	}

	// ��ӡ���
	cur = L->next;
	while (cur)
	{
		std::cout << cur->data << std::endl;
		cur = cur->next;
	}
}


void list_branch(LinkList L, LinkList L1, LinkList L2)
{
	// L1ʹ��L��ͷ��㣬L2�½�һ��ͷ���
	// 
	L1 = L; 
	L2 = new LinkNode;
	L2->next = NULL;

	LinkNode *head = L;

	// ����ǰ�����
	int pos = 0;
	LinkNode *prefix = L;
	// �������λ�ò��䣬����β�巨
	LinkNode *rear1 = L1;
	LinkNode *rear2 = L2;
	while (prefix->next)
	{
		++pos;

		LinkNode *cur = prefix->next; // ��ǰ���
		LinkNode *suffix = cur->next; // ��ǰ���ĺ��
		
		if (pos % 2 == 0)
		{// ż��
			rear1->next = cur;
			rear1 = cur;
		}
		else
		{// ����
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
		// ����ͷ�巨
		LinkNode *cur = prefix->next;
		LinkNode *suffix = cur->next;

		// ���� A
		cur->next = L1->next;
		L1->next = cur;

		//prefix->next = suffix;

		// ���� B
		cur = suffix;
		suffix = cur->next;
		if (cur)
		{
			cur->next = L2->next;
			L2->next = cur;

			prefix->next = suffix;// �����������
		}
		else
		{
			// �Ѿ�����β������ѭ��
			return;
		}

		

	}
}

void list_remove_same_node(LinkList L)
{
	// ����Ҫǰ�����
	// Ҳ������Ч��
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
		ԭ���ǵ����ģ���������ϲ�Ϊһ���ݼ�����
		�ϲ������������L1����
		����ͷ�巨
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

	// ����ʣ�������
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
		{// �ҵ��������
			LinkNode *new_node = new LinkNode;
			new_node->data = cur1->data;
			new_node->next = NULL;

			rear3->next = new_node;
			rear3 = new_node;
			
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		else if (cur1->data < cur2->data)
		{// ��Ϊ�ǵ����������������ƶ�����С�ĵ�����
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
		�󽻼���Ҳ��ֵ���
		��ԭ������Խ���ɾ������
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
		{ // �����ͷŽ��С������
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
	// �ͷ�ʣ����
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
		�鿴�Ƿ�Գƣ�
		��ͷ��������ǰ������ָ��ֱ��ƶ�һ����λ��Ȼ��鿴�Ƿ����
		���������Ϊ������ǰ������ָ��ͬһ�����
		���������Ϊż����ǰ������ָ��ͬ��㣬prior->prior == next; �� next->next == prior
	*/
	DLinkNode *cur_prior = L->prior;
	DLinkNode *cur_next = L->next;

	while (cur_prior && cur_next)
	{
		if (cur_prior->data != cur_next->data)
			return false;
		// ����
		if (cur_prior == cur_next)
			return true;
		// ż��
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
		������������ͷ���
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
			cura = cura->next; // A ���������ƶ�һ����λ
			cura_pos = cura;

			curb = Lb; // ����B����
		}
	}
	// ���� B �Ѿ��ߵ��������������
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

	// ��ʼ����
	rear1->next = L2->next;
	rear2->next = L1;

	delete L2;
}

void find_and_delete(CircleLinkList L1)
{
	LinkList L2 = new LinkNode;
	L2->next = L2;
	L2->data = -1;

	// ������
	LinkNode *prefix = L1;
	LinkNode *cur = NULL;
	
	LinkNode *cur2 = L2;

	while (prefix->next != L1)
	{
		// �� cur ���ӵ�ѭ������ L1 ���ó�
		cur = prefix->next;
		prefix->next = cur->next;

		// ������2
		cur2 = L2;
		while (cur2->next != NULL && cur2->next->data < cur->data)
			cur2 = cur2->next;

		// �ҵ�����λ��
		cur->next = cur2->next;
		cur2->next = cur;
	}

	// ѭ������ ������2
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
			// ����ƶ�һ����λ
			cur = cur->next;
			
		}

		// �ҵ���Сֵ
		min_prefix->next = min->next;
		printf("min:%d", min->data);
		delete min;

		cur = L1;
	}

	delete L1;
	
}

// ���׼�𰸲�һ��
// �Լ����뷨�Ǵ�ģ����ֻ����ֵ��Ƶ�ʣ����ı���ǰ���λ�ã����µ�����ṹ�仯
// ����Ӧ���Ƚ�����������ȡ�£�Ȼ���ٲ�����Ӧλ��

DLinkNode *Locate(DLinkList L, ElemType x)
{ // ����Ƶ���Ѿ��ǵ�����
	DLinkNode *cur = L->next;

	while (NULL != cur)
	{
		if (cur->data == x)
		{
			(cur->freq)++; // Ƶ��+1
			break;
		}

		cur = cur->next;
	}

	// û�ҵ�
	if (cur == NULL)
		return NULL;


	// �ҵ�ֵΪ x �Ķ���
	DLinkNode *pos = cur; // ���浱ǰ����ַ
	
	while (L != cur->prior) // ��ǰ����, ǰ������ͷ���
	{
		if (cur->freq >= cur->prior->freq)
		{
			cur = cur->prior; // ������ǰ
		}
		else
		{
			//
			break;
		}
	}

	// ����ֵ��Ƶ��
	pos->data = cur->data;
	cur->data = x;

	int freq = pos->freq;
	pos->freq = cur->freq;
	cur->freq = freq;

	return cur;
}

int   find_data(LinkList L, int k, ElemType &data)
{
	/*
		1 �������������㵥����ĳ��� n
		2 ��õ���k�ڵ������е�λ�� n-k+1
		3 ���������� n-k+1λ���ϵ�ֵ
		xxxxxxxxxxxxxxxx 
		�Լ��ķ�ʽ��Ҫ����2�Σ�����ֻ�����һ��
		�������ָ�룬q,p, ��ʼʱ��ָ��ͷ������һ����㣬����һ�����ݽ��
		p���ƶ�k��λ�ã�������k��λ�ú�q��pͬʱ����ƶ�����p��������βʱ��q��ָ�����ǵ�k�����
	*/

	LinkNode *p = L->next;
	LinkNode *q = L->next;
	int pos = k;

	while (NULL != p)
	{
		p = p->next;
		
		if (pos > 0)
			pos--;
		else
		{
			q = q->next;
		}
	}

	if (pos > 0) // ע������
	{
		data = q->data;
		return 1;
	}
		

	return 0;
}

int GetLen(LinkList L)
{
	int count = 0;

	LinkNode *cur = L->next;

	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

LinkNode *GetSamePointer(LinkList str1, LinkList str2)
{
	/*
		�ֱ����str1,str2,��������ַ����ĳ��� len1, len2
		��� �����ַ������ȵĲ� diff = len1-len2; diff>0
		���� p1=str1->next; p2=str2->next;�ֱ�ָ������ĵ�һ�����
		����ֵ����ַ��������ƶ� diff λ�ã�Ȼ������ָ�뿪ʼ�ȶ�ֵ�Ƿ���ȣ�
		�����ȣ����ҵ�λ�ã������p1,p2�ֱ��������ƶ�һ��λ��
		ʱ�临�Ӷ� O(len1+len2)
	*/
	int len1 = GetLen(str1);
	int len2 = GetLen(str2);

	LinkNode *cur1 = str1->next;
	LinkNode *cur2 = str2->next;

	int diff = (len1 > len2) ? (len1 - len2) : (len2 - len1);
	
	for (; len1 > len2; len1--)
		cur1 = cur2->next;

	for (; len1 < len2; len2--)
		cur2 = cur2->next;
	
	while (cur1 && cur2 && (cur1 != cur2))
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}

	return cur1;
}


void DeleteSameNode(LinkList L, int maxData)
{
	/*
		������ĿҪ��ʱ�临�ӶȾ����ܵĸ�Ч���������������ɾ����ֵͬ�ķ���������Ҫ�������Ρ�
		Ȼ���Ӧ�ÿ���ʹ�ÿռ任ʱ��ķ�ʽ��
			����һ�����飬��Ϊ |data|<=n, �������СΪ n+1
			��ɨ���ͬʱ�����������λ�� a[n] ��1���� a[n] �Ѿ�����1ʱ��˵����ֵ���ֵڶ��Σ�Ӧ��ɾ��
			ʱ�临�Ӷ� O(n), �ռ临�Ӷ� O(m)
	*/

	// ��������
	int *dataArray = new int[maxData+1];
	for (int i = 0; i < maxData + 1; i++) // ע�⣬�����еȺ�
		dataArray[i] = 0;

	LinkNode *cur = L->next;
	while (cur != NULL)
	{
		int pos = (cur->data) > 0 ? cur->data : -(cur->data);

		if (dataArray[pos] > 0)
		{// ɾ�����
			LinkNode *node = cur;

			cur = cur->next;

			delete node;

		}
		else
		{
			(dataArray[pos])++;

			cur = cur->next;
		}
	}


	delete[] dataArray;
}