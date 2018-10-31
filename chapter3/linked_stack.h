#pragma once
/*
	链式栈
	带头结点
*/
#include<cassert>


template<typename T>
struct stack_node
{
	T data;
	stack_node *link;

	stack_node(stack_node *l = nullptr)
	{
		data = T();
		link = l;
	}

	stack_node(const T &d, stack_node *l = nullptr)
	{
		data = d;
		link = l;
	}
};

template<typename T>
class linked_stack
{
public:
	linked_stack();

	bool push(const T &x);
	bool pop(T &x);

	bool empty() const { return top->link == nullptr; }
	
	int  get_size() const;

	bool get_top(T &x);

	void make_empty();

	friend std::ostream & operator<<(std::ostream  &os, linked_stack<T> &s)
	{
		stack_node<T> *ptr = s.top->link;

		int i = 0;

		while (ptr != nullptr)
		{
			os << i++ << ":" << ptr->data << std::endl;

			ptr = ptr->link;
		}

		return os;
	}

private:
	stack_node<T> *top;
};


template<typename T>
linked_stack<T>::linked_stack()
{
	top = new stack_node<T>();

	assert(nullptr != top);
}

template<typename T>
bool linked_stack<T>::push(const T &x)
{
	stack_node<T> *new_node = new stack_node<T>(x);

	new_node->link = top->link;
	top->link = new_node;

	return true;
}

template<typename T>
bool linked_stack<T>::pop(T &x)
{
	if (empty())
		return true;

	stack_node<T> *ptr = top->link;

	top->link = ptr->link;

	x = ptr->data;

	delete ptr; ptr = nullptr;

	return true;
}