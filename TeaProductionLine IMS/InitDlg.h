#pragma once
#include "EditPlcParaDlg.h"

// CInitDlg 对话框

class CInitDlg : public CDialog
{
	DECLARE_DYNAMIC(CInitDlg)

public:
	CInitDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInitDlg();

// 对话框数据
	enum { IDD = IDD_INITDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtPlcparaInitdlg();
	CEditPlcParaDlg m_EditPlcParaDlg;            //PLC参数配置界面//
};
