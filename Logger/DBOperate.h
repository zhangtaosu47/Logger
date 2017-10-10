#pragma once
class CDBOperate{
public:
	static CDBOperate* getInstance();
	~CDBOperate(void);

private:
	CDBOperate(void);
	static CDBOperate* instance;
};
