#include "StdAfx.h"
#include "DBOperate.h"

CDBOperate* CDBOperate::instance = NULL;

CDBOperate::CDBOperate(void)
{
}

CDBOperate::~CDBOperate(void)
{
}

CDBOperate* CDBOperate::getInstance(){
	if(NULL == instance)
	{
		instance = new CDBOperate();
	}

	return instance;
}

void CDBOperate::execSQL(CString strSQL)
{
	OutputDebugString(L"SQL = " + strSQL);
}
