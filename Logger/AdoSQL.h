#pragma once
#import "C://Program Files//Common Files//System//ado//msado15.dll" no_namespace rename("EOF","adoEOF")rename("BOF","adoBOF")

class CAdoSql  
{
private:
	CAdoSql();
public:	
	virtual ~CAdoSql();
	void InitialConn();										//�������ݿ�
	void ExitConn();										//�Ͽ����ݿ�
	_RecordsetPtr GetRecordSet(CString bstrSqlCmd);			//��ü�¼��
	void ExcuteCmd(CString bstrSqlCmd);						//ִ��sql���	
	static CAdoSql *getInstance();

public:
	_bstr_t m_bstrConn;										//�洢�������ݿ���ַ���
	_bstr_t m_sqlCmd;										//�洢sql���
	_ConnectionPtr m_pConnection;							//�������ݿ����ָ��
	_RecordsetPtr  m_pRecordSet;							//���ݼ�����ָ��
	static CAdoSql *instance;
};

