#pragma once
#include "afxcmn.h"


// CEditDeviceParaTabDlg 对话框

class CEditDeviceParaTabDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditDeviceParaTabDlg)

public:
	CEditDeviceParaTabDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditDeviceParaTabDlg();

// 对话框数据
	enum { IDD = IDD_EDITDEVICEPARA_TABDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list1;
};
