#pragma once
#include "logbase.h"
class CLogDelete :	public CLogBase
{
public:
	CLogDelete(void);
	~CLogDelete(void);
	virtual bool DoSomething();
};

