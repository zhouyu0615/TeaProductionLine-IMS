#pragma once
#include "afxcmn.h"


// CAllUserManageDlg �Ի���

class CAllUserManageDlg : public CDialog
{
	DECLARE_DYNAMIC(CAllUserManageDlg)

public:
	CAllUserManageDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAllUserManageDlg();

// �Ի�������
	enum { IDD = IDD_ALLUSERMANAGEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list1;
};
