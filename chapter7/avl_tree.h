#pragma once

/*
	AVL��
*/

template<typename K, typename E>
struct AVLNode
{
	AVLNode(K k = K(), E d = E(), AVLNode<K, E> l = nullptr, AVLNode<K,E> r = nullptr)
		: balance_factor(0)
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
private:
	// ����ת����ʾ�������ߣ�node ƽ������Ϊ2��node->right ƽ������Ϊ1
	void rotate_left(AVLNode<K, E> *node);         

	// ����ת����ʾ�������ߣ�node ƽ������Ϊ-2��node->left ƽ������Ϊ-1
	void rotate_right(AVLNode<K, E> *node);
	void rotate_left_right(AVLNode<K, E> *node);
	void rotate_right_left(AVLNode<K, E> *node);

	bool insert(const K &k, const E &e, AVLNode<K, E> *&node);

private:
	AVLNode<K, E> *root;
};

template<typename K, typename E>
void  AVLTree<K, E>::rotate_left(AVLNode<K, E> *node)
{
	AVLNode<K, E> *subL = node; // ��Ҫ����ת�Ľ��

	node = node->right;   // ԭ node �ҽ���Ϊ ���ڵ�

	subL->right = node->left;  // ���������Ϊ�ұ�����

	node->left = subL; // ����ת

	node->balance_factor = subL->balance_factor = 0;
}


template<typename K, typename E>
void  AVLTree<K, E>::rotate_right(AVLNode<K, E> *node)
{
	AVLNode<K, E> *subR = node;

	node = node->left;  // ԭ��������Ϊ���ڵ�

	subR->left = node->right; // �������ҵ���������

	node->right = subR;  // ����ת

	node->balance_factor = subR->balance_factor = 0;
}


template<typename K, typename E>
void  AVLTree<K, E>::rotate_left_right(AVLNode<K, E> *node)
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
void  AVLTree<K, E>::rotate_right_left(AVLNode<K, E> *node)
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
	return false;
}