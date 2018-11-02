#pragma once

/*
	循环队列
*/

template<typename T>
class circle_queue
{
public:
	circle_queue(int default_size = 10);
	~circle_queue();

	bool enqueue(const T &x);
	bool dequeue(T &x);

	bool empty() const { return front == rear; }
	bool full() const { return (rear + 1) % max_size == front; } // 当满的时候，总有一个是空的，也就是说实际能使用的空间是 max_size-1

	int  size() const { return (rear - front + max_size) % max_size; }
	bool get_front(T& x);

	friend std::ostream & operator<<(std::ostream  &os, circle_queue<T> &s)
	{
		for (int i = s.front; i < s.rear; i = (i+1) % s.max_size)
		{
			os << i << "=" << s.elems[i] << ' ';
		}

		return os;
	}

private:
	int  front, rear;
	T    *elems;
	int  max_size;
};

template<typename T>
circle_queue<T>::circle_queue(int default_size):max_size(default_size)
{
	elems = new T[default_size];

	front = rear = 0;

	for (int i = 0; i < max_size; i++)
	{
		elems[i] = T();
	}
}


template<typename T>
circle_queue<T>::~circle_queue()
{
	delete[] elems;
}

template<typename T>
bool circle_queue<T>::enqueue(const T &x)
{
	if (full())
		return false;

	elems[rear] = x;
	rear = (rear + 1) % max_size;

	return true;
}

template<typename T>
bool circle_queue<T>::dequeue(T &x)
{
	if (empty())
		return false;

	T = elems[front];

	front = (front + 1) % max_size;

	return true;
}

template<typename T>
bool circle_queue<T>::get_front(T& x)
{
	if (empty())
		return false;

	x = elems[front];

	return true;
}