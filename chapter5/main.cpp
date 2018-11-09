#include <cstdio>
#include <cstdlib>

#include <iostream>

#include "binary_tree.h"

void test_binary_tree()
{
	binary_tree<char> tree;

	// "A(B(D,E(G,)),C(,F))#"
	//std::cin >> tree;

	// 103
	tree.create_binary_tree("A(B(D,E(G,)),C(,F))#");
	
	std::cout << tree;
}

int main(int argc, char *argv[])
{
	test_binary_tree();

	getchar();

	exit(EXIT_SUCCESS);
}