#pragma once


// CEditPlcPopDlg 对话框

class CEditPlcPopDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditPlcPopDlg)

public:
	CEditPlcPopDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditPlcPopDlg();

// 对话框数据
	enum { IDD = IDD_EDITPLC_POPDLG };
	int m_nSelectedItem;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
