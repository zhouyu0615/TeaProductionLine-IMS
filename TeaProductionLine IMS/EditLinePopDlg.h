#pragma once


// CEditLinePopDlg �Ի���

class CEditLinePopDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditLinePopDlg)

public:
	CEditLinePopDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditLinePopDlg();

// �Ի�������
	enum { IDD = IDD_EDITLINE_POPDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
