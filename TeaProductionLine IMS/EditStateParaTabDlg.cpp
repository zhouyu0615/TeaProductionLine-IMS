// EditStateParaTabDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TeaProductionLine IMS.h"
#include "EditStateParaTabDlg.h"
#include "afxdialogex.h"


// CEditStateParaTabDlg �Ի���

IMPLEMENT_DYNAMIC(CEditStateParaTabDlg, CDialog)

CEditStateParaTabDlg::CEditStateParaTabDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditStateParaTabDlg::IDD, pParent)
{

}

CEditStateParaTabDlg::~CEditStateParaTabDlg()
{
}

void CEditStateParaTabDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listcontrl);
}


BEGIN_MESSAGE_MAP(CEditStateParaTabDlg, CDialog)
END_MESSAGE_MAP()


// CEditStateParaTabDlg ��Ϣ�������
