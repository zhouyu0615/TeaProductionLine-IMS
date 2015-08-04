// EditUserPopDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TeaProductionLine IMS.h"
#include "EditUserPopDlg.h"
#include "afxdialogex.h"


// CEditUserPopDlg 对话框

IMPLEMENT_DYNAMIC(CEditUserPopDlg, CDialog)

CEditUserPopDlg::CEditUserPopDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditUserPopDlg::IDD, pParent)
{

}

CEditUserPopDlg::~CEditUserPopDlg()
{
}

void CEditUserPopDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEditUserPopDlg, CDialog)
END_MESSAGE_MAP()


// CEditUserPopDlg 消息处理程序


void CEditUserPopDlg::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类

	//CDialog::OnOK();
}
