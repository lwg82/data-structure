#pragma once

#include <iostream>

/*
	ϡ�������Ԫ���ʾ

	��ʵ����һά����ʵ��

	Ŀǰֻʵ��
			ת��
			�ӷ�
			�˷�
*/


template<typename T>
struct trituple
{
	int row, col;

	T data;

	trituple & operator=(const trituple &rhs)
	{
		row = rhs.row;
		col = rhs.col;
		data = rhs.data;
	}
};

template<typename T>
class sparse_matrix
{
public:
	sparse_matrix(int default_size = 100);
	~sparse_matrix();

	sparse_matrix(const sparse_matrix &rhs);
	sparse_matrix<T> & operator=(const sparse_matrix &rhs);

	

	sparse_matrix<T> transpose();
	sparse_matrix<T> add(sparse_matrix<T> &b);
	sparse_matrix<T> multiply(sparse_matrix<T> &b);

	friend std::ostream& operator<<(std::ostream &out, sparse_matrix<T> &matrix)
	{

		for (int i = 0; i < matrix.terms; i++)
		{
			std::cout << "[" << matrix.elems[i].row << "," << matrix.elems[i].col << "]=" << matrix.elems[i].data << std::endl;
		}
		
		return out;
	}

	friend std::istream& operator >> (std::istream &in, sparse_matrix<T> &matrix)
	{
		return in;
	}

//private:
	int rows, cols;
	int terms;    // ��ǰ�洢����
	int max_terms; // �����ܹ��洢������
	trituple<T> *elems;
};

template<typename T>
sparse_matrix<T>::sparse_matrix(int default_size)
{
	max_terms = default_size;

	rows = 0;
	cols = 0;

	terms = 0;

	elems = new trituple<T>[default_size];

	
}


template<typename T>
sparse_matrix<T>::~sparse_matrix()
{
	delete[] elems;
}

template<typename T>
sparse_matrix<T> sparse_matrix<T>::transpose()
{
	sparse_matrix<T> B;



	return B;
}