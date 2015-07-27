// UserManageDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TeaProductionLine IMS.h"
#include "UserManageDlg.h"
#include "afxdialogex.h"
#include "MainDlg.h"

// CUserManageDlg �Ի���

IMPLEMENT_DYNAMIC(CUserManageDlg, CDialog)

CUserManageDlg::CUserManageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserManageDlg::IDD, pParent)
{

}

CUserManageDlg::~CUserManageDlg()
{
}

void CUserManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserManageDlg, CDialog)
	ON_BN_CLICKED(IDC_BT_ALLUSER, &CUserManageDlg::OnBnClickedBtAlluser)
	ON_BN_CLICKED(IDC_BT_EDITPASSWORD, &CUserManageDlg::OnBnClickedBtEditpassword)
END_MESSAGE_MAP()


// CUserManageDlg ��Ϣ�������

//�����û���ť��Ӧ����//
void CUserManageDlg::OnBnClickedBtAlluser()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (CMainDlg::s_nUserRight == 1)
		m_AllUserManageDlg.DoModal();
	else
		AfxMessageBox(_T("��û��Ȩ�޽��иò�����"));
}

//�޸����밴ť��Ӧ����//
void CUserManageDlg::OnBnClickedBtEditpassword()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_EditPasswordDlg.DoModal();
}
