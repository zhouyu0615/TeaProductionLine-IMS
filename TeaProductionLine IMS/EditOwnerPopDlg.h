#pragma once


// CEditOwnerPopDlg �Ի���

class CEditOwnerPopDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditOwnerPopDlg)

public:
	CEditOwnerPopDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditOwnerPopDlg();

// �Ի�������
	enum { IDD = IDD_EDITOWNER_POPDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
