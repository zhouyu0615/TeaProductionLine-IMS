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

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
