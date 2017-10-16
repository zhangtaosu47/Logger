
// LoggerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Logger.h"
#include "LoggerDlg.h"
#include "afxdialogex.h"

#include "LogBase.h"
#include "LogDelete.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <vector>
using namespace std;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLoggerDlg �Ի���




CLoggerDlg::CLoggerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoggerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLoggerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_DateTimeCtrl1);
	DDX_Control(pDX, IDC_COMBO1, m_ComboName);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_DateTimeCtrl2);
	DDX_Control(pDX, IDC_MONTHCALENDAR1, m_MonthCalCtrl1);
	DDX_Control(pDX, IDC_MONTHCALENDAR2, m_MonthCalCtrl2);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
}

BEGIN_MESSAGE_MAP(CLoggerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BT_QUERY, &CLoggerDlg::OnBnClickedBtQuery)
	ON_BN_CLICKED(IDC_RADIO_DELETE, &CLoggerDlg::OnBnClickedRadioDelete)
	ON_BN_CLICKED(IDC_RADIO_RESPOND, &CLoggerDlg::OnBnClickedRadioRespond)
END_MESSAGE_MAP()

// CLoggerDlg ��Ϣ�������

BOOL CLoggerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//added by zh.t
	m_ComboName.ResetContent();
	m_ComboName.InsertString(0,L"��");
	m_ComboName.InsertString(1,L"ȫ��");
	m_ComboName.InsertString(2,L"��ʩȫ");
	m_ComboName.InsertString(3,L"������");
	m_ComboName.InsertString(4,L"����");
	m_ComboName.InsertString(5,L"�³�");
	m_ComboName.InsertString(6,L"����");
	m_ComboName.InsertString(7,L"��־�");
	m_ComboName.InsertString(8,L"��ʢ��");
	m_ComboName.InsertString(9,L"����");
	m_ComboName.InsertString(10,L"�޾���");
	m_ComboName.SetCurSel(0);

	//���͡�ɾ������ť���µ���Ϣ
	PostMessage(WM_COMMAND, MAKEWPARAM(IDC_RADIO_DELETE, BN_CLICKED), NULL);  
	((CButton *)GetDlgItem(IDC_RADIO_DELETE))->SetCheck(TRUE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CLoggerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLoggerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CLoggerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLoggerDlg::OnBnClickedBtQuery()
{	
	//ȡ���ı����ַ��ķ���
	/*CEdit* pBoxOne;
	pBoxOne = (CEdit*) GetDlgItem(IDC_EDIT_TEST);
	CString str;
	pBoxOne-> GetWindowText(str);
	OutputDebugString(str + "\n");*/

	CLogBase *pLogDelete = new CLogDelete();
	CString strSQL;

	//ȡ��MonthCalCtrl����
	CTime dt;
	m_MonthCalCtrl1.GetCurSel(dt);
	CString str_Day1;
	str_Day1 = dt.Format("%Y-%m-%d");
	OutputDebugString(str_Day1 + "\n");


	//ȡ��MonthCalCtr2����	
	m_MonthCalCtrl2.GetCurSel(dt);
	CString str_Day2;
	str_Day2 = dt.Format("%Y-%m-%d");
	OutputDebugString(str_Day2 + "\n");

	//ȡ��DateTimeCtrll���ڵķ���
	CTime tm;
	m_DateTimeCtrl1.GetTime(tm);
	CString str_Time1 = tm.Format("%H:%M:%S");
	m_DateTimeCtrl2.GetTime(tm);
	CString str_Time2 = tm.Format("%H:%M:%S");
	OutputDebugString(str_Time1 + "\n");
	OutputDebugString(str_Time2 + "\n");

	//combo
	int nIndex;
	CString str_Name;
	nIndex = m_ComboName.GetCurSel();
	m_ComboName.GetLBText(nIndex,str_Name);
	OutputDebugString(str_Name + "\n");

	pLogDelete->SetDay1(str_Day1);
	pLogDelete->SetDay2(str_Day2);
	pLogDelete->SetTime1(str_Time1);
	pLogDelete->SetTime2(str_Time2);
	pLogDelete->SetName(str_Name);
	pLogDelete->DoSomething();	

	vector < vector <CString> >::iterator it1;
	vector <CString>::iterator it2;
	vector < vector <CString> > vecList = pLogDelete->GetVecList();
	/*for(it1=vecList.begin();it1!=vecList.end();++it1)
	{
	for(it2=it1->begin();it2!=it1->end();++it2)
	{
	OutputDebugString(*it2 + L" ");
	}
	OutputDebugString(L"\n");
	}*/

	vector <CString> vecColumn = pLogDelete->GetVecColumn();

	InitListCtrl(vecList,vecColumn);

	delete pLogDelete;
	pLogDelete = NULL;	
}

void CLoggerDlg::InitListCtrl(vector < vector <CString> > vecList,vector <CString> vecColumn)
{
	DWORD dwStyle = m_ListCtrl.GetExtendedStyle();     
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_ListCtrl.SetExtendedStyle(dwStyle);

	for (UINT i=0;i<vecColumn.size();++i)
	{
		m_ListCtrl.InsertColumn(i,vecColumn[i],LVCFMT_LEFT, 60);
	}

	for (UINT i=0;i<vecList.size();++i)
	{
		for (UINT j=0;j<vecList[i].size();++j)
		{
			if(0 == j)
			{
				m_ListCtrl.InsertItem(i,vecList[i][j]);
			}
			else
			{
				m_ListCtrl.SetItemText(i,j,vecList[i][j]);
			}
		}
	}
}

CLoggerDlg::RADIO_STATUS CLoggerDlg::GetRadioStatus()
{
	BOOL bRadio = FALSE;
	bRadio = ((CButton *)GetDlgItem(IDC_RADIO_DELETE))->GetCheck();
	if(TRUE == bRadio)
	{
		return RECORD_DELETE;
	}

	bRadio = ((CButton *)GetDlgItem(IDC_RADIO_RESPOND))->GetCheck();
	if(TRUE == bRadio)
	{
		return RECORD_RESPOND;
	}

	return RECORD_DELETE;
}

void CLoggerDlg::SetOperation(RADIO_STATUS status)
{
	switch(status)
	{
		case RECORD_DELETE:
			{
				((CButton *)GetDlgItem(IDC_BT_OPERATION))->SetWindowTextW(L"ɾ��");
				break;
			}
		case  RECORD_RESPOND:
			{
				((CButton *)GetDlgItem(IDC_BT_OPERATION))->SetWindowTextW(L"Ӧ��");
				break;
			}
		default:
			{
				OutputDebugString(L"Operation code error!\n");
			}
	}
}

void CLoggerDlg::OnBnClickedRadioDelete()
{
	SetOperation(RECORD_DELETE);
}

void CLoggerDlg::OnBnClickedRadioRespond()
{
	SetOperation(RECORD_RESPOND);
}
