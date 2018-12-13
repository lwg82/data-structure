#pragma once

#include "common.h"
#include "linked_list.h"

/*

ѭ������

https://blog.csdn.net/qq_29542611/article/details/79029540
https://www.cnblogs.com/ytz1996/p/6287420.html

*/
template<typename T>
class circle_list
{
public:
	circle_list();
	~circle_list();

	linked_node<T> * locate(int i);
	bool insert(int pos, T v);
	bool remove(int pos, T &v);

	void output();

//private:
	linked_node<T> *first;
	linked_node<T> *last; // û�õ�??
};


////////////////////////////////
template<typename T>
circle_list<T>::circle_list()
{
	first = new linked_node<T>();

	last = first;

	first->next = first;
}

template<typename T>
circle_list<T>::~circle_list()
{

}

template<typename T>
void circle_list<T>::output()
{
	linked_node<T> *current = first;

	while (current->next != first)
	{
		current = current->next;
		std::cout << current->value << '\t';
	}

	std::cout << std::endl;
}
template<typename T>
linked_node<T> * circle_list<T>::locate(int pos)
{
	if (pos < 0)
	{
		std::cout << "λ�� " << pos << " ��Ч" << std::endl;
		return nullptr;
	}

	linked_node<T>* current = first;
	int k = 0;

	while (current->next != first && k < pos)
	{
		current = current->next;
		k++;
	}

	return current;
}

template<typename T>
bool circle_list<T>::insert(int pos, T x)
{
	linked_node<T>* prefix = locate(pos);

	if (nullptr == prefix)
	{
		std::cout << "λ�� " << pos << " ��Ч" << std::endl;
		return false;
	}
	

	// �ҵ���
	linked_node<T> *new_node_ptr = new linked_node<T>(x);
	ERROR_MALLOC(new_node_ptr);

	new_node_ptr->next = prefix->next;
	prefix->next = new_node_ptr;

	return true;
}

template<typename T>
bool circle_list<T>::remove(int pos, T &v)
{
	// �ҵ�����ǰ��

	if (pos < 1)
	{
		std::cout << "λ�� " << pos << " ��Ч" << std::endl;
		return false;
	}

	linked_node<T>* prefix = locate(pos-1);

	if (nullptr != prefix)
	{
		linked_node<T>* del = prefix->next;

		prefix->next = del->next;

		v = del->value;

		delete del;

	}

	return false;
}