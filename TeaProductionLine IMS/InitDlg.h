#pragma once
#include "EditPlcParaDlg.h"

// CInitDlg �Ի���

class CInitDlg : public CDialog
{
	DECLARE_DYNAMIC(CInitDlg)

public:
	CInitDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInitDlg();

// �Ի�������
	enum { IDD = IDD_INITDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtPlcparaInitdlg();
	CEditPlcParaDlg m_EditPlcParaDlg;            //PLC�������ý���//
};
