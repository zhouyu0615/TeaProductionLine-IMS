#pragma once


// CEditModuleParaPopDlg �Ի���

class CEditModuleParaPopDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditModuleParaPopDlg)

public:
	CEditModuleParaPopDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditModuleParaPopDlg();

// �Ի�������
	enum { IDD = IDD_EDITMODULEPARA_POPDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
