#include "MyStrassen.h"

void NativeMult(TStSize aN, const TStMatrix A, const TStMatrix B, TStMatrix C)
{
	TStSize i, j, k;
	for (i = 0; i < aN; i++)
	{
		for (j = 0; j < aN; j++)
		{
			for (k = 0; k < aN; k++)
				C[IDX(i,j)] += A[IDX(i,k)] * B[IDX(k,j)];
		}
	}
}

void StMult(TStSize aN, const TStMatrix A, const TStMatrix B, TStMatrix C)
{
	if (aN < LEAF)
	{

	}
	else
	{

	}
}