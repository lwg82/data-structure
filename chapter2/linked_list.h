#pragma once

#include "common.h"

/*
	单链表
	不带头指针
*/
template<typename T>
struct linked_node
{
	linked_node(linked_node<T> *ptr = nullptr)
	{
		value = T();
		next = ptr;
	}

	linked_node(const T &v, linked_node<T> *ptr = nullptr)
	{
		value = v;
		next = ptr;
	}

	T   value;
	linked_node *next;
};

// 不带头指针
template<typename T>
class linked_list
{
public:
	linked_list();
	~linked_list();

	bool insert(int pos, T v);
	bool remove(int pos, T &v);

	void output();
private:
	linked_node<T>* first; // 
};

/////////////////////////////////////////////////////////////
template<typename T>
linked_list<T>::linked_list()
{
	first = nullptr;
}

template<typename T>
linked_list<T>::~linked_list()
{

}

template<typename T>
void linked_list<T>::output()
{
	linked_node<T> *current = first;

	while (current)
	{
		std::cout << current->value << '\t';
		current = current->next;
	}
}
// 在第x节点之后插入
template<typename T>
bool linked_list<T>::insert(int pos, T x)
{
	// 分两种情况，插入头部和插入 中间尾部;
	
	if (nullptr == first || 0 == pos) // 0 表示插入第一个节点之前
	{
		linked_node<T> *new_node_ptr = new linked_node<T>(x);

		new_node_ptr->next = first;
		first = new_node_ptr;

		return true;
	}
	else
	{
		// 查找位置 pos
		linked_node<T> *prefix = first;
		// 因为 prefix = first, 相当于第一个节点已经不用查找，所以这里k=1
		for (int k = 1; k < pos; k++) // 在第x节点之后插入
		{
			if (nullptr == prefix)
				break;
			else
				prefix = prefix->next;
		}


		if (nullptr == prefix && first)
		{
			std::cout << "位置 " << pos << " 无效" << std::endl;
			return false;
		}
		else
		{
			linked_node<T> *new_node_ptr = new linked_node<T>(x);
			ERROR_MALLOC(new_node_ptr);

			new_node_ptr->next = prefix->next;
			prefix->next = new_node_ptr;

			return true;
		}
	}


	return false;
}

template<typename T>
bool linked_list<T>::remove(int pos, T &v)
{
	if (!first)
		return false;

	// 分两种情况，删除第一个节点，和删除除第一个节点外的其他节点
	if (pos <= 1)
	{
		linked_node<T> *del = first;
		first = del->next;  // 向后移动一个位置

		v = del->value;
		delete del;
		return true;
	}
	else
	{
		linked_node<T> *prefix = first;
		
		for (int k = 1; k < pos-1; k++) // 查找 pos-1 个节点，也就是第 pos 的前驱
		{
			if (nullptr == prefix)
				break;
			else
				prefix = prefix->next;
		}

		// 未找到
		if (nullptr == prefix || prefix->next == nullptr) // 检查 next
		{
			std::cout << "位置 " << pos << " 无效" << std::endl;
			return false;
		}
		else
		{
			linked_node<T> *del = nullptr;

			del = prefix->next;

			prefix->next = del->next;

			v = del->value;
			delete del;
			return true;
		}
	}

	return false;
}


///////////////////////////////////////////////
// 带头指针
template<typename T>
class linked_head_list
{
public:
	linked_head_list();
	~linked_head_list();

	linked_node<T> * locate(int i);
	bool insert(int pos, T v);
	bool remove(int pos, T &v);

	void output();
private:
	linked_node<T>* head;

};

////////////////////////////////////////////////
template<typename T>
linked_head_list<T>::linked_head_list()
{
	head = new linked_head_list;
	head->next = nullptr;
	head->value = T();
}

template<typename T>
linked_head_list<T>::~linked_head_list()
{
	
}

template<typename T>
void linked_head_list<T>::output()
{
	linked_node<T> *current = head;

	while (current->next)
	{
		current = current->next;
		std::cout << current->value << '\t';
	}

	std::cout << std::endl;
}

template<typename T>
linked_node<T> * linked_head_list<T>::locate(int i)
{
	if (pos < 0)
	{
		std::cout << "位置 " << pos << " 无效" << std::endl;
		return nullptr;
	}

	linked_node<T>* current = head;
	int k = 0;

	while (current->next != nullptr && k < pos)
	{
		current = current->next;
		k++;
	}

	return current;
}



// 在第x节点之后插入
template<typename T>
bool linked_head_list<T>::insert(int pos, T x)
{
	// 不再分两种情况，从k=0开始查找，
	// a0, a1, a2, ...
	// 把head当成 a0

	if (pos < 0)
	{
		std::cout << "位置 " << pos << " 无效" << std::endl;
		return false;
	}

	linked_node<T>* current = locate(pos);
	
	if (nullptr == current)
	{// 没找到
		std::cout << "位置 " << pos << " 无效" << std::endl;
		return false;
	}
	else
	{
		linked_node<T> *new_node_ptr = new linked_node<T>(x);
		ERROR_MALLOC(new_node_ptr);

		new_node_ptr->next = current->next;
		current->next = new_node_ptr;

		return true;
	}


	return false;
}


template<typename T>
bool linked_head_list<T>::remove(int pos, T &v)
{
	if (pos < 0)
	{
		std::cout << "位置 " << pos << " 无效" << std::endl;
		return false;
	}

	linked_node<T>* current = locate(pos-1); // 找前一个位置
	
	if (nullptr == current)
	{// 没找到
		std::cout << "位置 " << pos << " 无效" << std::endl;
		return false;
	}
	else
	{
		linked_node<T>* del = current->next;

		current->next = del->next;

		value = del->value;

		delete value;

		return true;
	}

	return false;
}