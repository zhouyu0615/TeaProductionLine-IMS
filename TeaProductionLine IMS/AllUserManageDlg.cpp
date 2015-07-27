// AllUserManageDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TeaProductionLine IMS.h"
#include "AllUserManageDlg.h"
#include "afxdialogex.h"


// CAllUserManageDlg 对话框

IMPLEMENT_DYNAMIC(CAllUserManageDlg, CDialog)

CAllUserManageDlg::CAllUserManageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAllUserManageDlg::IDD, pParent)
{

}

CAllUserManageDlg::~CAllUserManageDlg()
{
}

void CAllUserManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LI1_ALLUSERMANAGEDLG, m_list1);
}


BEGIN_MESSAGE_MAP(CAllUserManageDlg, CDialog)
END_MESSAGE_MAP()


// CAllUserManageDlg 消息处理程序
