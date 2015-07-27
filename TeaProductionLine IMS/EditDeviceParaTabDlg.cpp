// EditDeviceParaTabDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TeaProductionLine IMS.h"
#include "EditDeviceParaTabDlg.h"
#include "afxdialogex.h"


// CEditDeviceParaTabDlg 对话框

IMPLEMENT_DYNAMIC(CEditDeviceParaTabDlg, CDialog)

CEditDeviceParaTabDlg::CEditDeviceParaTabDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditDeviceParaTabDlg::IDD, pParent)
{

}

CEditDeviceParaTabDlg::~CEditDeviceParaTabDlg()
{
}

void CEditDeviceParaTabDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LI1_EDITDEVICEPARA_TABDLG, m_list1);
}


BEGIN_MESSAGE_MAP(CEditDeviceParaTabDlg, CDialog)
END_MESSAGE_MAP()


// CEditDeviceParaTabDlg 消息处理程序
