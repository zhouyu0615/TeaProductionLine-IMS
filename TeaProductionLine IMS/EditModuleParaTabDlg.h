#pragma once
#include "afxcmn.h"


// CEditModuleParaTabDlg �Ի���

class CEditModuleParaTabDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditModuleParaTabDlg)

public:
	CEditModuleParaTabDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditModuleParaTabDlg();

// �Ի�������
	enum { IDD = IDD_EDITMODULEPARA_TABDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listcontrl;
};
