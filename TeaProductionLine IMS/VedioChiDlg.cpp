// VedioChiDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TeaProductionLine IMS.h"
#include "VedioChiDlg.h"
#include "afxdialogex.h"


// CVedioChiDlg �Ի���

IMPLEMENT_DYNAMIC(CVedioChiDlg, CDialog)

CVedioChiDlg::CVedioChiDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVedioChiDlg::IDD, pParent)
{

}

CVedioChiDlg::~CVedioChiDlg()
{
}

void CVedioChiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CVedioChiDlg, CDialog)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CVedioChiDlg ��Ϣ�������

//�����С�仯ʱ��ʹ�ؼ�����Ӧ//
void CVedioChiDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
	if (nType == SIZE_RESTORED || nType == SIZE_MAXIMIZED)
		ReSize();
}


BOOL CVedioChiDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	//�����ؼ���С//
	CRect TempRect;
	GetClientRect(&TempRect);                                                    //ȡ�ͻ�����С//    
	m_OldSize.x = TempRect.right - TempRect.left;
	m_OldSize.y = TempRect.bottom - TempRect.top;


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

//�����С�����仯ʱ���ؼ�����Ӧ����//
void CVedioChiDlg::ReSize()
{
	float fsp[2];
	POINT recNewSize; //��ȡ���ڶԻ���Ĵ�С//  
	CRect TempRect;
	GetClientRect(&TempRect);     //ȡ�ͻ�����С//    
	recNewSize.x = TempRect.right - TempRect.left;
	recNewSize.y = TempRect.bottom - TempRect.top;
	fsp[0] = (float)recNewSize.x / m_OldSize.x;
	fsp[1] = (float)recNewSize.y / m_OldSize.y;
	CRect Rect;
	int woc;
	CPoint OldTLPoint, TLPoint; //���Ͻ�//  
	CPoint OldBRPoint, BRPoint; //���½�//  
	HWND  hwndChild = ::GetWindow(m_hWnd, GW_CHILD);  //�г����пؼ�//    
	while (hwndChild)
	{
		woc = ::GetDlgCtrlID(hwndChild);//ȡ��ID//  
		GetDlgItem(woc)->GetWindowRect(Rect);
		ScreenToClient(Rect);
		OldTLPoint = Rect.TopLeft();
		TLPoint.x = long(OldTLPoint.x*fsp[0]);
		TLPoint.y = long(OldTLPoint.y*fsp[1]);
		OldBRPoint = Rect.BottomRight();
		BRPoint.x = long(OldBRPoint.x *fsp[0]);
		BRPoint.y = long(OldBRPoint.y *fsp[1]);
		Rect.SetRect(TLPoint, BRPoint);
		GetDlgItem(woc)->MoveWindow(Rect, TRUE);
		hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);
	}
	m_OldSize = recNewSize;
}
