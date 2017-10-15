
// LoggerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxdtctl.h"
#include "afxwin.h"
#include "afxcmn.h"

#include <vector>
using namespace std;

// CLoggerDlg �Ի���
class CLoggerDlg : public CDialogEx
{
// ����
public:
	CLoggerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LOGGER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
