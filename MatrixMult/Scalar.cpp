#include "Array.h"
#include <iostream>
#include "Misc.h"
#include <stdio.h>
#define M     3

using namespace std;

TVal a[M][M] = { { 2,0,3 },{ 5,1,2 },{ 0,0,4 } };
TVal b[M][M] = { { 1,3,4 },{ 2,1,2 },{ 4,0,1 } };
TVal c[M][M];

void show_matrix(TVal *matrix, int n, int m) // this functions displays matrix
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
			printf("%d ", *(matrix + i*m + j));
		printf("\n");
	}
	printf("\n");
}

void test(void)
{
	// display matrixes A and B
	show_matrix(a[0], M, M);
	show_matrix(b[0], M, M);
	for (int i = 0; i<M; i++)
		for (int j = 0; j<M; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k<M; k++) c[i][j] += a[i][k] * b[k][j];
		}
	show_matrix(c[0], M, M);
}

bool Scalar(const TMatrix& A, const TMatrix& B, TMatrix& C)
{
	if (A.isNull() || A[0].isNull() || B.isNull() || B[0].isNull())
		return false;
	size_t m = A.Count();
	TArray<TVal> tInit(m, 0);
	C = TMatrix(A[0].Count(), tInit);

	for (size_t i = 0; i < m; ++i)
		for (size_t j = 0; j < m; ++j)
			for (int k = 0; k< m; k++)
				C[i][j] += A[i][k] * B[k][j];
	return true;
}


void ScalarTest()
{
	TArray<TVal> tInit(M, 0);
	TMatrix tA(M, tInit);
	TMatrix tB(M, tInit);
	TMatrix tC;

	Init(tA, a[0], M);
	Init(tB, b[0], M);
	Scalar(tA, tB, tC);
	print(tC);
}
