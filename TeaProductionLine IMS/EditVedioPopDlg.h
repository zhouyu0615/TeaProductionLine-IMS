#pragma once


// CEditVedioPopDlg �Ի���

class CEditVedioPopDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditVedioPopDlg)

public:
	CEditVedioPopDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditVedioPopDlg();

// �Ի�������
	enum { IDD = IDD_EDITVEDIO_POPDLG };
	int m_nSelectedItem;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
