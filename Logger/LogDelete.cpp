#include "StdAfx.h"
#include "LogDelete.h"
#include "DBOperate.h"
#include "AdoSQL.h"
#include "Common.h"

CLogDelete::CLogDelete(void)
{
}

CLogDelete::~CLogDelete(void)
{
}

BOOL CLogDelete::DoExcuteCmd()
{
	PADOSQL db = NULL;
	try
	{
		db = CAdoSql::getInstance();
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	
	CString strSQL = L"DELETE " + CCommon::STRING_FROM_SQL;
	db->ExcuteCmd(strSQL);

	return TRUE;
}