// InitDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TeaProductionLine IMS.h"
#include "InitDlg.h"
#include "afxdialogex.h"


// CInitDlg �Ի���

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


// CInitDlg ��Ϣ�������

//��PLC��������ť��Ӧ����//
void CInitDlg::OnBnClickedBtPlcparaInitdlg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_EditPlcParaDlg.DoModal();
}
