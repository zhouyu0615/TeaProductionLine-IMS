
// MainDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TeaProductionLine IMS.h"
#include "MainDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
 int CMainDlg::s_nUserRight = 1;  //��ʼ��ȫ�־�̬�������û�Ȩ�ޱ�־//
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


// CMainDlg �Ի���


IMPLEMENT_DYNAMIC(CMainDlg, CDialog);

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
	m_nCurChiDlg = 0;                                 //��ʼ����ǰ��ʾ�Ӵ���ı�ʶ��//
}

CMainDlg::~CMainDlg()
{
	// ����öԻ������Զ���������
	//  ���˴���ָ��öԻ���ĺ���ָ������Ϊ NULL���Ա�
	//  �˴���֪���öԻ����ѱ�ɾ����
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BT_USER, &CMainDlg::OnBnClickedBtUser)
	ON_COMMAND(IDM_SYSTEMINIT, &CMainDlg::OnSysteminit)
	ON_COMMAND(IDM_PLCPARA, &CMainDlg::OnPlcpara)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BT_VEDIO, &CMainDlg::OnBnClickedBtVedio)
	ON_BN_CLICKED(IDC_BT_DEVICE, &CMainDlg::OnBnClickedBtDevice)
END_MESSAGE_MAP()


// CMainDlg ��Ϣ�������

BOOL CMainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//���������ӽ��棬������//
	CRect ChiDlgRect;
    GetDlgItem(IDC_ST_PIC)->GetWindowRect(&ChiDlgRect);
	ScreenToClient(&ChiDlgRect);
	m_DeviceChiDlg.Create(IDD_DEVICE_CHIDLG, this);	
	m_DeviceChiDlg.MoveWindow(ChiDlgRect);
	m_DeviceChiDlg.ShowWindow(SW_HIDE);
	m_VedioChiDlg.Create(IDD_VEDIO_CHIDLG, this);
	m_VedioChiDlg.MoveWindow(ChiDlgRect);
	m_VedioChiDlg.ShowWindow(SW_HIDE);

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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_MAXIMIZE);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	//�����ؼ���С//
	CRect TempRect;
	GetClientRect(&TempRect);                                                    //ȡ�ͻ�����С//    
	m_OldSize.x = TempRect.right - TempRect.left;
	m_OldSize.y = TempRect.bottom - TempRect.top;

	//���״̬��//
	m_StatBar = new CStatusBarCtrl;
	TempRect.top = TempRect.bottom - 20;                                         //����״̬���ľ�������//
	m_StatBar->Create(WS_BORDER | WS_VISIBLE | CBRS_BOTTOM, TempRect, this, 3);
	int nParts[4] = { 100, 200, 300, -1 };                                       //�ָ�ߴ�//
	m_StatBar->SetParts(4, nParts);                                              //�ָ�״̬��//
	m_StatBar->SetText(_T("״̬����"), 0, 0);                                    //��һ����������"״̬����"//
	m_StatBar->SetText(_T("��һ��������"), 1, 0); 
	m_StatBar->SetText(_T("��������"), 2, 0);
	m_StatBar->SetText(_T("��ע"), 3, 0);
	m_StatBar->ShowWindow(SW_SHOW);



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMainDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ���û��ر� UI ʱ������������Ա���������ĳ��
//  �������Զ�����������Ӧ�˳���  ��Щ
//  ��Ϣ�������ȷ����������: �����������ʹ�ã�
//  ������ UI�������ڹرնԻ���ʱ��
//  �Ի�����Ȼ�ᱣ�������

void CMainDlg::OnClose()
{
	if (CanExit())
		CDialog::OnClose();
}

void CMainDlg::OnOK()
{
	if (CanExit())
		CDialog::OnOK();
}

void CMainDlg::OnCancel()
{
	if (CanExit())
		CDialog::OnCancel();
}

BOOL CMainDlg::CanExit()
{
	// �����������Ա�����������Զ���
	//  �������Իᱣ�ִ�Ӧ�ó���
	//  ʹ�Ի���������������� UI ����������
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}


