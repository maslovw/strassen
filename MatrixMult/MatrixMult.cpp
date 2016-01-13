// MatrixMult.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <stdint.h>
#include "Misc.h"
#include "Scalar.h"
#include "Strassen.h"

int main()
{
	ScalarTest();
	std::cout << std::endl;
	StrassenTest();
    return 0;
}

