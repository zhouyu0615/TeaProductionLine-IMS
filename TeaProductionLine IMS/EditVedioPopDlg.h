#pragma once


// CEditVedioPopDlg 对话框

class CEditVedioPopDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditVedioPopDlg)

public:
	CEditVedioPopDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditVedioPopDlg();

// 对话框数据
	enum { IDD = IDD_EDITVEDIO_POPDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
