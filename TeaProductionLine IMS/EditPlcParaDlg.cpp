// EditPlcParaDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TeaProductionLine IMS.h"
#include "EditPlcParaDlg.h"
#include "afxdialogex.h"


// CEditPlcParaDlg 对话框

IMPLEMENT_DYNAMIC(CEditPlcParaDlg, CDialog)

CEditPlcParaDlg::CEditPlcParaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditPlcParaDlg::IDD, pParent)
{

}

CEditPlcParaDlg::~CEditPlcParaDlg()
{
}

void CEditPlcParaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_EDITPLCPARADLG, m_tab1);
}


BEGIN_MESSAGE_MAP(CEditPlcParaDlg, CDialog)
END_MESSAGE_MAP()


// CEditPlcParaDlg 消息处理程序
