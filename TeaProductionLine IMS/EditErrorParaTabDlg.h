#pragma once
#include "afxcmn.h"


// CEditErrorParaTabDlg �Ի���

class CEditErrorParaTabDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditErrorParaTabDlg)

public:
	CEditErrorParaTabDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditErrorParaTabDlg();

// �Ի�������
	enum { IDD = IDD_EDITERRORPARA_TABDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list1;
};
