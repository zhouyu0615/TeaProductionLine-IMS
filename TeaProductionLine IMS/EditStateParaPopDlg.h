#pragma once


// CEditStateParaPopDlg �Ի���

class CEditStateParaPopDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditStateParaPopDlg)

public:
	CEditStateParaPopDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditStateParaPopDlg();

// �Ի�������
	enum { IDD = IDD_EDITSTATEPARA_POPDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
