#pragma once

#include "common.h"

/*
	������
	����ͷָ��
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

// ����ͷָ��
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
// �ڵ�x�ڵ�֮�����
template<typename T>
bool linked_list<T>::insert(int pos, T x)
{
	// ���������������ͷ���Ͳ��� �м�β��;
	
	if (nullptr == first || 0 == pos) // 0 ��ʾ�����һ���ڵ�֮ǰ
	{
		linked_node<T> *new_node_ptr = new linked_node<T>(x);

		new_node_ptr->next = first;
		first = new_node_ptr;

		return true;
	}
	else
	{
		// ����λ�� pos
		linked_node<T> *prefix = first;
		// ��Ϊ prefix = first, �൱�ڵ�һ���ڵ��Ѿ����ò��ң���������k=1
		for (int k = 1; k < pos; k++) // �ڵ�x�ڵ�֮�����
		{
			if (nullptr == prefix)
				break;
			else
				prefix = prefix->next;
		}


		if (nullptr == prefix && first)
		{
			std::cout << "λ�� " << pos << " ��Ч" << std::endl;
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

	// �����������ɾ����һ���ڵ㣬��ɾ������һ���ڵ���������ڵ�
	if (pos <= 1)
	{
		linked_node<T> *del = first;
		first = del->next;  // ����ƶ�һ��λ��

		v = del->value;
		delete del;
		return true;
	}
	else
	{
		linked_node<T> *prefix = first;
		
		for (int k = 1; k < pos-1; k++) // ���� pos-1 ���ڵ㣬Ҳ���ǵ� pos ��ǰ��
		{
			if (nullptr == prefix)
				break;
			else
				prefix = prefix->next;
		}

		// δ�ҵ�
		if (nullptr == prefix || prefix->next == nullptr) // ��� next
		{
			std::cout << "λ�� " << pos << " ��Ч" << std::endl;
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
// ��ͷָ��
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
		std::cout << "λ�� " << pos << " ��Ч" << std::endl;
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



// �ڵ�x�ڵ�֮�����
template<typename T>
bool linked_head_list<T>::insert(int pos, T x)
{
	// ���ٷ������������k=0��ʼ���ң�
	// a0, a1, a2, ...
	// ��head���� a0

	if (pos < 0)
	{
		std::cout << "λ�� " << pos << " ��Ч" << std::endl;
		return false;
	}

	linked_node<T>* current = locate(pos);
	
	if (nullptr == current)
	{// û�ҵ�
		std::cout << "λ�� " << pos << " ��Ч" << std::endl;
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
		std::cout << "λ�� " << pos << " ��Ч" << std::endl;
		return false;
	}

	linked_node<T>* current = locate(pos-1); // ��ǰһ��λ��
	
	if (nullptr == current)
	{// û�ҵ�
		std::cout << "λ�� " << pos << " ��Ч" << std::endl;
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