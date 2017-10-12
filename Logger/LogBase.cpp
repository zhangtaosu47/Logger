#include "StdAfx.h"
#include "LogBase.h"


CLogBase::CLogBase(void)
{
}


CLogBase::~CLogBase(void)
{
}

void CLogBase::SetDay1(CString str)
{
	m_strDay1 = str;
}

void CLogBase::SetDay2(CString str)
{
	m_strDay2 = str;
}

void CLogBase::SetTime1(CString str)
{
	m_strTime1 = str;
}

void CLogBase::SetTime2(CString str)
{
	m_strTime2 = str;
}

void CLogBase::SetName(CString str)
{
	m_strName = str;
}

CString ** CLogBase::GetListItem()
{
	return m_strListItem;
}

UINT32 CLogBase::GetRows()
{
	return m_Rows;
}

UINT32 CLogBase::GetColums()
{
	return m_Colums;
}
