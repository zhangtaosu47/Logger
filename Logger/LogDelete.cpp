#include "StdAfx.h"
#include "LogDelete.h"


CLogDelete::CLogDelete(void)
{
}


CLogDelete::~CLogDelete(void)
{
}

bool CLogDelete::DoSomething()
{
	OutputDebugString(L"CLogDelete::DoSomething");
	OutputDebugString(m_strDay1 + "\n");
	OutputDebugString(m_strDay2 + "\n");
	OutputDebugString(m_strTime1 + "\n");
	OutputDebugString(m_strTime2 + "\n");
	OutputDebugString(m_strName + "\n");
	return true;
}