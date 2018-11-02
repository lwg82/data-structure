#pragma once


/*
˫�˶��У�����ʵ��
*/

#include "linked_queue.h"


template<typename T>
class linked_double_queue
{
public:
	linked_double_queue() :head(nullptr), tail(nullptr) {}
	~linked_double_queue() { make_empty(); }

	bool getHead(T &x) const;
	bool getTail(T &x) const;

	bool DeQueueHead(T &x);  // ��ͷ ɾ��
	bool EnQueueTail(const T &x); // ��β ����

	bool DeQueueTail(T &x); // ��β ɾ��
	bool EnQueueHead(const T &x); // ��ͷ ����

	bool empty() const { return head == nullptr; }

	int  size() const;
	
	void make_empty();

	
private:
	queue_node<T> *head, *tail;
};



template<typename T>
void linked_double_queue<T>::make_empty()
{
	// ��ͷ��ʼɾ
	queue_node<T> *ptr = nullptr;

	while (head != nullptr)
	{
		ptr = head;

		head = ptr->link;

		delete ptr; ptr = nullptr;
	}
}


template<typename T>
bool linked_double_queue<T>::DeQueueHead(T &x)
{
	if (empty())
		return false;

	queue_node<T> *ptr = head;

	head = head->link;

	x = ptr->data;

	delete ptr;

	return true;
}


template<typename T>
bool linked_double_queue<T>::EnQueueTail(const T &x)
{
	// �����������һ�ֶ���Ϊ�գ�����ͷλ�ã���һ�ֲ�Ϊ�գ�ֱ����β������
	if (nullptr == head)
	{
		head = new queue_node<T>(x);

		tail = head;
	}
	else
	{
		tail->link = new queue_node<T>(x);
		tail = tail->link;
	}

	return true;
}


template<typename T>
bool linked_double_queue<T>::DeQueueTail(T &x)
{
	if (empty())
		return false;

	// ��Ҫ�ҵ���β��ǰ�����
	queue_node<T> *prefix = head;

	while (prefix->link != tail)
	{
		prefix = ptr->link;
	}

	x = head->data;

	delete head;

	prefix->link = NULL;
	head = prefix;



	return true;
}


template<typename T>
bool linked_double_queue<T>::EnQueueHead(const T &x)
{
	if (nullptr == head)
	{
		head = new queue_node<T>(x);

		tail = head;
	}
	else
	{
		queue_node<T> *new_node = new queue_node<T>(x);

		new_node->link = head;

		head = new_node;
	}
	return true;
}