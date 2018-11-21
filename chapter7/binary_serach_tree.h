#pragma once

/*
	����������
*/

template<typename K, typename E>
struct BSTNode
{
	BSTNode(K k = K(), E d = E(), BSTNode<E, K> *l = nullptr, BSTNode<E, K> *r = nullptr)
		:key(k), data(d), left(l), right(r)
	{

	}

	K key;  // �ؼ���
	E data; // ������
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
	else return node; // �ҵ����

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
			return insert(key, data, node->left); // ע������return�����д���
		}
		else
		{
			if (key > node->key)
			{
				return insert(key, data, node->right); // ע������return�����д���
			}
			else
			{
				return false; // �������Ѿ����ڸ�key
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
		// �ݹ�ɾ��
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
				// key ���, ��������������Ҷ���Ϊ�� �� ������һ��Ϊ��
				if (node->left != nullptr && node->right != nullptr)
				{
					// ����������������õ���һ�����
					BSTNode<K, E> *node_min = node->right;

					while (node_min->left != nullptr)
						node_min = node_min->left;

					// �滻��� �ؼ���
					node->key = node_min->key;
					node->data = node_min->data; // ͬʱҪ�����ݸ�ֵ����

					// ��������node���������У�ɾ���ո�����Ľ��
					// Ҳ�ı���ɾ���� key, Ҳ������ node �����������ɾ��node_min->key�Ľ�� 
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