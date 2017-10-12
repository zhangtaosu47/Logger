#include "StdAfx.h"
#include "LogDelete.h"
#include "DBOperate.h"
#include "AdoSQL.h"

CLogDelete::CLogDelete(void)
{
}

CLogDelete::~CLogDelete(void)
{
}

bool CLogDelete::DoSomething()
{
	PADOSQL db = CAdoSql::getInstance();

	CString strSQL;
	strSQL += L"DELETE * FROM UC_alarmlog WHERE almt > '" + m_strDay1 + L" " + m_strTime1 + L"' ";
	strSQL += L"AND almt < '" + m_strDay2 + L" " + m_strTime2 + L"' ";
	strSQL += L"AND reviewer = '" + m_strName + L"'";

	CString strSQL2 = L"SELECT * FROM lala";
	_RecordsetPtr rs = db->GetRecordSet(strSQL2);
	m_Rows = rs->GetRecordCount();
	m_Colums = rs->GetFields()->GetCount();

	m_strListItem = new CString *[rs->GetRecordCount()];	
	int j = 0;
	while(!rs->adoEOF)
	{
		m_strListItem[j] = new CString [rs->GetFields()->GetCount()];
		for(int i=0;i<rs->GetFields()->GetCount();++i)
		{			
			_variant_t v = rs->GetFields()->GetItem((long)i)->Value;
			CString str = (TCHAR*)(_bstr_t)v;
			m_strListItem[j][i] = str;
//			OutputDebugString(str + "  ");
		}
//		OutputDebugString(L"\n");
		j++;
		rs->MoveNext();
	}

	//strSQL2 = L"update lala set name = 'WAWA' where name = 'MOO'";
	//db->ExcuteCmd(strSQL2);

	return true;
}