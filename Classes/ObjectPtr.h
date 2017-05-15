#pragma once
#include "TObject.h"

class ObjectPtr
{
	TObject * Ptr = nullptr;
public:
	ObjectPtr()
	{}

	void operator=(TObject * ptr)
	{
		delete Ptr;
		Ptr = ptr;
	}

	ObjectPtr(TObject * ptr)
		: Ptr(ptr)
	{ }

	~ObjectPtr()
	{
		delete Ptr;
	}

	TObject& operator*()
	{
		return *Ptr;
	}

	TObject* operator->()
	{
		return Ptr;
	}

	TObject * Get()
	{
		return Ptr;
	}

	operator bool()
	{
		return Ptr != nullptr;
	}
};