#include <cstdio>
#include <cstdlib>

#include "sequential_list.h"
#include "linked_list.h"
#include "circle_list.h"


void test_circle_list()
{
	circle_list<int> circle;

	circle.insert(0, 5); // 5
	circle.insert(3, 2); // 5, 2
	circle.insert(1, 4); // 5,4,2
	circle.insert(2, 3); // 5,4,3,2
	circle.insert(4, 1); // 5,4,3,2,1
	circle.output();

	int del = 0;
	circle.remove(3, del);
	circle.output();

	getchar();
}

// 约瑟夫问题, n 总人数， m 报数
template<typename T>
void josephus(circle_list<T> &list, int n, int m)
{
	linked_node<T> *current = list.first;
	linked_node<T> *prefix = nullptr;

	// 开始报数
	// 找最后一个人，也就是运行 n-1 次
	for (int x = 0; x < n - 1; x++)
	{
		for (int y = 1; y < m - 1; y++)
		{
			prefix = current;
			current = current->next;
		}

		std::cout << "出列的人是 " << current->value << std::endl;

		// 删除出列的人
		prefix->next = current->next;

		delete current;

		current = prefix->next; // 指向下一个
	}


}



void test_linked_list()
{
	linked_list<int> list;

	list.insert(1, 4);
	list.insert(0, 1);// 1, 4
	list.insert(1, 2);// 1, 2, 4
	list.insert(2, 3);// 1, 2, 3, 4
	list.output();


	int del = 0;
	list.remove(5, del);
	list.remove(2, del); // 1, 3, 4

	list.output();

	getchar();
}


void test_josephus()
{
	circle_list<int> list;

	list.insert(1, 4);
	list.insert(0, 1);// 1, 4
	list.insert(1, 2);// 1, 2, 4
	list.insert(2, 3);// 1, 2, 3, 4
	list.insert(4, 5);// 1, 2, 3, 4
	list.insert(5, 6);// 1, 2, 3, 4
	list.insert(6, 7);// 1, 2, 3, 4
	list.insert(7, 8);// 1, 2, 3, 4
	list.insert(8, 9);// 1, 2, 3, 4
	list.insert(9, 10);// 1, 2, 3, 4
	list.insert(10, 11);// 1, 2, 3, 4
	list.output();

	josephus<int>(list, 11, 3);
	list.output();

	getchar();
}


int main(int argc, char *argv[])
{
	//test_linked_list();
	//test_circle_list();

	test_josephus();

	exit(EXIT_SUCCESS);
}