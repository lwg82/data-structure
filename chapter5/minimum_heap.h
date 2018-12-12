#pragma once

/*
	最小堆， 因为数组是从0开始计数的
					  0
				1			2
			3		4    5       6
*/

template<typename T>
class minimum_heap
{
public:
	minimum_heap(int default_size = 100);

	T &getMin() const { return elem[0]; }

	bool insert(const T &data);
	bool remove(T &data);

private:
	void shiftUp(int start);

	void shiftDown(int start, int size);
private:
	T *elem;
	int max_size;
	int current_size;
};


template<typename T>
minimum_heap<T>::minimum_heap(int default_size)
	:elem(nullptr)
	,max_size(default_size)
	,current_size(0)
{
	elem = new T[default_size];

	for (int i = 0; i < default_size; i++)
		elem[i] = 0;
}


template<typename T>
bool minimum_heap<T>::insert(const T &data)
{
	if (current_size >= max_size)
		return false;

	elem[current_size] = data;

	shiftUp(current_size);

	current_size++;

	return true;
}

template<typename T>
bool minimum_heap<T>::remove(T &data)
{
	if (!current_size)
		return false;

	data = elem[0]; // 堆顶元素

	elem[0] = elem[current_size - 1]; // 用最后一个元素顶替
	elem[current_size - 1] = 0;
	current_size--;


	shiftDown(0, current_size - 1);

	return true;
}


template<typename T>
void minimum_heap<T>::shiftUp(int start)
{
	int pos = start;
	int parent = (pos - 1) / 2; // 父节点位置
	T   data = elem[pos];

	while (pos > 0)
	{
		if (elem[parent] < data)
			break;
		else
		{
			elem[pos] = elem[parent]; // 父节点数据复制给结点 ????

			pos = parent; // 向上继续寻找

			parent = (pos - 1) / 2; // 再求父节点位置
		}
	} // while

	elem[pos] = data;
}


template<typename T>
void minimum_heap<T>::shiftDown(int start, int size)
{
	int pos = start;
	int left_pos = pos * 2 + 1; // 左结点
	T   data = elem[pos];

	while (left_pos <= size)
	{
		if (left_pos < size &&
			elem[left_pos] > elem[left_pos + 1])
			left_pos++;     // 指向左右子女中数据较小的那个

		if (data < elem[left_pos])
			break;
		else
		{
			elem[pos] = elem[left_pos];

			pos = left_pos;

			left_pos = pos * 2 + 1; // 左结点
		}
	} // while

	elem[pos] = data;


}
