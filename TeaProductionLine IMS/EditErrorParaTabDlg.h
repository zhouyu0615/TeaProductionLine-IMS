#pragma once
#include "afxcmn.h"


// CEditErrorParaTabDlg 对话框

class CEditErrorParaTabDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditErrorParaTabDlg)

public:
	CEditErrorParaTabDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditErrorParaTabDlg();

// 对话框数据
	enum { IDD = IDD_EDITERRORPARA_TABDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list1;
};
