#pragma once

typedef unsigned long TStSize;
typedef unsigned long TStVal;
typedef TStVal* TStMatrix;

#define IDX(X, Y) (aN * Y + X)    // rows first
#define LEAF (TStSize)5


void StMult(TStSize aN, const TStMatrix A, const TStMatrix B, TStMatrix C);
