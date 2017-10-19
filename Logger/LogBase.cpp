#include "StdAfx.h"
#include "LogBase.h"
#include "Common.h"


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

BOOL CLogBase::DoExcuteCmd()
{	
	return TRUE;
}

BOOL CLogBase::DoSearch()
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

	CString strSQL = L"SELECT * ";
	m_strSQL = L"FROM UC_alarmlog WHERE almt > '" + m_strDay1 + L" " + m_strTime1 + L"' ";
	m_strSQL += L"AND almt < '" + m_strDay2 + L" " + m_strTime2 + L"' ";
	m_strSQL += L"AND reviewer = '" + m_strName + L"'";

	strSQL += m_strSQL;
	CCommon::STRING_FROM_SQL = m_strSQL;
	CString strSQL2 = L"SELECT * FROM lala";
	_RecordsetPtr rs = db->GetRecordSet(strSQL2);

	m_vecList.clear();
	m_vecList.swap(vector < vector <CString> >());
	m_vecColumn.clear();
	m_vecColumn.swap(vector <CString>());

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
			CString str;
			if(v.vt != VT_NULL)
			{
				str = (TCHAR*)(_bstr_t)v;			
			}

			vecRow.push_back(str);
		}
		m_vecList.push_back(vecRow);
		vecRow.clear();
		rs->MoveNext();
	}

	return TRUE;
}

vector < vector <CString> > CLogBase::GetVecList()
{
	return m_vecList;
}

vector <CString> CLogBase::GetVecColumn()
{
	return m_vecColumn;
}
