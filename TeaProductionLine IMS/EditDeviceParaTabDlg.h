#pragma once
#include "afxcmn.h"


// CEditDeviceParaTabDlg �Ի���

class CEditDeviceParaTabDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditDeviceParaTabDlg)

public:
	CEditDeviceParaTabDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditDeviceParaTabDlg();

// �Ի�������
	enum { IDD = IDD_EDITDEVICEPARA_TABDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list1;
};
