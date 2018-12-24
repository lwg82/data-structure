#include "chapter31.h"

#include <string>



void InitStack(SqStack &S)
{

}
void ClearStack(SqStack &S)
{

}

bool Push(SqStack &S, ElemType x)
{
	return true;
}
bool Pop(SqStack &S, ElemType &x)
{
	return true;
}

bool StackEmpty(SqStack &S)
{
	return true;
}
bool GetTop(SqStack &S, ElemType &x)
{
	return true;
}

/*
	假设存入一维数组当中,且以 '\0' 结尾的字符串
	入栈操作 'I'
	出栈操作 'O'
*/
bool CheckValidate(char *oper)
{
	/*
		定义一个整数，如果是入栈操作则加1，出栈操作则减1
		判断该变量是否小于0
	*/

	int oper_len = strlen(oper);
	int validate = 0;

	for (int i = 0; i < oper_len; i++)
	{
		char ch = oper[i];

		if (ch == 'I')
			validate++;
		else
		{
			validate--;

			if (validate < 0)
			{
				return false;
			}
		}
	}


	return true;
}


bool estimate(LinkList L)
{
	if (L == NULL)
		return false;

	SqStack stack;
	InitStack(stack);

	LinkNode *cur = L;

	int count = 0;

	while (cur != NULL)
	{
		count++;

		Push(stack, cur->data);

		cur = cur->next;
	}

	// 遍历第二次
	cur = L;
	int half = count / 2 + count % 2;

	while (half > 0)
	{
		ElemType x;
		Pop(stack, x);

		if (x != cur->data)
			return false;

		cur = cur->next;
		half--;
	}

	ClearStack(stack);
	
	return false;
}


void InitShareStack(SqShareStack &L)
{
	L.top = -1;
	L.bottom = MaxSize;
}

bool LeftPush(SqShareStack &L, ElemType x)
{
	if ((L.top + 1) == L.bottom)
		return false;

	L.data[++L.top] = x;

	return true;
}

bool LeftPop(SqShareStack &L, ElemType &x)
{
	if (L.top == -1)
		return false;

	x = L.data[L.top--];

	return true;
}


bool RightPush(SqShareStack &L, ElemType x)
{
	if ((L.bottom - 1) == L.top)
		return false;

	L.data[--L.bottom] = x;

	return true;
}


bool RightPop(SqShareStack &L, ElemType &x)
{
	if (L.bottom == MaxSize)
		return false;

	x = L.data[L.bottom++];
}