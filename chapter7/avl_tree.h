#pragma once

/*
	AVL��
*/

#include <stack>

template<typename K, typename E>
struct AVLNode
{
	AVLNode(K k = K(), E d = E(), AVLNode<K, E> *l = nullptr, AVLNode<K,E> *r = nullptr)
		: key(k), data(d)
		, left(l), right(r)
		, balance_factor(0)
	{}

	K key;
	E data;

	AVLNode<K, E> *left, *right;

	int balance_factor; // ƽ������
};

template<typename K, typename E>
class AVLTree
{
public:
	AVLTree() : root(nullptr)
	{}
		
	bool insert(const K &k, const E &e) { return insert(k, e, root); }

	AVLNode<K, E>* search(const K &k) { search_counter = 0; return search(k, root); }

	int get_counter() const { return search_counter; }
private:
	// ����ת����ʾ�������ߣ�node ƽ������Ϊ2��node->right ƽ������Ϊ1
	void rotate_left(AVLNode<K, E> *&node);         

	// ����ת����ʾ�������ߣ�node ƽ������Ϊ-2��node->left ƽ������Ϊ-1
	void rotate_right(AVLNode<K, E> *&node);
	void rotate_left_right(AVLNode<K, E> *&node);
	void rotate_right_left(AVLNode<K, E> *&node);

	bool insert(const K &k, const E &e, AVLNode<K, E> *&node);
	AVLNode<K, E>* search(const K &k, AVLNode<K, E> *subTree);

	void inOrder(AVLNode<K, E> *node, std::ostream &out);

	friend std::ostream& operator<<(std::ostream &out, AVLTree<K, E> &tree)
	{
		tree.inOrder(tree.root, out);
		out << std::endl;
		
		return out;
	}

private:
	AVLNode<K, E> *root;

	int search_counter;
};

template<typename K, typename E>
void AVLTree<K, E>::inOrder(AVLNode<K, E> *subTree, std::ostream &out)
{
	if (subTree != nullptr)
	{
		inOrder(subTree->left, out);
		out << "key = " << subTree->key << " value =" << subTree->data << std::endl;
		inOrder(subTree->right, out);
	}
}

template<typename K, typename E>
void  AVLTree<K, E>::rotate_left(AVLNode<K, E> *&node)
{
	AVLNode<K, E> *subL = node; // ��Ҫ����ת�Ľ��

	node = node->right;   // ԭ node �ҽ���Ϊ ���ڵ�

	subL->right = node->left;  // ���������Ϊ�ұ�����

	node->left = subL; // ����ת

	node->balance_factor = subL->balance_factor = 0;
}


template<typename K, typename E>
void  AVLTree<K, E>::rotate_right(AVLNode<K, E> *&node)
{
	AVLNode<K, E> *subR = node;

	node = node->left;  // ԭ��������Ϊ���ڵ�

	subR->left = node->right; // �������ҵ���������

	node->right = subR;  // ����ת

	node->balance_factor = subR->balance_factor = 0;
}


template<typename K, typename E>
void  AVLTree<K, E>::rotate_left_right(AVLNode<K, E> *&node)
{
	// �Ȱ����Ǹ��Ե�λ��ȷ������
	AVLNode<K, E> *subR = node;
	AVLNode<K, E> *subL = node->left;

	node = subL->right;

	// ����ת
	subL->right = node->left;
	node->left = subL;
	// ȷ���������ĸ�
	if (node->balance_factor <= 0) // ��߸�
		subL->balance_factor = 0;
	else                          
		subL->balance_factor = -1;

	// ����ת
	subR->left = node->right;
	node->right = subR;
	// ȷ���������ĸ߶�
	if (node->balance_factor == -1) // ��߸�
		subR->balance_factor = 1;
	else                            
		subR->balance_factor = 0;

	// ���ø��ڵ�߶�
	node->balance_factor = 0;
}


template<typename K, typename E>
void  AVLTree<K, E>::rotate_right_left(AVLNode<K, E> *&node)
{
	AVLNode<K, E> *subL = node;
	AVLNode<K, E> *subR = node->right;

	node = subR->left;

	// ����
	subR->left = node->right;
	node->right = subR;
	if (node->balance_factor >= 0) // �Ҹ�
		subR->balance_factor = 0;
	else
		subR->balance_factor = 1;

	// ����
	subL->right = node->left;
	node->left = subL;
	if (node->balance_factor == 1) // �Ҹ�
		subL->balance_factor = -1;
	else
		subL->balance_factor = 0;

	node->balance_factor = 0;

}


template<typename K, typename E>
bool AVLTree<K,E>::insert(const K &k, const E &e, AVLNode<K, E> *&node)
{
	std::stack<AVLNode<K, E> *> stack_trace; // ������·��
	AVLNode<K, E> *node_parent = nullptr; // �����
	AVLNode<K, E> *node_current = nullptr; // ��ǰ���

	node_current = node;

	// Ѱ�Ҳ���λ�ã�����¼·��
	while (node_current != nullptr)
	{
		node_parent = node_current; // ���游���λ��
		stack_trace.push(node_current); // ��¼·��

		if (k < node_current->key)
			node_current = node_current->left;
		else
			node_current = node_current->right;
	}

	// �ҵ�λ�ã������½��
	node_current = new AVLNode<K, E>(k, e);

	// ����
	if (node_parent == nullptr)
	{
		node = node_current;
		return true;
	}

	// �½�����
	if (node_current->key < node_parent->key)
		node_parent->left = node_current;
	else
		node_parent->right = node_current;

	// ����ƽ�⻯
	while (!stack_trace.empty())
	{// ��Ϊ��
		// ��ȡ���ڵ�
		node_parent = stack_trace.top();
		stack_trace.pop();

		// ����ƽ������
		if (node_current == node_parent->left)
			node_parent->balance_factor--;
		else
			node_parent->balance_factor++;

		// 3���������
		// ��һ��
		if (0 == node_parent->balance_factor)
			break;
		
		// �ڶ��� 
		if (-1 == node_parent->balance_factor || 1 == node_parent->balance_factor)
			node_current = node_parent; // ���游�ڵ㣬�������ϻ���
		else
		{
			// ��������� 
			if (node_parent->balance_factor == 2)
			{ // ��������
				if (node_current->balance_factor == 1) // ����ת
					rotate_left(node_parent);
				else                                   //  node_current->balance_factor == -1
					rotate_right_left(node_parent);
			} 
			else  //  node_parent->balance_factor == -2
			{ // ��������
				if (node_current->balance_factor == -1)
					rotate_right(node_parent);
				else
					rotate_left_right(node_parent);
			}

			break; // �������ϵ���
		}
	} // while

	if (stack_trace.empty())
	{
		// ���������ĸ��ڵ�
		node = node_parent;
	}
	else
	{
		// û�е��������ڵ㣬��������
		AVLNode<K, E> *node_grandfather = stack_trace.top();

		if (node_parent->key < node_grandfather->key)
			node_grandfather->left = node_parent;
		else
			node_grandfather->right = node_parent;
	}


	return true;
}


template<typename K, typename E>
AVLNode<K, E>* AVLTree<K, E>::search(const K &k, AVLNode<K, E> *subTree)
{
	if (!subTree)
		return nullptr;

	++search_counter;

	if (k < subTree->key)
		return search(k, subTree->left);
	else if (k > subTree->key)
		return search(k, subTree->right);
	return subTree;

}