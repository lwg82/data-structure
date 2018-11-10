#pragma once

#include <iostream>
#include <stack>

template<typename T>
struct binary_tree_node
{
	T data;
	binary_tree_node<T> *left, *right;

	binary_tree_node(T x = T(), binary_tree_node<T> *l = nullptr, binary_tree_node<T> *r = nullptr)
		:data(x), left(l), right(r)
	{

	}
};


template<typename T>
class binary_tree
{
public:
	binary_tree();
	~binary_tree();

	binary_tree(const binary_tree<T>& rhs);

	void create_binary_tree(char *string_list);
	void destroy_binary_tree(binary_tree_node<T> *&sub);

	void preOrder(void(*visit)(binary_tree_node<T> *node));
	void inOrder(void(*visit)(binary_tree_node<T> *node));
	void postOrder(void(*visit)(binary_tree_node<T> *node));

	int size()  { return size(root); }
	int height()  { return height(root); };

	

private:

	void preOrder(binary_tree_node<T> *sub, void(*visit)(binary_tree_node<T> *node));
	void inOrder(binary_tree_node<T> *sub, void(*visit)(binary_tree_node<T> *node));
	void postOrder(binary_tree_node<T> *sub, void(*visit)(binary_tree_node<T> *node));

	int size(binary_tree_node<T> *sub);
	int height(binary_tree_node<T> *sub);

	binary_tree_node<T> * copy(binary_tree_node<T> *sub);

	

	// 前序遍历输出
	void traverse(binary_tree_node<T> *sub, std::ostream &out);

	friend std::istream& operator>>(std::istream &in, binary_tree<T> &tree)
	{

		return in;
	}

	friend std::ostream& operator<<(std::ostream &out, binary_tree<T> &tree)
	{
		tree.traverse(tree.root, out);
		return out;
	}

public:
	binary_tree_node<T> *root;

	char eof;                           // 结束符 #
};

template<typename T>
binary_tree<T>::binary_tree()
	:root(nullptr)
	,eof('#')
{

}


template<typename T>
binary_tree<T>::~binary_tree()
{
	destroy_binary_tree(root);
}

template<typename T>
void binary_tree<T>::destroy_binary_tree(binary_tree_node<T> *&sub)
{
	if (sub != nullptr)
	{
		destroy_binary_tree(sub->left);
		destroy_binary_tree(sub->right);

		delete sub; sub = nullptr;
	}
}

template<typename T>
void binary_tree<T>::create_binary_tree(char *string_list)
{
	destroy_binary_tree(root);

	char *str_ptr = string_list;

	std::stack<binary_tree_node<T> *> s;

	binary_tree_node<T> *node_sub = nullptr;
	binary_tree_node<T> *node_parent = nullptr;

	int k = 0;

	char data = *str_ptr;

	while (data != eof)
	{
		switch (data)
		{
		case '(':
			s.push(node_sub);
			k = 1;
			break;

		case ')':
			s.pop();
			break;

		case ',':
			k = 2;
			break;

		default:
			node_sub = new binary_tree_node<T>(data);

			if (nullptr == root)
			{
				root = node_sub;
			}
			else
			{
				if (1 == k)
				{
					node_parent = s.top();
					node_parent->left = node_sub;
				}
				else
				{
					node_parent = s.top();
					node_parent->right = node_sub;
				}
			}
		}

		data = *++str_ptr;
	}

}

template<typename T>
void binary_tree<T>::traverse(binary_tree_node<T> *sub, std::ostream &out)
{
	if (sub != nullptr)
	{
		out << sub->data;

		traverse(sub->left, out);
		traverse(sub->right, out);
	}
}


template<typename T>
void binary_tree<T>::preOrder(void(*visit)(binary_tree_node<T> *node))
{
	preOrder(root, visit);
}


template<typename T>
void binary_tree<T>::inOrder(void(*visit)(binary_tree_node<T> *node))
{
	inOrder(root, visit);
}


template<typename T>
void binary_tree<T>::postOrder(void(*visit)(binary_tree_node<T> *node))
{
	postOrder(root, visit);
}


template<typename T>
void binary_tree<T>::preOrder(binary_tree_node<T> *sub, void(*visit)(binary_tree_node<T> *node))
{
	if (sub != nullptr)
	{
		visit(sub);
		preOrder(sub->left, visit);
		preOrder(sub->right, visit);
	}

}



template<typename T>
void binary_tree<T>::inOrder(binary_tree_node<T> *sub, void(*visit)(binary_tree_node<T> *node))
{
	if (sub != nullptr)
	{
		inOrder(sub->left, visit);
		visit(sub);
		inOrder(sub->right, visit);
	}
}



template<typename T>
void binary_tree<T>::postOrder(binary_tree_node<T> *sub, void(*visit)(binary_tree_node<T> *node))
{
	if (sub != nullptr)
	{
		postOrder(sub->left, visit);
		postOrder(sub->right, visit);

		visit(sub);
	}
	
}



template<typename T>
int binary_tree<T>::size(binary_tree_node<T> *sub)
{
	if (nullptr == sub)
		return 0;
	else
		return size(sub->left) + size(sub->right) + 1;
}

template<typename T>
int binary_tree<T>::height(binary_tree_node<T> *sub)
{
	if (nullptr == sub)
		return 0;
	else
	{
		int left = height(sub->left);
		int right = height(sub->right);
		return left > right ? left+1 : right+1;
	}
}



template<typename T>
binary_tree<T>::binary_tree(const binary_tree<T> &rhs)
{
	root = copy(rhs.root); // 注意赋值给 root
}

template<typename T>
binary_tree_node<T>* binary_tree<T>::copy(binary_tree_node<T> *sub)
{
	if (nullptr == sub)
		return nullptr;

	binary_tree_node<T> *node = new binary_tree_node<T>;
	// 先序
	node->data = sub->data;

	node->left = copy(sub->left);
	node->right = copy(sub->right);

	return node;
}

template<typename T>
bool equal(binary_tree_node<T> *node1, binary_tree_node<T> *node2)
{
	if (nullptr == node1 && nullptr == node2)
		return true;
	
	if (nullptr != node1 && nullptr != node2 && node1->data == node2->data
		&& equal(node1->left, node2->left)           // 左子树相等
		&& equal(node1->right, node2->right))        // 右子树相等
		return true;

	return false;
}

// 非成员函数
template<typename T>
bool operator==(const binary_tree<T> &t1,const binary_tree<T> &t2)
{
	return equal(t1.root, t2.root);
}

template<typename T>
bool operator!=(const binary_tree<T> &t1, const binary_tree<T> &t2)
{
	return !(t1 == t2);
}