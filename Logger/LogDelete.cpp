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

	for (int i=0;i<rs->GetFields()->GetCount();++i)
	{
		CString strTemp;
		strTemp.Format(L"%s",(LPCTSTR)rs->GetFields()->GetItem((long)i)->GetName());
		m_vecColumn.push_back(strTemp);
	}

	vector <CString> vecRow;
	while(!rs->adoEOF)
	{		
		for(int i=0;i<rs->GetFields()->GetCount();++i)
		{			
			_variant_t v = rs->GetFields()->GetItem((long)i)->Value;
			CString str = (TCHAR*)(_bstr_t)v;			
			vecRow.push_back(str);
		}
		m_vecList.push_back(vecRow);
		vecRow.clear();
		rs->MoveNext();
	}

	//strSQL2 = L"update lala set name = 'WAWA' where name = 'MOO'";
	//db->ExcuteCmd(strSQL2);

	return true;
}