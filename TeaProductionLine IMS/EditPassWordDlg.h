#pragma once


// CEditPassWordDlg �Ի���

class CEditPassWordDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditPassWordDlg)

public:
	CEditPassWordDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditPassWordDlg();

// �Ի�������
	enum { IDD = IDD_EDITPASSWORDDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
