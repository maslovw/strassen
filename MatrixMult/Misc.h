#pragma once
#include <iostream>
#include <stdint.h>
#include "Array.h"

typedef uint32_t TVal;
typedef TArray<TVal> TRow;
typedef TArray<TRow> TMatrix;

inline void print(const TMatrix& aArr)
{
	for (size_t i = 0; i < aArr.Count(); ++i)
	{
		for (size_t j = 0; j < aArr[0].Count(); ++j)
			std::cout << int(aArr[i][j]) << "\t";

		std::cout << std::endl;
	}
}

inline void Init(TMatrix& aA, TVal *matrix, size_t m)
{
	for (size_t i = 0; i < m; ++i)
		for (size_t j = 0; j < m; ++j)
			aA[i][j] = *(matrix + i*m + j);
}
