/*
	顺序栈的定义与操作

*/
#define ElemType int
#define MaxSize  100


typedef struct
{
	ElemType data[MaxSize];
	int top; // 栈顶指针
	
}SqStack;

void InitStack(SqStack &S);
void ClearStack(SqStack &S);

bool Push(SqStack &S, ElemType x);
bool Pop(SqStack &S, ElemType &x);

bool StackEmpty(SqStack &S);
bool GetTop(SqStack &S, ElemType &x);



// 3.2
bool CheckValidate(char *oper);

// 4
/*
	题目只给出了单链表，并没给带头结点
	解题方式：用栈
	先遍历一遍将所有数据入栈

	遍历第二遍，每遍历一个数据，栈出栈一个数据，进行比对
	如果不等则不是中心对称

*/
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LinkNode, *LinkList;

bool estimate(LinkList L);

// 5
/*
	共享栈设计
	
	左边 top = -1; 判空 top == -1; 判满 top + 1 == bottom;
	右边 bottom = MaxSize; 判空 bottom == MaxSize; 判满 bottom - 1 == top;
*/
typedef struct
{
	ElemType data[MaxSize];
	int top;
	int bottom;
}SqShareStack;

void InitShareStack(SqShareStack &L);

bool LeftPush(SqShareStack &L, ElemType x);
bool LeftPop(SqShareStack &L, ElemType &x);

bool RightPush(SqShareStack &L, ElemType x);
bool RightPop(SqShareStack &L, ElemType &x);