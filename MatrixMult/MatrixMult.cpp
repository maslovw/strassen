// MatrixMult.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <stdint.h>
#include "Misc.h"
#include "Scalar.h"
#include "Strassen.h"
#include "StrassenC.h"
#include <fstream>
#include<stdlib.h>
using namespace std;

extern "C"
void StrassenCTest(const char* apFileName);

void Generate(const char* apName, int n)
{
	int *tA = new int[n*n];
	for (int i = 0; i < n*n; ++i)
	{
		tA[i] = rand();
	}
	FILE* tpFile = fopen(apName, "wb");
	fwrite(&n, sizeof(n), 1, tpFile);
	fwrite(tA, sizeof(int), n*n, tpFile);
	fclose(tpFile);
	delete [] tA;
}

bool isFilesEqual(const std::string& lFilePath, const std::string& rFilePath) 
{
	std::ifstream lFile(lFilePath.c_str(), std::ifstream::in | std::ifstream::binary);
	std::ifstream rFile(rFilePath.c_str(), std::ifstream::in | std::ifstream::binary);

	if (!lFile.is_open() || !rFile.is_open())
	{
		return false;
	}
	const size_t BUFFER_SIZE = 1024;
	char *lBuffer = new char[BUFFER_SIZE]();
	char *rBuffer = new char[BUFFER_SIZE]();

	do
	{
		lFile.read(lBuffer, BUFFER_SIZE);
		rFile.read(rBuffer, BUFFER_SIZE);
		auto numberOfRead = lFile.gcount();//I check the files with the same size

		if (std::memcmp(lBuffer, rBuffer, numberOfRead) != 0)
		{
			memset(lBuffer, 0, numberOfRead);
			memset(rBuffer, 0, numberOfRead);
			return false;
		}
	} while (lFile.good() || rFile.good());

	delete [] lBuffer;
	delete [] rBuffer;
	return true;
}

int main()
{
	Generate("a.bin", 1*1024);
	Generate("b.bin", 1*1024);
	//return 0;
	cout << "Scalar" << endl;
	//ScalarTest("sc.bin");
	std::cout << std::endl;
	cout << "Strassen C++" << endl;
	StrassenTest("ss.bin");
	cout << "files eq=" << isFilesEqual("sc.bin", "ss.bin") << endl;
	return 0;
	cout << "Strassen C" << endl;
	StrassenCTest("ssc.bin");
	cout << "files eq=" << isFilesEqual("sc.bin", "ssc.bin") << endl;
    return 0;
}

