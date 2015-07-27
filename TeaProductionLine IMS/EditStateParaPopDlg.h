#pragma once


// CEditStateParaPopDlg 对话框

class CEditStateParaPopDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditStateParaPopDlg)

public:
	CEditStateParaPopDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditStateParaPopDlg();

// 对话框数据
	enum { IDD = IDD_EDITSTATEPARA_POPDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
