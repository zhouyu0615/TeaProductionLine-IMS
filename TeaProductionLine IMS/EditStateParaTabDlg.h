#pragma once
#include "afxcmn.h"


// CEditStateParaTabDlg 对话框

class CEditStateParaTabDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditStateParaTabDlg)

public:
	CEditStateParaTabDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditStateParaTabDlg();

// 对话框数据
	enum { IDD = IDD_EDITSTATEPARA_TABDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listcontrl;
};
