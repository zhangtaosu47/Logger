#include "StdAfx.h"
#include "LogDelete.h"
#include "DBOperate.h"


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

	CDBOperate *db = CDBOperate::getInstance();
	if(!db)
	{
		OutputDebugString(L"Cannot get DB");
		return false;
	}

	CString strSQL;
	strSQL += L"DELETE * FROM UC_alarmlog WHERE almt > '" + m_strDay1 + L" " + m_strTime1 + L"' ";
	strSQL += L"AND almt < '" + m_strDay2 + L" " + m_strTime2 + L"' ";
	strSQL += L"AND reviewer = '" + m_strName + L"'";

	db->execSQL(strSQL);

	return true;
}