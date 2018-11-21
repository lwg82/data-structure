#include <cstdio>
#include <cstdlib>

#include <iostream>

#include "binary_serach_tree.h"
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

int main(int argc, char *argv[])
{
	test_binary_search_tree();

	getchar();

	exit(EXIT_SUCCESS);
}