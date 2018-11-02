#pragma once


/*
	双端队列(双端循环对列)，数组实现
*/

template<typename T>
class sequential_double_queue
{
public:
	sequential_double_queue(int default_size = 100);
	~sequential_double_queue();

	bool getHead(T &x) const;
	bool getTail(T &x) const;

	

	bool DeQueueHead(T &x);  // 对头 删除
	bool EnQueueTail(const T &x); // 队尾 插入

	bool DeQueueTail(T &x); // 队尾 删除
	bool EnQueueHead(const T &x); // 对头 插入

	bool empty() const { return head == tail; }
	bool full() const { return (tail + 1) % max_size == head; } // 当满的时候，总有一个是空的，也就是说实际能使用的空间是 max_size-1
	int  size() const { return (tail - head + max_size) % max_size; }

	// 因为队头不在是正数，所以做了修改
	friend std::ostream & operator<<(std::ostream  &os, sequential_double_queue<T> &s)
	{
		int index = s.head;
		
		for (int i = 0; i < s.size(); i++)
		{
			os << i << "=" << s.elems[index++ % s.max_size] << ' ';
		}
		
		return os;
	}

private:
	T *elems;
	int head, tail;
	int max_size;
};

template<typename T>
sequential_double_queue<T>::sequential_double_queue(int default_size)
{
	elems = new T[default_size];

	max_size = default_size;

	head = tail = 0;

	for (int i = 0; i < max_size; i++)
	{
		elems[i] = T();
	}
}


template<typename T>
sequential_double_queue<T>::~sequential_double_queue()
{
	delete[] elems;
}


template<typename T>
bool sequential_double_queue<T>::DeQueueHead(T &x)
{
	// 先取数据，再前进一步
	if (empty())
		return false;

	x = elems[head];
	elems[head] = T();

	head = (head + 1) % max_size;

	return true;
}

template<typename T>
bool sequential_double_queue<T>::EnQueueTail(const T &x)
{
	// tail 需要先写入数据，再前进一步
	if (full())
		return false;

	elems[tail] = x;
	tail = (tail + 1) % max_size;

	return true;
}



template<typename T>
bool sequential_double_queue<T>::EnQueueHead(const T &x)
{
	// head 需要回退一步, 再写入数据
	if (full())
		return false;

	head = (head - 1 + max_size) % max_size; // 注意这里,会溢出
	elems[head] = x;

	return true;
}





template<typename T>
bool sequential_double_queue<T>::DeQueueTail(T &x)
{
	// 先后退一步，再取数据
	if (empty())
		return false;

	tail = (tail - 1 + max_size) % max_size; // 注意这里,会溢出
	x = elems[tail];

	elems[tail] = T();

	return true;
}