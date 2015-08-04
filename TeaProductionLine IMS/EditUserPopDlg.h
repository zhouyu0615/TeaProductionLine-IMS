#pragma once


// CEditUserPopDlg 对话框

class CEditUserPopDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditUserPopDlg)

public:
	CEditUserPopDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditUserPopDlg();

// 对话框数据
	enum { IDD = IDD_EDITUSER_POPDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
};
