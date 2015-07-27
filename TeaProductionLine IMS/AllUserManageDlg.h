#pragma once
#include "afxcmn.h"


// CAllUserManageDlg 对话框

class CAllUserManageDlg : public CDialog
{
	DECLARE_DYNAMIC(CAllUserManageDlg)

public:
	CAllUserManageDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAllUserManageDlg();

// 对话框数据
	enum { IDD = IDD_ALLUSERMANAGEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list1;
};
