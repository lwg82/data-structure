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

	void create_binary_tree(char *string_list);
	void destroy_binary_tree(binary_tree_node<T> *&sub);

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

private:
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