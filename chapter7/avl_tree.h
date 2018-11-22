#pragma once

/*
	AVL树
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

	int balance_factor; // 平衡因子
};

template<typename K, typename E>
class AVLTree
{
public:
	AVLTree() : root(nullptr)
	{}
		
	bool insert(const K &k, const E &e) { return insert(k, e, root); }
private:
	// 左旋转，表示右子树高，node 平衡因子为2，node->right 平衡因子为1
	void rotate_left(AVLNode<K, E> *node);         

	// 右旋转，表示左子树高，node 平衡因子为-2，node->left 平衡因子为-1
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
	AVLNode<K, E> *subL = node; // 需要左旋转的结点

	node = node->right;   // 原 node 右结点变为 根节点

	subL->right = node->left;  // 左边子树变为右边子树

	node->left = subL; // 左旋转

	node->balance_factor = subL->balance_factor = 0;
}


template<typename K, typename E>
void  AVLTree<K, E>::rotate_right(AVLNode<K, E> *node)
{
	AVLNode<K, E> *subR = node;

	node = node->left;  // 原左子树变为根节点

	subR->left = node->right; // 右子树挂到左子树上

	node->right = subR;  // 右旋转

	node->balance_factor = subR->balance_factor = 0;
}


template<typename K, typename E>
void  AVLTree<K, E>::rotate_left_right(AVLNode<K, E> *node)
{
	// 先把他们各自的位置确定下来
	AVLNode<K, E> *subR = node;
	AVLNode<K, E> *subL = node->left;

	node = subL->right;

	// 左旋转
	subL->right = node->left;
	node->left = subL;
	// 确定左子树的高
	if (node->balance_factor <= 0) // 左边高
		subL->balance_factor = 0;
	else                          
		subL->balance_factor = -1;

	// 右旋转
	subR->left = node->right;
	node->right = subR;
	// 确定右子树的高度
	if (node->balance_factor == -1) // 左边高
		subR->balance_factor = 1;
	else                            
		subR->balance_factor = 0;

	// 设置根节点高度
	node->balance_factor = 0;
}


template<typename K, typename E>
void  AVLTree<K, E>::rotate_right_left(AVLNode<K, E> *node)
{
	AVLNode<K, E> *subL = node;
	AVLNode<K, E> *subR = node->right;

	node = subR->left;

	// 右旋
	subR->left = node->right;
	node->right = subR;
	if (node->balance_factor >= 0) // 右高
		subR->balance_factor = 0;
	else
		subR->balance_factor = 1;

	// 左旋
	subL->right = node->left;
	node->left = subL;
	if (node->balance_factor == 1) // 右高
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