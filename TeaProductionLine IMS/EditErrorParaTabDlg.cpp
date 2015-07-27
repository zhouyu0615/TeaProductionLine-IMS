// EditErrorParaTabDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TeaProductionLine IMS.h"
#include "EditErrorParaTabDlg.h"
#include "afxdialogex.h"


// CEditErrorParaTabDlg 对话框

IMPLEMENT_DYNAMIC(CEditErrorParaTabDlg, CDialog)

CEditErrorParaTabDlg::CEditErrorParaTabDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditErrorParaTabDlg::IDD, pParent)
{

}

CEditErrorParaTabDlg::~CEditErrorParaTabDlg()
{
}

void CEditErrorParaTabDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LI1_EDITERRORPARA_TABDLG, m_list1);
}


BEGIN_MESSAGE_MAP(CEditErrorParaTabDlg, CDialog)
END_MESSAGE_MAP()


// CEditErrorParaTabDlg 消息处理程序
