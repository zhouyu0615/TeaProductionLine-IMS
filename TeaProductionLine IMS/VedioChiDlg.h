#pragma once


// CVedioChiDlg 对话框

class CVedioChiDlg : public CDialog
{
	DECLARE_DYNAMIC(CVedioChiDlg)

public:
	CVedioChiDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CVedioChiDlg();

// 对话框数据
	enum { IDD = IDD_VEDIO_CHIDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);    //窗体大小发生变化时的响应函数//
	POINT m_OldSize;                                    //窗体大小发生变化前的尺寸//
	void ReSize();                                      //使控件自适应对话框大小的变化//
	virtual BOOL OnInitDialog();
};
