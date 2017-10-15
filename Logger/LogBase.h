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
	vector < vector <CString> > GetVecList();
	vector <CString> GetVecColumn();

protected:
	CString m_strDay1;
	CString m_strDay2;
	CString m_strTime1;
	CString m_strTime2;
	CString m_strName;
	vector < vector <CString> > m_vecList;
	vector <CString> m_vecColumn;
};

