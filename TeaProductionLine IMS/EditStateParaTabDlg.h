#pragma once
#include "afxcmn.h"


// CEditStateParaTabDlg �Ի���

class CEditStateParaTabDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditStateParaTabDlg)

public:
	CEditStateParaTabDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditStateParaTabDlg();

// �Ի�������
	enum { IDD = IDD_EDITSTATEPARA_TABDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listcontrl;
};
