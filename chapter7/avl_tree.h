#pragma once

/*
	AVL树
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

	int balance_factor; // 平衡因子
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
	// 左旋转，表示右子树高，node 平衡因子为2，node->right 平衡因子为1
	void rotate_left(AVLNode<K, E> *&node);         

	// 右旋转，表示左子树高，node 平衡因子为-2，node->left 平衡因子为-1
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
	AVLNode<K, E> *subL = node; // 需要左旋转的结点

	node = node->right;   // 原 node 右结点变为 根节点

	subL->right = node->left;  // 左边子树变为右边子树

	node->left = subL; // 左旋转

	node->balance_factor = subL->balance_factor = 0;
}


template<typename K, typename E>
void  AVLTree<K, E>::rotate_right(AVLNode<K, E> *&node)
{
	AVLNode<K, E> *subR = node;

	node = node->left;  // 原左子树变为根节点

	subR->left = node->right; // 右子树挂到左子树上

	node->right = subR;  // 右旋转

	node->balance_factor = subR->balance_factor = 0;
}


template<typename K, typename E>
void  AVLTree<K, E>::rotate_left_right(AVLNode<K, E> *&node)
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
void  AVLTree<K, E>::rotate_right_left(AVLNode<K, E> *&node)
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
	std::stack<AVLNode<K, E> *> stack_trace; // 结点插入路径
	AVLNode<K, E> *node_parent = nullptr; // 父结点
	AVLNode<K, E> *node_current = nullptr; // 当前结点

	node_current = node;

	// 寻找插入位置，并记录路径
	while (node_current != nullptr)
	{
		node_parent = node_current; // 保存父结点位置
		stack_trace.push(node_current); // 记录路劲

		if (k < node_current->key)
			node_current = node_current->left;
		else
			node_current = node_current->right;
	}

	// 找到位置，创建新结点
	node_current = new AVLNode<K, E>(k, e);

	// 空树
	if (node_parent == nullptr)
	{
		node = node_current;
		return true;
	}

	// 新结点插入
	if (node_current->key < node_parent->key)
		node_parent->left = node_current;
	else
		node_parent->right = node_current;

	// 重新平衡化
	while (!stack_trace.empty())
	{// 不为空
		// 获取父节点
		node_parent = stack_trace.top();
		stack_trace.pop();

		// 调整平衡因子
		if (node_current == node_parent->left)
			node_parent->balance_factor--;
		else
			node_parent->balance_factor++;

		// 3种情况分析
		// 第一种
		if (0 == node_parent->balance_factor)
			break;
		
		// 第二种 
		if (-1 == node_parent->balance_factor || 1 == node_parent->balance_factor)
			node_current = node_parent; // 保存父节点，继续向上回溯
		else
		{
			// 第三种情况 
			if (node_parent->balance_factor == 2)
			{ // 右子树高
				if (node_current->balance_factor == 1) // 左旋转
					rotate_left(node_parent);
				else                                   //  node_current->balance_factor == -1
					rotate_right_left(node_parent);
			} 
			else  //  node_parent->balance_factor == -2
			{ // 左子树高
				if (node_current->balance_factor == -1)
					rotate_right(node_parent);
				else
					rotate_left_right(node_parent);
			}

			break; // 不再向上调整
		}
	} // while

	if (stack_trace.empty())
	{
		// 调整到树的根节点
		node = node_parent;
	}
	else
	{
		// 没有调整到根节点，重新连接
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