#pragma once
/*
��ʽ����
����ͷ���
*/

template<typename T>
struct queue_node
{
	T data;
	queue_node *link;

	queue_node(queue_node *l = nullptr)
	{
		data = T();
		link = l;
	}

	queue_node(const T &d, queue_node *l = nullptr)
	{
		data = d;
		link = l;
	}
};


template<typename T>
class linked_queue
{
public:
	linked_queue() :front(nullptr), rear(nullptr) {}
	~linked_queue() { make_empty(); }

	bool enqueue(const T &x);
	bool dequeue(T &x);

	bool empty() const { return front == nullptr; }

	int  size() const;
	bool get_front(T& x);

	void make_empty();

	friend std::ostream & operator<<(std::ostream  &os, linked_queue<T> &s)
	{
		queue_node<T> *ptr = s.front;

		int i = 0;
		while (ptr)
		{
			os  << i++ << "=" << ptr->data << " ";

			ptr = ptr->link;
		}

		return os;
	}
private:
	queue_node<T> *front, *rear;
};

template<typename T>
void linked_queue<T>::make_empty()
{
	// ��ͷ��ʼɾ
	queue_node<T> *ptr = nullptr;

	while (front != nullptr)
	{
		ptr = front;

		front = ptr->link;

		delete ptr; ptr = nullptr;
	}
}


template<typename T>
bool linked_queue<T>::enqueue(const T &x)
{
	// �����������һ�ֶ���Ϊ�գ�����ͷλ�ã���һ�ֲ�Ϊ�գ�ֱ����β������
	if (nullptr == front)
	{
		front = new queue_node<T>(x);
		rear = front;
	}
	else
	{
		rear->link = new queue_node<T>(x);
		rear = rear->link;
	}

	return true;
}

template<typename T>
bool linked_queue<T>::dequeue(T &x)
{
	// �Ƚ��ȳ��� β�����룬ͷ����
	if (empty())
		return false;

	queue_node<T> *ptr = front;

	x = ptr->data;

	front = front->link;

	delete ptr;

	return true;
}