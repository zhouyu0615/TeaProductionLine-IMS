#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "DataProvider.h"
#include "EditModuleParaPopDlg.h"
#include "ProcessModulePara.h"


// CEditModuleParaTabDlg �Ի���

class CEditModuleParaTabDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditModuleParaTabDlg)

public:
	CEditModuleParaTabDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditModuleParaTabDlg();

// �Ի�������
	enum { IDD = IDD_EDITMODULEPARA_TABDLG };
	int m_nSelectedItem;
	CDataProvider* m_pDataProvider = CDataProvider::getInstance();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list1;
	CComboBox m_LineComboBox;
	CComboBox m_ModuleComboBox;
	CComboBox m_PlcComboBox;
	CEdit m_UnitEdit;
	CEdit m_NameEdit;
	CEdit m_AddrTypeEdit;
	CEdit m_ReadAddrIndexEdit;
	CComboBox m_ValueTypeComboBox;
	CButton m_IsConfigRadio;
	int m_NotConfigRadio;
	CButton m_IsVisibleRadio;
	int m_NotVisibleRadio;
	CEdit m_WriteAddrIndex;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedAddItem();
	afx_msg void OnBnClickedClearEdit();
	afx_msg void OnBnClickedClearAll();
	afx_msg void OnCbnSelchangeCo2EditmoduleparaTabdlg();
	afx_msg void OnNMRClickLi1EditmoduleparaTabdlg(NMHDR *pNMHDR, LRESULT *pResult);

	int MyOnPaint();
	int ListOnPaint();
	int LineComboxPaint();
	int ModuleComboxPaint(CString LineName);
	int PlcComboxPaint();

	int ValTypeComboBoxInit();
	
};
