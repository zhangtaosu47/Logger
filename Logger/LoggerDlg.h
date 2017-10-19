
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

// Radio��״̬
	enum RADIO_STATUS{RECORD_DELETE = 0,RECORD_RESPOND};

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
	CComboBox m_ComboName;
	CDateTimeCtrl m_DateTimeCtrl1;
	CDateTimeCtrl m_DateTimeCtrl2;
	CMonthCalCtrl m_MonthCalCtrl1;
	CMonthCalCtrl m_MonthCalCtrl2;
	CListCtrl m_ListCtrl;
	RADIO_STATUS m_RadioStatus;

private:
	void InitListCtrl(vector < vector <CString> > vecList,vector <CString> vecColumn);
//	RADIO_STATUS GetRadioStatus();
public:
	afx_msg void OnBnClickedRadio();
	afx_msg void OnBnClickedRadioDelete();
	afx_msg void OnBnClickedRadioRespond();
	afx_msg void OnBnClickedBtOperation();
	afx_msg void OnBnClickedBtQuery();
};
