#pragma once


// CEditDevicePopDlg �Ի���

class CEditDevicePopDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditDevicePopDlg)

public:
	CEditDevicePopDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditDevicePopDlg();

// �Ի�������
	enum { IDD = IDD_EDITDEVICE_POPDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
