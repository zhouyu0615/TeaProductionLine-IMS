// InitDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TeaProductionLine IMS.h"
#include "InitDlg.h"
#include "afxdialogex.h"


// CInitDlg 对话框

IMPLEMENT_DYNAMIC(CInitDlg, CDialog)

CInitDlg::CInitDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInitDlg::IDD, pParent)
{

}

CInitDlg::~CInitDlg()
{
}

void CInitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInitDlg, CDialog)
	ON_BN_CLICKED(IDC_BT_PLCPARA_INITDLG, &CInitDlg::OnBnClickedBtPlcparaInitdlg)
END_MESSAGE_MAP()


// CInitDlg 消息处理程序

//“PLC变量”按钮响应函数//
void CInitDlg::OnBnClickedBtPlcparaInitdlg()
{
	// TODO:  在此添加控件通知处理程序代码
	m_EditPlcParaDlg.DoModal();
}
