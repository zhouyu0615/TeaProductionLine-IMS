#pragma once


// CEditErrorParaPopDlg �Ի���

class CEditErrorParaPopDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditErrorParaPopDlg)

public:
	CEditErrorParaPopDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditErrorParaPopDlg();

// �Ի�������
	enum { IDD = IDD_EDITERRORPARA_POPDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
