#pragma once


// CEditPlcPopDlg �Ի���

class CEditPlcPopDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditPlcPopDlg)

public:
	CEditPlcPopDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditPlcPopDlg();

// �Ի�������
	enum { IDD = IDD_EDITPLC_POPDLG };
	int m_nSelectedItem;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
