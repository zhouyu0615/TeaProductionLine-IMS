#pragma once


// CEditDeviceParaPopDlg 对话框

class CEditDeviceParaPopDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditDeviceParaPopDlg)

public:
	CEditDeviceParaPopDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditDeviceParaPopDlg();

// 对话框数据
	enum { IDD = IDD_EDITDEVICEPARA_POPDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
