// EditLinePopDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TeaProductionLine IMS.h"
#include "EditLinePopDlg.h"
#include "afxdialogex.h"


// CEditLinePopDlg 对话框

IMPLEMENT_DYNAMIC(CEditLinePopDlg, CDialogEx)

CEditLinePopDlg::CEditLinePopDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEditLinePopDlg::IDD, pParent)
{

}

CEditLinePopDlg::~CEditLinePopDlg()
{
}

void CEditLinePopDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEditLinePopDlg, CDialogEx)
END_MESSAGE_MAP()


// CEditLinePopDlg 消息处理程序
