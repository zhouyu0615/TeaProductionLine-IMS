#pragma once


// CEditModulePopDlg �Ի���

class CEditModulePopDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditModulePopDlg)

public:
	CEditModulePopDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditModulePopDlg();

// �Ի�������
	enum { IDD = IDD_EDITMODULE_POPDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
