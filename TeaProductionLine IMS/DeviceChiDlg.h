#pragma once


// CDeviceChiDlg �Ի���

class CDeviceChiDlg : public CDialog
{
	DECLARE_DYNAMIC(CDeviceChiDlg)

public:
	CDeviceChiDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeviceChiDlg();

// �Ի�������
	enum { IDD = IDD_DEVICE_CHIDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	POINT m_OldSize;                                    //�����С�����仯ǰ�ĳߴ�//
	void ReSize();                                      //ʹ�ؼ�����Ӧ�Ի����С�ı仯//
	virtual BOOL OnInitDialog();
};
