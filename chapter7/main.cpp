#include <cstdio>
#include <cstdlib>

#include <iostream>

#include "binary_serach_tree.h"
#include "avl_tree.h"

/*

		
*/
void test_binary_search_tree()
{
	// 53 
	BST<int, int> bst;

	bst.insert(53, 53);
	bst.insert(78, 78);
	bst.insert(17, 17);
	bst.insert(45, 45);
	bst.insert(9, 9);
	bst.insert(23, 23);

	bst.insert(94, 94);
	bst.insert(65, 65);

	bst.insert(81, 81);
	bst.insert(88, 88);

	bst.inOrder();

	//bst.remove(9);
	//bst.remove(17);
	std::cout << (bst.remove(78) ? "true" : "false") << std::endl;;
	std::cout << (bst.remove(99) ? "true" : "false") << std::endl;;

	bst.inOrder();
}

void test_avl_tree()
{
	AVLTree<int, int> avl;

	avl.insert(16, 16);
	avl.insert(3, 3);
	//std::cout << avl;
	

	avl.insert(7, 7);
	//std::cout << avl;

	avl.insert(11, 11);
	avl.insert(9, 9);
	avl.insert(26, 26);
	avl.insert(18, 18);
	avl.insert(14, 14);
	avl.insert(15, 15);

	std::cout << avl;


	std::cout  << "比对次数:" << avl.get_counter() << " key= " << avl.search(14)->key; // 右结合
}

int main(int argc, char *argv[])
{
	//test_binary_search_tree();
	test_avl_tree();

	getchar();

	exit(EXIT_SUCCESS);
}