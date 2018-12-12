#include "chapter2.h"


bool delete_minimum(SqList &list, ElemType &elem)
{
	if (list.length < 1)
		return false;

	ElemType delete_value = list.data[0];
	int      pos = 0;

	for (int i = 1; i < list.length; i++)
	{
		if (delete_value > list.data[i])
		{
			delete_value = list.data[i];
			pos = i;
		}
	}

	
	elem = list.data[pos];

	list.data[pos] = list.data[list.length - 1];
	list.length--; // 注意这里

	return true;
	
}

void reverse(SqList &list)
{
	ElemType tmp = 0;

	for (int i = 0; i < list.length / 2; i++) // 只扫描一半
	{
		tmp = list.data[i];
		
		list.data[i] = list.data[list.length - 1 - i];

		list.data[list.length - 1 - i] = tmp;
	}
}

void delete_value(SqList &list, ElemType elem)
{
	int pos = 0; // 记录当前空闲的位置

	for (int i = 0; i < list.length; i++)
	{
		if (list.data[i] != elem)
		{
			list.data[pos] = list.data[i];

			pos++;
		}
	}

	list.length = pos;
}


bool delete_range(SqList &list, ElemType s, ElemType t)
{
	if (list.length < 1)
		return false;

	if (s >= t)
		return false;

	int min = 0;
	int max = 0;

	for (min = 0; min < list.length && list.data[min] < s; min++);

	if (min >= list.length)
		return false;
		
	for (max = min; max < list.length && list.data[max] <= t; max++);

	for (; max < list.length; min++, max++)
		list.data[min] = list.data[max];
	
	list.length = min + 1;

	return true;
}


bool delete_range2(SqList &list, ElemType s, ElemType t)
{
	if (list.length < 1 && s >= t) // = 也不合理
		return false;

	int pos = 0;

	for (int i = 0; i < list.length; i++)
	{
		if (list.data[i] < s && list.data[i] > t)
		{
			list.data[pos] = list.data[i];
			pos++;
		}
	}

	list.length = pos; // pos 已经指向下一个位置

	return true;
}


bool delete_repeat(SqList &list)
{
	if (list.length < 1)
		return false;

	int j;
	int i;

	for (i = 0, j = 1; j < list.length; j++)
	{
		if (list.data[i] != list.data[j])
			list.data[++i] = list.data[j];
	}

	list.length = i + 1;

	return true;
}

bool merge(SqList &list1, SqList &list2, SqList &list3)
{
	if (list1.length + list2.length > list3.max)
		return false;

	int i=0, j=0, k=0;

	for (; i < list1.length && j < list2.length;)
	{
		if (list1.data[i] < list2.data[j])
			list3.data[k++] = list1.data[i++];
		else
			list3.data[k++] = list2.data[j++];
	}

	
	for (;i < list1.length; i++)
		list3.data[k++] = list1.data[i];

	for (; j < list2.length; j++)
		list3.data[k++] = list2.data[j];

	list3.length = k + 1;
	
	return true;
}


void reverse_array(ElemType *elems, int size)
{
	ElemType tmp;
	for (int i = 0; i < size / 2; i++)
	{
		tmp = elems[i];
		elems[i] = elems[size - i - 1];
		elems[size - i - 1] = tmp;
	}
}

void exchange_array(ElemType *elems, int m, int n)
{
	// a: 0 -- m-1
	// b: m -- m + n -1
	// a1,a2,a3,...,am,b1,b2,b3,...,bn
	reverse_array(elems, m + n); // bn,...,b3,b2,b1,am,...,a3,a2,a1
	reverse_array(elems, n);     // b1,b2,b3,...,bn,am,...,a3,a2,a1
	reverse_array(elems + n, m); // b1,b2,b3,...,bn,a1,a2,a3,...,am
}

void exchange_and_insert(SqList &list, ElemType x)
{
	// 折半查找
	int low = 0;
	int high = list.length;
	int mid = 0;

	while (low <= high)
	{
		mid = (high + low) / 2; // 这是是 +

		if (x == list.data[mid])
			break;
		else if (x > list.data[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}

	// 未找到
	if (low > high)
	{
		for (int i = list.length - 1; i > high; i--) // 为什么大于 high
			list.data[i + 1] = list.data[i];

		// 结束的时候i=high
		list.data[high + 1] = x;
		list.length++;
	}
	else
	{
		if (mid != list.length - 1)
		{ // 去除最后一个位置
			// 交换位置
			list.data[mid] = list.data[mid + 1];
			list.data[mid + 1] = x;
		}
	}
}




ElemType search(ElemType elemA[], ElemType elemB[], int size)
{
	int low_a = 0, high_a = size -1;
	int low_b = 0, high_b = size -1;

	int mid_a;
	int mid_b;

	while (low_a != high_a || low_b != high_b)
	{
		// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
		mid_a = (high_a + low_a) / 2; // 这是是 +
		mid_b = (high_b + low_b) / 2;

		if (elemA[mid_a] == elemB[mid_b])
			return elemA[mid_a];

		if (elemA[mid_a] > elemB[mid_b])
		{
			if ((low_b + high_b) % 2 == 0)
			{
				// 舍弃 A 的右半边，
				// 舍弃 B 的左半边
				high_a = mid_a;
				low_b = mid_b;
			}
			else
			{
				high_a = mid_a;
				low_b = mid_b + 1;
			}
		}
		else
		{
			if ((low_a + low_b) % 2 == 0)
			{
				low_a = mid_a;  // 舍弃 A 中点的左半边
				high_b = mid_b; // 舍弃 B 中点的右半边
			}
			else
			{
				low_a = mid_a + 1;  // 舍弃 A 中点的左半边,包括中点
				high_b = mid_b; // 舍弃 B 中点的右半边
			}
			
		}
	}
	
	return elemA[mid_a] > elemB[mid_b] ? elemA[mid_a] : elemB[mid_b];
}