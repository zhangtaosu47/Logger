#pragma once
#include <vector>
using namespace std;
class CLogBase
{	
public:
	CLogBase(void);
	~CLogBase(void);
	void SetDay1(CString str);
	void SetDay2(CString str);
	void SetTime1(CString str);
	void SetTime2(CString str);
	void SetName(CString str);
	virtual bool DoSomething() = 0;
	CString **GetListItem();
	UINT32 GetRows();
	UINT32 GetColums();
	vector < vector <CString> > GetVecList();

protected:
	CString m_strDay1;
	CString m_strDay2;
	CString m_strTime1;
	CString m_strTime2;
	CString m_strName;
	CString **m_strListItem;
	vector < vector <CString> > m_vecList;
	UINT32	m_Rows;
	UINT32	m_Colums;
};

