#pragma once


// CEditUserPopDlg �Ի���

class CEditUserPopDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditUserPopDlg)

public:
	CEditUserPopDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditUserPopDlg();

// �Ի�������
	enum { IDD = IDD_EDITUSER_POPDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
