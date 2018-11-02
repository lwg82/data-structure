#include <cstdio>
#include <cstdlib>

#include "sequential_stack.h"
#include "dual_stack.h"
#include "linked_stack.h"
#include "circle_queue.h"
#include "linked_queue.h"
#include "double_ended_queue.h"
#include "double_linked_queue.h"

void test_stack()
{
	sequential_stack<int> stack;

	stack.push(19);
	stack.push(3);
	stack.push(6);

	std::cout << stack << std::endl;

	int value;

	stack.pop(value);

	std::cout << stack << std::endl;

	getchar();


}

void test_dual_stack()
{
	dual_stack<int> stack;

	getchar();
}

void test_linked_stack()
{
	linked_stack<int> stack;

	stack.push(19);
	stack.push(17);
	stack.push(6);
	stack.push(5);
	stack.push(4);
	stack.push(3);

	std::cout << stack << std::endl;

	int value;

	stack.pop(value);
	stack.pop(value);

	std::cout << stack << std::endl;

	getchar();
}

void test_circle_queue()
{
	circle_queue<int> queue(6); // 

	queue.enqueue(20);
	queue.enqueue(18);
	queue.enqueue(15);
	queue.enqueue(13);
	queue.enqueue(12);
	queue.enqueue(11);

	std::cout << queue << std::endl;
}

void test_linked_queue()
{
	linked_queue<int> queue;

	queue.enqueue(20);
	queue.enqueue(18);
	queue.enqueue(15);
	queue.enqueue(13);
	queue.enqueue(12);
	queue.enqueue(11);

	std::cout << queue << std::endl;
}

void test_sequential_double_queue()
{
	sequential_double_queue<int> queue;

	queue.EnQueueTail(13);
	queue.EnQueueTail(12);
	queue.EnQueueTail(11);

	std::cout << queue << std::endl;

	queue.EnQueueHead(20);
	queue.EnQueueHead(18);
	queue.EnQueueHead(15);


	std::cout << queue << std::endl;

	int x = 0;
	queue.DeQueueHead(x);

	std::cout << queue << std::endl;

	queue.DeQueueTail(x);

	std::cout << queue << std::endl;

}

void test_linked_double_queue()
{
	linked_double_queue<int> queue;


}

int main(int argc, char *argv[])
{
	//test_stack();
	//test_dual_stack();
	//test_linked_stack();
	//test_circle_queue();
	//test_linked_queue();
	//test_sequential_double_queue();

	test_linked_double_queue();


	getchar();
	exit(EXIT_SUCCESS);
}