
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
}

BEGIN_MESSAGE_MAP(CLoggerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BT_QUERY, &CLoggerDlg::OnBnClickedBtQuery)
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
	m_ComboName.AddString(L"�³�");
	m_ComboName.AddString(L"����");
	m_ComboName.AddString(L"����");
	m_ComboName.AddString(L"��־�");
	m_ComboName.AddString(L"��ʩȫ");
	m_ComboName.AddString(L"��ʢ��");

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

	delete pLogDelete;
	pLogDelete = NULL;
}