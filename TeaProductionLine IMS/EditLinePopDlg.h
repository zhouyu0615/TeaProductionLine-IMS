#pragma once


// CEditLinePopDlg 对话框

class CEditLinePopDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditLinePopDlg)

public:
	CEditLinePopDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditLinePopDlg();

// 对话框数据
	enum { IDD = IDD_EDITLINE_POPDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
