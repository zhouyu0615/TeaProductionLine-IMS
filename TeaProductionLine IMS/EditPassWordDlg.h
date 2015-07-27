#pragma once


// CEditPassWordDlg 对话框

class CEditPassWordDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditPassWordDlg)

public:
	CEditPassWordDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditPassWordDlg();

// 对话框数据
	enum { IDD = IDD_EDITPASSWORDDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
