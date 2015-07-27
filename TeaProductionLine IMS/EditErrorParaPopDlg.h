#pragma once


// CEditErrorParaPopDlg 对话框

class CEditErrorParaPopDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditErrorParaPopDlg)

public:
	CEditErrorParaPopDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditErrorParaPopDlg();

// 对话框数据
	enum { IDD = IDD_EDITERRORPARA_POPDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
