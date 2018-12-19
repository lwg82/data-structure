#pragma once

#include "common.h"

template<typename T>
class sequential_list
{
	typedef T value_type;
public:
	sequential_list(int default_size = 100);
	~sequential_list();

	//sequential_list(const sequential_list& rhs);
	//sequential_list<T> operator=(const sequential_list& list);

	bool insert(int i, T &value);

	void output();
private:
	value_type  *data;   // Êý×é
	int          max_size;
	int          last;
};

/*
	
*/

template<typename T> 
sequential_list<T>::sequential_list(int default_size)
{
	data = nullptr;
	max_size = 0;
	last = -1;

	if (default_size)
	{
		data = new T[default_size];
		ERROR_MALLOC(data);

		max_size = default_size;
	}
}

template<typename T>
sequential_list<T>::~sequential_list()
{
	if (data)
	{
		delete[] data; data = nullptr;
	}

	max_size = 0;
	last = -1;
}

template<typename T>
bool sequential_list<T>::insert(int i, T &value)
{
	// ±íÂú
	

	// i ¼ì²â

	return true;
}
