// EditPlcPopDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TeaProductionLine IMS.h"
#include "EditPlcPopDlg.h"
#include "afxdialogex.h"


// CEditPlcPopDlg 对话框

IMPLEMENT_DYNAMIC(CEditPlcPopDlg, CDialog)

CEditPlcPopDlg::CEditPlcPopDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditPlcPopDlg::IDD, pParent)
{

}

CEditPlcPopDlg::~CEditPlcPopDlg()
{
}

void CEditPlcPopDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEditPlcPopDlg, CDialog)
END_MESSAGE_MAP()


// CEditPlcPopDlg 消息处理程序
