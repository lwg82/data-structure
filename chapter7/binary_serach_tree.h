#pragma once

/*
	二叉搜索树
*/

template<typename K, typename E>
struct BSTNode
{
	BSTNode(K k = K(), E d = E(), BSTNode<E, K> *l = nullptr, BSTNode<E, K> *r = nullptr)
		:key(k), data(d), left(l), right(r)
	{

	}

	K key;  // 关键码
	E data; // 数据域
	BSTNode<E, K> *left, *right;

	
};

template<typename K, typename E>
class BST
{
public:
	BST():root(nullptr) {}

	BSTNode<K, E> *serach(const K &key) { return search(key, root); }
	
	bool           insert(const K &key, const E &data) { return insert(key, data, root); }

	bool           remove(const K &key) { return remove(key, root); }

	void inOrder() { inOrder(root); }

private:
	BSTNode<K, E> * search(const K &key, BSTNode<K, E> *node);

	bool insert(const K &key, const E &data, BSTNode<K, E> *&node);

	bool remove(const K &key, BSTNode<K, E> *&node);

	void inOrder(BSTNode<K, E> *subTree);
private:
	BSTNode<K, E> *root;
};

template<typename K, typename E>
BSTNode<K, E>* BST<K, E>::search(const K &key, BSTNode<K, E> *node)
{
	if (nullptr == node)
		return nullptr;

	if (key < node->key)
		serach(key, node->left);
	else if (key > node->key)
		search(key, node->right);
	else return node; // 找到结点

	return nullptr;
}


template<typename K, typename E>
bool BST<K, E>::insert(const K &key, const E &data, BSTNode<K, E> *&node)
{
	if (nullptr == node)
	{
		node = new BSTNode<K, E>(key, data);

		return true;
	}
	else
	{
		if (key < node->key)
		{
			return insert(key, data, node->left); // 注意这里return，书中错误
		}
		else
		{
			if (key > node->key)
			{
				return insert(key, data, node->right); // 注意这里return，书中错误
			}
			else
			{
				return false; // 在树中已经存在该key
			}
		}
	}
}

template<typename K, typename E>
void BST<K, E>::inOrder(BSTNode<K, E> *subTree)
{
	if (subTree != nullptr)
	{
		inOrder(subTree->left);
		std::cout << "key = " << subTree->key << " value =" << subTree->data << std::endl;
		inOrder(subTree->right);
	}
}

template<typename K, typename E>
bool BST<K, E>::remove(const K &key, BSTNode<K, E> *&node)
{
	if (nullptr != node)
	{
		// 递归删除
		if (key < node->key)
		{
			return remove(key, node->left);
		}
		else
		{
			if (key > node->key)
			{
				return remove(key, node->right);
			}
			else
			{
				// key 相等, 分两种情况，左右都不为空 或， 左右有一个为空
				if (node->left != nullptr && node->right != nullptr)
				{
					// 中序遍历右子树，得到第一个结点
					BSTNode<K, E> *node_min = node->right;

					while (node_min->left != nullptr)
						node_min = node_min->left;

					// 替换结点 关键码
					node->key = node_min->key;
					node->data = node_min->data; // 同时要把数据赋值过来

					// 这里是在node的右子树中，删除刚刚上提的结点
					// 也改变了删除的 key, 也就是在 node 结点右子树中删除node_min->key的结点 
					return remove(node_min->key, node->right);

				}
				else
				{
					BSTNode<K, E> *node_del = node;

					if (nullptr == node->left)
					{
						node = node->right;
					}
					else
					{
						node = node->left;
					}

					delete node_del;

					return true;
				}
			}
		}
	}
	return false;
}