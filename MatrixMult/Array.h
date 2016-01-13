
#ifndef Array_h__
#define Array_h__
#include "stddef.h"
#define	MIN(a, b)						((a) < (b) ? (a) :(b))
template <typename T> 
class TArray 
{
private:
	size_t mCount;
	T *pData;

public:
	TArray () : mCount (0), pData (nullptr) {}

	TArray (size_t aCount) : mCount (aCount),
		pData (new T[aCount])
	{  }

	TArray (size_t aCount, const T& aFillVal) : mCount (aCount),
		pData (new T[aCount])
	{ 
		Fill (aFillVal);
	}

	// ����������� �����������
	TArray (const TArray&);

	// ����������� �����������
	TArray (TArray&&);


	// ����������� ��� �-�������� �������� 
	template<size_t aCount>
	TArray (const T (&apArr)[aCount], size_t aSize = aCount) :
		mCount (aSize),
		pData (new T[aSize])
	{
		Copy (apArr, aSize);
	}


	// ����������� �-�������� �������� ���������� malloc-��
	TArray (const T *const apArr, size_t aCount) :
		mCount (aCount),
		pData (new T[aCount])
	{}

	~TArray () { if (pData) delete [] pData;}

	inline T*		  Get ()		  { return pData; }
	inline const T*   Get ()	const { return pData; }
	inline bool	   isNull ()	const { return pData == nullptr; }
	inline size_t	 Size ()	const { return mCount * sizeof(T); }		// ������ ������
	inline size_t	Count ()	const { return mCount; }					// ���������� ��������� ���� T � ������

	//�������������� �����
	inline operator const T* () const { return pData; }
	inline operator	      T* ()	      { return pData; }
	inline operator   size_t ()	const { return Size (); }
	inline operator     bool ()	const { return pData != nullptr; }
		
	TArray& Release () { mCount = 0; if (pData) delete[] pData; pData = nullptr; return *this; } //������������ ������

	// �������� �����������
	TArray& operator= (const TArray&);
	// �������� �����������
	TArray& operator= (TArray&&);

	TArray& Copy (const T* aPtr, size_t aCount) 
	{
		for (size_t i = 0; i < MIN(mCount, aCount); ++i)
			pData [i] = aPtr [i];
		return *this;
	}

	TArray& Copy (const TArray<T>& aPtr)
	{
		for (size_t i = 0; i < MIN (mCount, aPtr.mCount); ++i)
			pData[i] = aPtr[i];
		return *this;
	}

	TArray& Fill (const T& aValue)
	{
		for (size_t i = 0; i < mCount; ++i)
			pData[i] = aValue;
		return *this;
	}
};



// ����������� �����������
template <typename T>
TArray<T>::TArray (const TArray& aArr): 
mCount (aArr.mCount),
pData (new T[aArr.mCount])
{
	Copy (aArr.pData, aArr.mCount);
}


// ����������� �����������
template <typename T>
TArray<T>::TArray (TArray&& aArr) :
mCount (aArr.mCount),
pData (aArr.pData)
{
	aArr.mCount = 0;
	aArr.pData = nullptr;
}


// �������� �����������
template <typename T>
TArray<T>& TArray<T>::operator=(const TArray& aArr)
{
	if (this == &aArr)
		return *this;
	if (mCount != aArr.mCount)
	{
		if (pData) 
			delete[] pData;
		mCount = aArr.mCount;
		pData = (mCount > 0) ? new T[aArr.mCount] : nullptr;
	}
	if (pData)
		Copy (aArr.pData, aArr.mCount);
	return *this;
}

// �������� �����������
template <typename T>
TArray<T>& TArray<T>::operator=(TArray&& aArr)
{
	if (this == &aArr)
		return *this;
	if (pData)
		delete[] pData;
	mCount = aArr.mCount;
	pData = aArr.pData;
	aArr.mCount = 0;
	aArr.pData = nullptr;

	return *this;
}



#endif // Array_h__



