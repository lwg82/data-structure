#pragma once


/*
	˫�˶���(˫��ѭ������)������ʵ��
*/

template<typename T>
class sequential_double_queue
{
public:
	sequential_double_queue(int default_size = 100);
	~sequential_double_queue();

	bool getHead(T &x) const;
	bool getTail(T &x) const;

	

	bool DeQueueHead(T &x);  // ��ͷ ɾ��
	bool EnQueueTail(const T &x); // ��β ����

	bool DeQueueTail(T &x); // ��β ɾ��
	bool EnQueueHead(const T &x); // ��ͷ ����

	bool empty() const { return head == tail; }
	bool full() const { return (tail + 1) % max_size == head; } // ������ʱ������һ���ǿյģ�Ҳ����˵ʵ����ʹ�õĿռ��� max_size-1
	int  size() const { return (tail - head + max_size) % max_size; }

	// ��Ϊ��ͷ���������������������޸�
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
	// ��ȡ���ݣ���ǰ��һ��
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
	// tail ��Ҫ��д�����ݣ���ǰ��һ��
	if (full())
		return false;

	elems[tail] = x;
	tail = (tail + 1) % max_size;

	return true;
}



template<typename T>
bool sequential_double_queue<T>::EnQueueHead(const T &x)
{
	// head ��Ҫ����һ��, ��д������
	if (full())
		return false;

	head = (head - 1 + max_size) % max_size; // ע������,�����
	elems[head] = x;

	return true;
}





template<typename T>
bool sequential_double_queue<T>::DeQueueTail(T &x)
{
	// �Ⱥ���һ������ȡ����
	if (empty())
		return false;

	tail = (tail - 1 + max_size) % max_size; // ע������,�����
	x = elems[tail];

	elems[tail] = T();

	return true;
}