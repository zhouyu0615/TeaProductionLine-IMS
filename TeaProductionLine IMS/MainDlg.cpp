
// MainDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TeaProductionLine IMS.h"
#include "MainDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
 int CMainDlg::s_nUserRight = 1;  //初始化全局静态变量：用户权限标志//
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMainDlg 对话框


IMPLEMENT_DYNAMIC(CMainDlg, CDialog);

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
	m_nCurChiDlg = 1;                                 //初始化当前显示子窗体的标识符//

	//读取数据库到数据源//
	m_pDataProvider->InitDataProvider();
	for (int n = 0; n < m_pDataProvider->m_vectProductionLine.size();n++)  //为每条生产线设置配方//
	{
		m_pDataProvider->SetCurConfig(m_pDataProvider->m_vectProductionLine[n].m_Id, 1);
	}
}

CMainDlg::~CMainDlg()
{
	// 如果该对话框有自动化代理，则
	//  将此代理指向该对话框的后向指针设置为 NULL，以便
	//  此代理知道该对话框已被删除。

	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_CityComboBox);
	DDX_Control(pDX, IDC_EDIT1, m_edWeatherInfo);
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
	ON_BN_CLICKED(IDC_BT_CONFIG, &CMainDlg::OnBnClickedBtConfig)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, &CMainDlg::OnBnClickedUpdateWeather)
END_MESSAGE_MAP()


// CMainDlg 消息处理程序

BOOL CMainDlg::OnInitDialog()
{
	
	CDialog::OnInitDialog();
	//创建各个子界面，并隐藏//
	/*CRect ChiDlgRect;
	GetDlgItem(IDC_PIC_POSITION)->GetWindowRect(ChiDlgRect);
	ScreenToClient(ChiDlgRect);*/

	m_LoginDlg.DoModal();				//登录界面///

	CRect CurWindowRect, ChiDlgRect;
	GetClientRect(&CurWindowRect);
	ChiDlgRect.left = CurWindowRect.right / 280;
	ChiDlgRect.top = CurWindowRect.bottom / 5.85 ;
	ChiDlgRect.bottom = CurWindowRect.bottom/40*39.95;
	ChiDlgRect.right = CurWindowRect.right / 5 * 3.7;
	
	m_DeviceChiDlg.Create(IDD_DEVICE_CHIDLG,this);	
	m_DeviceChiDlg.MoveWindow(ChiDlgRect);
	m_DeviceChiDlg.ShowWindow(SW_HIDE);


	CRect CurWindowRect1, ChiDlgRect1;
	GetClientRect(&CurWindowRect1);
	
	ChiDlgRect1.left = CurWindowRect1.right / 280;
	ChiDlgRect1.top = CurWindowRect1.bottom / 6.2;
	ChiDlgRect1.bottom = CurWindowRect1.bottom / 40 * 38.2;
	ChiDlgRect1.right = CurWindowRect1.right / 5 * 3.84;
	m_VedioChiDlg.Create(IDD_VEDIO_CHIDLG,this);
	m_VedioChiDlg.MoveWindow(ChiDlgRect1);
	m_VedioChiDlg.ShowWindow(SW_SHOW);


	m_ConfigChiDlg.Create(IDD_CONFIG_CHIDLG, this);
	m_ConfigChiDlg.MoveWindow(ChiDlgRect1);
	m_ConfigChiDlg.ShowWindow(SW_HIDE);

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MAXIMIZE);

	// TODO:  在此添加额外的初始化代码

	//调整控件大小//
	CRect TempRect;
	GetClientRect(&TempRect);                                                    //取客户区大小//    
	m_OldSize.x = TempRect.right - TempRect.left;
	m_OldSize.y = TempRect.bottom - TempRect.top;

	//添加状态栏//
	m_StatBar = new CStatusBarCtrl;
	TempRect.top = TempRect.bottom /75;                                         //设置状态栏的矩形区域//
	m_StatBar->Create(WS_BORDER | WS_VISIBLE | CBRS_BOTTOM, TempRect, this, 3);
	int nParts[4] = { TempRect.right / 6, TempRect.right / 3, TempRect.right / 2, -1 };                                       //分割尺寸//
	m_StatBar->SetParts(4, nParts);                                              //分割状态栏//
	m_StatBar->SetText(_T("状态参数"), 0, 0);                                    //第一个分栏加入"状态参数"//
	m_StatBar->SetText(_T("第一条生产线"), 1, 0); 
	m_StatBar->SetText(_T("正常运行"), 2, 0);
	m_StatBar->SetText(_T("备注"), 3, 0);
	m_StatBar->ShowWindow(SW_SHOW);

	
	//天气预报
	m_CityComboBox.AddString(_T("长沙"));
	m_CityComboBox.AddString(_T("北京"));
	m_CityComboBox.AddString(_T("深圳"));
	m_CityComboBox.SetCurSel(0);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMainDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 当用户关闭 UI 时，如果控制器仍保持着它的某个
