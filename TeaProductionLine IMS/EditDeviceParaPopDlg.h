#pragma once


// CEditDeviceParaPopDlg �Ի���

class CEditDeviceParaPopDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditDeviceParaPopDlg)

public:
	CEditDeviceParaPopDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditDeviceParaPopDlg();

// �Ի�������
	enum { IDD = IDD_EDITDEVICEPARA_POPDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
