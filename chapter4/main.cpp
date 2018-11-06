#include <cstdio>
#include <cstdlib>

#include <iostream>

#include "sparse_matrix.h"

void test_sparse_matrix()
{
	sparse_matrix<int> matrix;

	/*
		0 1 2

	0	0 1 0
	1	2 0 3
	2	0 5 0
	3	9 0 6
	*/

	matrix.rows = 4;
	matrix.cols = 3;
	matrix.terms = 6;

	matrix.elems[0].row = 0;
	matrix.elems[0].col = 1;
	matrix.elems[0].data = 1;

	matrix.elems[1].row = 1;
	matrix.elems[1].col = 0;
	matrix.elems[1].data = 2;

	matrix.elems[2].row = 1;
	matrix.elems[2].col = 2;
	matrix.elems[2].data = 3;

	matrix.elems[3].row = 2;
	matrix.elems[3].col = 1;
	matrix.elems[3].data = 5;

	matrix.elems[4].row = 3;
	matrix.elems[4].col = 0;
	matrix.elems[4].data = 9;

	matrix.elems[5].row = 3;
	matrix.elems[5].col = 2;
	matrix.elems[5].data = 6;

	std::cout << matrix;
}

int main(int argc, char *argv[])
{
	test_sparse_matrix();

	getchar();

	exit(EXIT_SUCCESS);
}