//  对象，则自动化服务器不应退出。  这些
//  消息处理程序确保如下情形: 如果代理仍在使用，
//  则将隐藏 UI；但是在关闭对话框时，
//  对话框仍然会保留在那里。

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
	// 如果代理对象仍保留在那里，则自动化
	//  控制器仍会保持此应用程序。
	//  使对话框保留在那里，但将其 UI 隐藏起来。
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}


//“用户管理”按钮响应函数//
void CMainDlg::OnBnClickedBtUser()
{
	// TODO:  在此添加控件通知处理程序代码
	m_UserManageDlg.DoModal();   //弹出用户管理界面//
}


//菜单栏“系统配置”按钮响应函数//
void CMainDlg::OnSysteminit()
{
	// TODO:  在此添加命令处理程序代码
	if (s_nUserRight == 1)
		m_InitDlg.DoModal();
	else
		AfxMessageBox(_T("您没有权限进行该操作！"));
}


//PLC参数配置按钮响应函数//
void CMainDlg::OnPlcpara()
{
	// TODO:  在此添加命令处理程序代码
	if (s_nUserRight == 1)
		m_EditPlcParaDlg.DoModal();
	else
		AfxMessageBox(_T("您没有权限进行该操作！"));
}

//窗体发生大小变化时的响应函数//
void CMainDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
	if (nType == SIZE_RESTORED || nType == SIZE_MAXIMIZED)
	{
		ReSize();
	}
}

//重新布局窗体内的控件//
void CMainDlg::ReSize()
{
	double fsp[2];
	POINT recNewSize;                                 //获取现在对话框的大小//  
	CRect TempRect;
	GetClientRect(&TempRect);                         //取客户区大小//    
	recNewSize.x = TempRect.right - TempRect.left;
	recNewSize.y = TempRect.bottom - TempRect.top;
	fsp[0] = (double)recNewSize.x / m_OldSize.x;
	fsp[1] = (double)recNewSize.y / m_OldSize.y;
	CRect Rect;
	int woc;
	CPoint OldTLPoint, TLPoint;                       //左上角//  
	CPoint OldBRPoint, BRPoint;                       //右下角//  
	HWND  hwndChild = ::GetWindow(m_hWnd, GW_CHILD);  //列出所有控件//    
	while (hwndChild)
	{
		woc = ::GetDlgCtrlID(hwndChild);              //取得ID//  
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

//单击“视频监控”按钮的响应函数//
void CMainDlg::OnBnClickedBtVedio()
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_nCurChiDlg == ID_VEDIODLG)
		return;
	m_DeviceChiDlg.ShowWindow(SW_HIDE);
	m_VedioChiDlg.ShowWindow(SW_SHOW);
	m_ConfigChiDlg.ShowWindow(SW_HIDE);
	m_nCurChiDlg = ID_VEDIODLG;               //相应为当前显示子界面的标识符赋值//
}

//点击“设备监控”按钮的响应函数//
void CMainDlg::OnBnClickedBtDevice()
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_nCurChiDlg == ID_DEVICEDLG)  //如果当前显示的子界面已经是设备监控界面，则不做任何响应//
		return;	
	if (m_ConfigChiDlg.m_OldConfigGraChiDlg.m_bIsCurConfigChange)
	{
		m_DeviceChiDlg.RePaintModuleList();
		m_ConfigChiDlg.m_OldConfigGraChiDlg.m_bIsCurConfigChange = false;
	}
	m_VedioChiDlg.ShowWindow(SW_HIDE);
	m_DeviceChiDlg.ShowWindow(SW_SHOW);
	m_ConfigChiDlg.ShowWindow(SW_HIDE);
	m_nCurChiDlg = ID_DEVICEDLG;         //相应为当前显示子界面的标识符赋值//
}

//配方按钮的响应函数//
void CMainDlg::OnBnClickedBtConfig()
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_nCurChiDlg == ID_CONFIGDLG)
		return;
	m_ConfigChiDlg.ShowWindow(SW_SHOW);
	m_DeviceChiDlg.ShowWindow(SW_HIDE);
	m_VedioChiDlg.ShowWindow(SW_HIDE);
	m_nCurChiDlg = ID_CONFIGDLG;
}

//销毁主窗体//
void CMainDlg::OnDestroy()
{

	CDialog::OnDestroy();

	// TODO:  在此处添加消息处理程序代码
}


void CMainDlg::OnBnClickedUpdateWeather()
{
	// TODO:  在此添加控件通知处理程序代码
	CString strCity;
	m_CityComboBox.GetWindowText(strCity);
	m_weather.UpdateWeather(strCity);

	m_edWeatherInfo.SetWindowText(m_weather.m_strWeatherInfo);

}
