#include <cstdio>
#include <cstdlib>

#include <iostream>

#include "binary_tree.h"

template<typename T>
void visit(binary_tree_node<T>* node)
{
	std::cout << node->data;
}

void test_binary_tree()
{
	binary_tree<char> tree;

	// "A(B(D,E(G,)),C(,F))#"
	//std::cin >> tree;

	// 103
	// tree.create_binary_tree("A(B(D,E(G,)),C(,F))#");
	//std::cout << tree;

/*
	tree.create_binary_tree("-(+(a,*(b,-(c,d))),/(e,f))#");

	tree.preOrder(visit);
	std::cout << std::endl;

	tree.inOrder(visit);
	std::cout << std::endl;

	tree.postOrder(visit);
	std::cout << std::endl;

	std::cout << "size=" << tree.size() << std::endl;
	std::cout << "height=" << tree.height() << std::endl;
*/

	binary_tree<char> tree1;
	tree1.create_binary_tree("A(B(D,E(G,)),C(,F))#");
	std::cout << tree1;
	std::cout << std::endl;

	binary_tree<char> tree2(tree1);
	std::cout << tree2;
	std::cout << std::endl;

	std::cout << ((tree1 == tree2)? "t":"f") << std::endl;
	std::cout << ((tree1 != tree2) ? "t" : "f") << std::endl;
}

int main(int argc, char *argv[])
{
	test_binary_tree();

	getchar();

	exit(EXIT_SUCCESS);
}