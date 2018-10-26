#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

template<typename T>
class linear_list
{
public:
	linear_list();
	~linear_list();

	virtual int size() const = 0;
	virtual int length() const = 0;
	
	virtual int locate(int i) const = 0;

	virtual int search(T &x) const = 0;

	


};


#endif
