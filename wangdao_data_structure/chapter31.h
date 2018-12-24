/*
	˳��ջ�Ķ��������

*/
#define ElemType int
#define MaxSize  100


typedef struct
{
	ElemType data[MaxSize];
	int top; // ջ��ָ��
	
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
	��Ŀֻ�����˵�������û����ͷ���
	���ⷽʽ����ջ
	�ȱ���һ�齫����������ջ

	�����ڶ��飬ÿ����һ�����ݣ�ջ��ջһ�����ݣ����бȶ�
	��������������ĶԳ�

*/
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LinkNode, *LinkList;

bool estimate(LinkList L);

// 5
/*
	����ջ���
	
	��� top = -1; �п� top == -1; ���� top + 1 == bottom;
	�ұ� bottom = MaxSize; �п� bottom == MaxSize; ���� bottom - 1 == top;
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