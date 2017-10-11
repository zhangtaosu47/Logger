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
	//��ʼ��COM���
	::CoInitialize(NULL);
	HRESULT hr = NULL;

	try
	{
		hr = m_pConnection.CreateInstance("ADODB.Connection");  //����Connection����
		//hr = m_pConnection.CreateInstance(__uuidof(Connection));����ͬ��

		//1���½�һ���ļ�����������ȡ����׺������Ϊudl�����hello.udl��
		//2��˫��hello.udl�ļ���������������������壬��д������Դ��ѡ���Լ�����������Դ���ֵģ�
		//3�����Լ��±���ʽ�򿪣������е����ݾ��������ַ�

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
	//������¼��ָ�����ʵ��
	m_pRecordSet.CreateInstance(__uuidof(Recordset));
	//�򿪼�¼��
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
	//�رռ�¼��������
	if (m_pRecordSet != NULL)
	{
		m_pRecordSet->Close();
	}
	m_pConnection->Close();
	::CoUninitialize();
}