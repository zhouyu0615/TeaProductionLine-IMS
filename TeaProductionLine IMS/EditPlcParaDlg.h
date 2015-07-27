#pragma once
#include "afxcmn.h"


// CEditPlcParaDlg 对话框

class CEditPlcParaDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditPlcParaDlg)

public:
	CEditPlcParaDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditPlcParaDlg();

// 对话框数据
	enum { IDD = IDD_EDITPLCPARADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab1;
};