//���û�������ť��Ӧ����//
void CMainDlg::OnBnClickedBtUser()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_UserManageDlg.DoModal();   //�����û��������//
}


//�˵�����ϵͳ���á���ť��Ӧ����//
void CMainDlg::OnSysteminit()
{
	// TODO:  �ڴ���������������
	if (s_nUserRight == 1)
		m_InitDlg.DoModal();
	else
		AfxMessageBox(_T("��û��Ȩ�޽��иò�����"));
}


//PLC�������ð�ť��Ӧ����//
void CMainDlg::OnPlcpara()
{
	// TODO:  �ڴ���������������
	if (s_nUserRight == 1)
		m_EditPlcParaDlg.DoModal();
	else
		AfxMessageBox(_T("��û��Ȩ�޽��иò�����"));
}

//���巢����С�仯ʱ����Ӧ����//
void CMainDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
	if (nType == SIZE_RESTORED || nType == SIZE_MAXIMIZED)
	{
		ReSize();
	}
}

//���²��ִ����ڵĿؼ�//
void CMainDlg::ReSize()
{
	double fsp[2];
	POINT recNewSize;                                 //��ȡ���ڶԻ���Ĵ�С//  
	CRect TempRect;
	GetClientRect(&TempRect);                         //ȡ�ͻ�����С//    
	recNewSize.x = TempRect.right - TempRect.left;
	recNewSize.y = TempRect.bottom - TempRect.top;
	fsp[0] = (double)recNewSize.x / m_OldSize.x;
	fsp[1] = (double)recNewSize.y / m_OldSize.y;
	CRect Rect;
	int woc;
	CPoint OldTLPoint, TLPoint;                       //���Ͻ�//  
	CPoint OldBRPoint, BRPoint;                       //���½�//  
	HWND  hwndChild = ::GetWindow(m_hWnd, GW_CHILD);  //�г����пؼ�//    
	while (hwndChild)
	{
		woc = ::GetDlgCtrlID(hwndChild);              //ȡ��ID//  
		GetDlgItem(woc)->GetWindowRect(Rect);
		ScreenToClient(Rect);
		OldTLPoint = Rect.TopLeft();
		TLPoint.x = double(OldTLPoint.x*fsp[0]);
		TLPoint.y = double(OldTLPoint.y*fsp[1]);
		OldBRPoint = Rect.BottomRight();
		BRPoint.x = double(OldBRPoint.x *fsp[0]);
		BRPoint.y = double(OldBRPoint.y *fsp[1]);
		Rect.SetRect(TLPoint, BRPoint);
		GetDlgItem(woc)->MoveWindow(Rect, TRUE);
	/*	if (woc == IDC_ST_PIC)
		{
			GetDlgItem(IDD_DEVICE_CHIDLG)->MoveWindow(Rect, TRUE);
			GetDlgItem(IDD_VEDIO_CHIDLG)->MoveWindow(Rect, TRUE);
		}*/
		hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);
	}
	m_OldSize = recNewSize;
}

//��������Ƶ��ء���ť����Ӧ����//
void CMainDlg::OnBnClickedBtVedio()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_nCurChiDlg == ID_VEDIODLG)
		return;
	m_DeviceChiDlg.ShowWindow(SW_HIDE);
	m_VedioChiDlg.ShowWindow(SW_SHOW);
	m_nCurChiDlg = ID_VEDIODLG;               //��ӦΪ��ǰ��ʾ�ӽ���ı�ʶ����ֵ//
}

//������豸��ء���ť����Ӧ����//
void CMainDlg::OnBnClickedBtDevice()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_nCurChiDlg == ID_DEVICEDLG)  //�����ǰ��ʾ���ӽ����Ѿ����豸��ؽ��棬�����κ���Ӧ//
		return;	
	m_VedioChiDlg.ShowWindow(SW_HIDE);
	m_DeviceChiDlg.ShowWindow(SW_SHOW);
	m_nCurChiDlg = ID_DEVICEDLG;         //��ӦΪ��ǰ��ʾ�ӽ���ı�ʶ����ֵ//
}
