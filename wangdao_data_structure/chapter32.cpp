#include "chapter32.h"


void InitQueue(SqQueue &Q)
{
	Q.front = Q.rear = 0;
}

bool EnQueue(SqQueue &Q, ElemType x)
{
	if ((Q.rear + 1) % MaxSize == Q.front)
		return false;

	Q.data[Q.rear] = x;

	Q.rear = (Q.rear + 1) % MaxSize;

	return true;
}
bool DeQueue(SqQueue &Q, ElemType &x)
{
	if (Q.front == Q.rear)
		return false;

	x = Q.data[Q.front];

	Q.front = (Q.front + 1) % MaxSize;

	return true;
}

bool GetHead(SqQueue &Q, ElemType &x)
{
	if (Q.front == Q.rear)
		return false;

	x = Q.data[Q.front];

	return true;
}

////////////////////////////
void InitQueue(LinkQueue &Q)
{
	LinkNode *node = new LinkNode; // ͷ���

	Q.front = Q.rear = node;
	Q.front->next = nullptr;
}

bool EnQueue(LinkQueue &Q, ElemType x)
{
	// û�ж��������
	LinkNode *node = new LinkNode;
	node->data = x;
	node->next = nullptr;

	Q.rear->next = node;
	Q.rear = node;

	return true;
}

bool DeQueue(LinkQueue &Q, ElemType &x)
{
	if (Q.rear == Q.front)
		return false;

	LinkNode *cur = Q.front->next;
	Q.front->next = cur->next; // ���ֻʣ��һ����㣬����front�п���ΪNULL

	x = cur->data;

	if (Q.rear == cur)
	{// ע������
		Q.rear = Q.front;
	}

	return true;
}

bool IsEmpty(LinkQueue &Q)
{
	return (Q.front == Q.rear);
}