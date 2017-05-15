#pragma once 
#include "TObject.h"

class TBomb : public TObject
{
public:
	TBomb();

	TBomb(float x, float y, const std::string & fileName);

	virtual ~TBomb() = default;
};