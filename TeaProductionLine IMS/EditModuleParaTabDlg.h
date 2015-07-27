#pragma once
#include "afxcmn.h"


// CEditModuleParaTabDlg 对话框

class CEditModuleParaTabDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditModuleParaTabDlg)

public:
	CEditModuleParaTabDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditModuleParaTabDlg();

// 对话框数据
	enum { IDD = IDD_EDITMODULEPARA_TABDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listcontrl;
};
