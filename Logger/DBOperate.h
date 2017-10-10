#pragma once
class CDBOperate{
public:	
	~CDBOperate(void);
	static CDBOperate* getInstance();
	static void execSQL(CString strSQL);
private:
	CDBOperate(void);
	static CDBOperate* instance;
};
