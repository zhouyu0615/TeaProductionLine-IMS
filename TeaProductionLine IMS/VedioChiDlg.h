#pragma once


// CVedioChiDlg �Ի���

class CVedioChiDlg : public CDialog
{
	DECLARE_DYNAMIC(CVedioChiDlg)

public:
	CVedioChiDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CVedioChiDlg();

// �Ի�������
	enum { IDD = IDD_VEDIO_CHIDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);    //�����С�����仯ʱ����Ӧ����//
	POINT m_OldSize;                                    //�����С�����仯ǰ�ĳߴ�//
	void ReSize();                                      //ʹ�ؼ�����Ӧ�Ի����С�ı仯//
	virtual BOOL OnInitDialog();
};
