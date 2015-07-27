#pragma once


// CEditOwnerPopDlg 对话框

class CEditOwnerPopDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditOwnerPopDlg)

public:
	CEditOwnerPopDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditOwnerPopDlg();

// 对话框数据
	enum { IDD = IDD_EDITOWNER_POPDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
