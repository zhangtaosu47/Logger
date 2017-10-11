#pragma once
#import "C://Program Files//Common Files//System//ado//msado15.dll" no_namespace rename("EOF","adoEOF")rename("BOF","adoBOF")

class CAdoSql  
{
private:
	CAdoSql();
public:	
	virtual ~CAdoSql();
	void InitialConn();										//连接数据库
	void ExitConn();										//断开数据库
	_RecordsetPtr GetRecordSet(CString bstrSqlCmd);			//获得记录集
	void ExcuteCmd(CString bstrSqlCmd);						//执行sql语句	
	static CAdoSql *getInstance();

public:
	_bstr_t m_bstrConn;										//存储连接数据库的字符串
	_bstr_t m_sqlCmd;										//存储sql语句
	_ConnectionPtr m_pConnection;							//连接数据库对象指针
	_RecordsetPtr  m_pRecordSet;							//数据集对象指针
	static CAdoSql *instance;
};

