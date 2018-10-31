/*
	顺序栈

*/
#include <cassert>
#include <iostream>


template<typename T>
class sequential_stack
{
public:
	sequential_stack(int default_max_size = 100);
	~sequential_stack();

	bool push(const T &x);
	bool pop(T &x);

	bool empty() const { return -1 == top; }
	bool full() const { return top == max_size - 1; }

	int  get_size() const { return top + 1};

	bool get_top(T &x);

	void make_empty() { top = -1; }

	friend std::ostream & operator<<(std::ostream  &os, sequential_stack<T> &s)
	{
		os << "top=" << s.top << std::endl;
		for (int i = 0; i <= s.top; i++)
		{
			os << i << ":" << s.elems[i] << std::endl;
		}
		return os;
	}
	
private:
	void overflow_process();

private:
	T     *elems;

	int   top; // 栈顶
	
	int   max_size;  // 最大可容纳个数
};


template<typename T>
sequential_stack<T>::sequential_stack(int default_max_size)
{
	assert(default_max_size > 0);

	elems = new T[default_max_size];

	for (int index = 0; index < default_max_size; index++)
	{
		elems[index] = T();
	}

	max_size = default_max_size;
	top = -1;

}


template<typename T>
sequential_stack<T>::~sequential_stack()
{

}
template<typename T>
bool sequential_stack<T>::push(const T &x)
{
	if (full())
		return false;

	elems[++top] = x;

	return true;
}

template<typename T>
bool sequential_stack<T>::pop(T &x)
{
	if (empty())
		return false;

	x = elems[top--];

	return true;
}

template<typename T>
void sequential_stack<T>::overflow_process()
{
	if (!full())
		return;

	int new_max_size = max_size + 20;
	T *new_elems = new T[new_max_size];

	for (int i = 0; i < max_size; i++)
	{
		new_elems[i] = elems[i];
	}

	delete[] elems;

	max_size = new_max_size;
	elems = new_elems;


}
