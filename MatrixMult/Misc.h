#pragma once
#include <iostream>
#include <stdint.h>
#include "Array.h"

typedef uint64_t TVal;
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

inline void Save(const char* apName,const TMatrix& aA)
{
	FILE* tpFile = fopen(apName, "wb");
	size_t n = aA.Count();
	fwrite(&n, sizeof(n), 1, tpFile);
	for (size_t i = 0; i < n; ++i)
		fwrite(aA[i], sizeof(int), n, tpFile);
	fclose(tpFile);
}

inline void Init(const char* apFileName, TMatrix& aA)
{
	int m;
	FILE* tpFile = fopen(apFileName, "rb");
	fread(&m, sizeof(m), 1, tpFile);
	TVal *tA = new TVal[m*m];
	fread(tA, sizeof(int), m*m, tpFile);
	fclose(tpFile);
	TRow tInit(m, 0);
	aA = TMatrix(m, tInit);
	for (size_t i = 0; i < m; ++i)
		for (size_t j = 0; j < m; ++j)
			aA[i][j] = *(tA + i*m + j);
	delete[] tA;
}


#include <ctime>
#include <ratio>
#include <chrono>

inline std::chrono::steady_clock::time_point TimeStart()
{
	using namespace std::chrono;

	return steady_clock::now();
}


inline std::chrono::duration<double> TimeStop(std::chrono::steady_clock::time_point& t1)
{
	using namespace std::chrono;

	steady_clock::time_point t2 = steady_clock::now();

	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	std::cout << "It took me " << time_span.count() << " seconds." << std::endl;
	return time_span;
}