#pragma once
#include "TSubject.h"

class SubjectPtr
{
	TSubject * Ptr = nullptr;
public:
	SubjectPtr() = default;

	void operator=(TSubject * ptr)
	{
		delete Ptr;
		Ptr = ptr;
	}

	SubjectPtr(TSubject * ptr)
		: Ptr(ptr)
	{ }

	~SubjectPtr()
	{
		delete Ptr;
	}

	TSubject& operator*()
	{
		return *Ptr;
	}

	TSubject* operator->()
	{
		return Ptr;
	}

	TSubject * Get()
	{
		return Ptr;
	}

	operator bool()
	{
		return Ptr != nullptr;
	}
};