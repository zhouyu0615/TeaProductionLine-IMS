#pragma once


// CDeviceChiDlg 对话框

class CDeviceChiDlg : public CDialog
{
	DECLARE_DYNAMIC(CDeviceChiDlg)

public:
	CDeviceChiDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDeviceChiDlg();

// 对话框数据
	enum { IDD = IDD_DEVICE_CHIDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	POINT m_OldSize;                                    //窗体大小发生变化前的尺寸//
	void ReSize();                                      //使控件自适应对话框大小的变化//
	virtual BOOL OnInitDialog();
};
