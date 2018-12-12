#pragma once

/*
	��С�ѣ� ��Ϊ�����Ǵ�0��ʼ������
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

	data = elem[0]; // �Ѷ�Ԫ��

	elem[0] = elem[current_size - 1]; // �����һ��Ԫ�ض���
	elem[current_size - 1] = 0;
	current_size--;


	shiftDown(0, current_size - 1);

	return true;
}


template<typename T>
void minimum_heap<T>::shiftUp(int start)
{
	int pos = start;
	int parent = (pos - 1) / 2; // ���ڵ�λ��
	T   data = elem[pos];

	while (pos > 0)
	{
		if (elem[parent] < data)
			break;
		else
		{
			elem[pos] = elem[parent]; // ���ڵ����ݸ��Ƹ���� ????

			pos = parent; // ���ϼ���Ѱ��

			parent = (pos - 1) / 2; // ���󸸽ڵ�λ��
		}
	} // while

	elem[pos] = data;
}


template<typename T>
void minimum_heap<T>::shiftDown(int start, int size)
{
	int pos = start;
	int left_pos = pos * 2 + 1; // ����
	T   data = elem[pos];

	while (left_pos <= size)
	{
		if (left_pos < size &&
			elem[left_pos] > elem[left_pos + 1])
			left_pos++;     // ָ��������Ů�����ݽ�С���Ǹ�

		if (data < elem[left_pos])
			break;
		else
		{
			elem[pos] = elem[left_pos];

			pos = left_pos;

			left_pos = pos * 2 + 1; // ����
		}
	} // while

	elem[pos] = data;


}
