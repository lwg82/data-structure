#pragma once

/*
	顺序队列，循环队列
*/

#define ElemType int
#define MaxSize  100

typedef struct
{
	ElemType data[MaxSize];
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue &Q);
bool EnQueue(SqQueue &Q, ElemType x);
bool DeQueue(SqQueue &Q, ElemType &x);
bool GetHead(SqQueue &Q, ElemType &x);

/*
	链式队列
	带头结点
*/
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LinkNode;

typedef struct
{
	LinkNode *front;
	LinkNode *rear;	
}LinkQueue;

void InitQueue(LinkQueue &Q);
bool EnQueue(LinkQueue &Q, ElemType x);
bool DeQueue(LinkQueue &Q, ElemType &x);
bool IsEmpty(LinkQueue &Q);