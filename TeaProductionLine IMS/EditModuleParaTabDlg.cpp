// EditModuleParaTabDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TeaProductionLine IMS.h"
#include "EditModuleParaTabDlg.h"
#include "afxdialogex.h"


// CEditModuleParaTabDlg �Ի���

IMPLEMENT_DYNAMIC(CEditModuleParaTabDlg, CDialog)

CEditModuleParaTabDlg::CEditModuleParaTabDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditModuleParaTabDlg::IDD, pParent)
{

}

CEditModuleParaTabDlg::~CEditModuleParaTabDlg()
{
}

void CEditModuleParaTabDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LI1_EDITMODULEPARA_TABDLG, m_listcontrl);
}


BEGIN_MESSAGE_MAP(CEditModuleParaTabDlg, CDialog)
END_MESSAGE_MAP()


// CEditModuleParaTabDlg ��Ϣ�������
