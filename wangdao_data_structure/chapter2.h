#pragma once

#define MAX_SIZE 100
#define ElemType int

struct SqList
{
	ElemType *data;
	int max;
	int length;
};
// 1
bool delete_minimum(SqList &list, ElemType &elem);
// 2
void reverse(SqList &list);
// 3
void delete_value(SqList &list, ElemType elem);

// 4 假设顺序表为递增
bool delete_range(SqList &list, ElemType s, ElemType t);

// 5 表无序
bool delete_range2(SqList &list, ElemType s, ElemType t);

// 6
bool delete_repeat(SqList &list);

// 7
bool merge(SqList &list1, SqList &list2, SqList &list3);

// 8
void reverse_array(ElemType *elems, int size);
void exchange_array(ElemType *elems, int m, int n);

// 9
void exchange_and_insert(SqList &list, ElemType x);

// 11
ElemType search(ElemType elemA[], ElemType elemB[], int size);