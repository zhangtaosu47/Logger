
// LoggerDlg.h : 头文件
//

#pragma once
#include "afxdtctl.h"
#include "afxwin.h"
#include "afxcmn.h"

#include <vector>
using namespace std;

// CLoggerDlg 对话框
class CLoggerDlg : public CDialogEx
{
// 构造
public:
	CLoggerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LOGGER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtQuery();
	CComboBox m_ComboName;
	CDateTimeCtrl m_DateTimeCtrl1;
	CDateTimeCtrl m_DateTimeCtrl2;
	CMonthCalCtrl m_MonthCalCtrl1;
	CMonthCalCtrl m_MonthCalCtrl2;
	CListCtrl m_ListCtrl;

private:
	void InitListCtrl(vector < vector <CString> > vecList,vector <CString> vecColumn);
public:
	afx_msg void OnBnClickedRadio();
};
