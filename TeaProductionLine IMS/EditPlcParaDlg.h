#pragma once
#include "afxcmn.h"


// CEditPlcParaDlg �Ի���

class CEditPlcParaDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditPlcParaDlg)

public:
	CEditPlcParaDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditPlcParaDlg();

// �Ի�������
	enum { IDD = IDD_EDITPLCPARADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab1;
};
