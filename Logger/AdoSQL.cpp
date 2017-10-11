#include "StdAfx.h"
#include "AdoSQL.h"

CAdoSql *CAdoSql::instance = NULL;

CAdoSql::CAdoSql()
{
	m_pConnection = NULL;
	m_pRecordSet = NULL;
	InitialConn();
}

CAdoSql::~CAdoSql()
{
	ExitConn();
}

CAdoSql *CAdoSql::getInstance()
{
	if(NULL == instance)
	{
		instance = new CAdoSql();
	}

	return instance;
}

void CAdoSql::InitialConn()
{
	//初始化COM组件
	::CoInitialize(NULL);
	HRESULT hr = NULL;

	try
	{
		hr = m_pConnection.CreateInstance("ADODB.Connection");  //创建Connection对象
		//hr = m_pConnection.CreateInstance(__uuidof(Connection));作用同上

		//1、新建一个文件，名字任意取，后缀名必须为udl（如何hello.udl）
		//2、双击hello.udl文件，进入数据连接属性面板，填写好数据源（选择自己创建的数据源名字的）
		//3、再以记事本方式打开，第三行的数据就是连接字符

		//m_bstrConn = "Provider=SQLNCLI10.1;Integrated Security="";Persist Security Info=False;User ID=sa;Password=123456;Initial Catalog=WORK;Data Source="";Initial File Name="";Server SPN=""";
		//m_bstrConn = "Provider=SQLOLEDB;Integrated Security="";Persist Security Info=False;Initial Catalog=WORK;Data Source="";Initial File Name="";Server SPN=""";
		m_bstrConn = "Provider=SQLOLEDB.1;Password=123456;Persist Security Info=True;User ID=sa;Initial Catalog=TestDB;Data Source=X6X8-20160219EX";

		hr = m_pConnection->Open(m_bstrConn, "", "", adModeUnknown);
		if (!SUCCEEDED(hr)) {
			OutputDebugString(L"Connect DB failed.");
		}
	}
	catch (_com_error e)
	{
		CString strErr;
		strErr.Format(L"Connect DB failed.\n%s", e.ErrorMessage());
		OutputDebugString(strErr);
	}
}

_RecordsetPtr CAdoSql::GetRecordSet(CString bstrSqlCmd)
{
	m_sqlCmd = _bstr_t(bstrSqlCmd);
	//创建记录集指针对象实例
	m_pRecordSet.CreateInstance(__uuidof(Recordset));
	//打开记录集
	m_pRecordSet->Open(m_sqlCmd, m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	return m_pRecordSet;	
}

void CAdoSql::ExcuteCmd(CString bstrSqlCmd)
{
	m_sqlCmd = _bstr_t(bstrSqlCmd);
	_variant_t RecordsAffected;

	try{
		m_pRecordSet = m_pConnection->Execute(m_sqlCmd, &RecordsAffected, adCmdText);
	}
	catch(_com_error e) {
		OutputDebugString(e.ErrorMessage());
	}
}

void CAdoSql::ExitConn()
{
	//关闭记录集和连接
	if (m_pRecordSet != NULL)
	{
		m_pRecordSet->Close();
	}
	m_pConnection->Close();
	::CoUninitialize();
}