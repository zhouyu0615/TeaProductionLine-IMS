#pragma once


// CEditModulePopDlg 对话框

class CEditModulePopDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditModulePopDlg)

public:
	CEditModulePopDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditModulePopDlg();

// 对话框数据
	enum { IDD = IDD_EDITMODULE_POPDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
