#include <cstdio>
#include <cstdlib>

#include <iostream>

#include "chapter2.h"

void test()
{
	int elemA[] = {11, 13, 15, 17, 19};
	int elemB[] = {2, 4, 6, 8, 20};

	int nret = search(elemA, elemB, 5);

	std::cout << nret << std::endl;
}


int main(int argc, char *argv[])
{
	test();

	getchar();

	exit(EXIT_SUCCESS);
}