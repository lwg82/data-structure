#pragma once


/*
双端队列，链表实现
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

	bool DeQueueHead(T &x);  // 对头 删除
	bool EnQueueTail(const T &x); // 队尾 插入

	bool DeQueueTail(T &x); // 队尾 删除
	bool EnQueueHead(const T &x); // 对头 插入

	bool empty() const { return head == nullptr; }

	int  size() const;
	
	void make_empty();

	
private:
	queue_node<T> *head, *tail;
};



template<typename T>
void linked_double_queue<T>::make_empty()
{
	// 从头开始删
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
	// 分两种情况，一种队列为空，插入头位置，另一种不为空，直接在尾部插入
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

	// 需要找到队尾的前驱结点
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