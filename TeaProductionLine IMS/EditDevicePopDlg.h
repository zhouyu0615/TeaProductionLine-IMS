#pragma once


// CEditDevicePopDlg 对话框

class CEditDevicePopDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditDevicePopDlg)

public:
	CEditDevicePopDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditDevicePopDlg();

// 对话框数据
	enum { IDD = IDD_EDITDEVICE_POPDLG };
	int m_nSelectedItem;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
