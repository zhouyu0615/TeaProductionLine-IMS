// EditErrorParaTabDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TeaProductionLine IMS.h"
#include "EditErrorParaTabDlg.h"
#include "afxdialogex.h"


// CEditErrorParaTabDlg 对话框

IMPLEMENT_DYNAMIC(CEditErrorParaTabDlg, CDialog)

CEditErrorParaTabDlg::CEditErrorParaTabDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditErrorParaTabDlg::IDD, pParent)
{

}

CEditErrorParaTabDlg::~CEditErrorParaTabDlg()
{
}

void CEditErrorParaTabDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LI1_EDITERRORPARA_TABDLG, m_list1);
	DDX_Control(pDX, IDC_CO1_EDITERRORPARA_TABDLG, m_LineComboBox);
	DDX_Control(pDX, IDC_CO2_EDITERRORPARA_TABDLG, m_ModuleComboBox);
	DDX_Control(pDX, IDC_CO3_EDITERRORPARA_TABDLG, m_DeviceComboBox);
	DDX_Control(pDX, IDC_CO4_EDITERRORPARA_TABDLG, m_PlcComboBox);
	DDX_Control(pDX, IDC_ED1_EDITERRORPARA_TABDLG, m_NameEdit);
	DDX_Control(pDX, IDC_ED2_EDITERRORPARA_TABDLG, m_AddrIndexEdit);
	DDX_Control(pDX, IDC_ED3_EDITERRORPARA_TABDLG, m_DescriptionEdit);
}


BEGIN_MESSAGE_MAP(CEditErrorParaTabDlg, CDialog)
	ON_BN_CLICKED(IDC_BT1_EDITERRORPARA_TABDLG, &CEditErrorParaTabDlg::OnBnClickedAddItem)
	ON_BN_CLICKED(IDC_BT2_EDITERRORPARA_TABDLG, &CEditErrorParaTabDlg::OnBnClickedClearEdit)
	ON_BN_CLICKED(IDC_BT3_EDITERRORPARA_TABDLG, &CEditErrorParaTabDlg::OnBnClickedClearAllTabdlg)
	ON_CBN_SELCHANGE(IDC_CO1_EDITERRORPARA_TABDLG, &CEditErrorParaTabDlg::OnCbnSelchangeLine)
	ON_CBN_SELCHANGE(IDC_CO2_EDITERRORPARA_TABDLG, &CEditErrorParaTabDlg::OnCbnSelchangeModule)
	ON_NOTIFY(NM_RCLICK, IDC_LI1_EDITERRORPARA_TABDLG, &CEditErrorParaTabDlg::OnNMRClickLi1EditerrorparaTabdlg)
END_MESSAGE_MAP()


// CEditErrorParaTabDlg 消息处理程序


void CEditErrorParaTabDlg::OnBnClickedAddItem()
{
	// TODO:  在此添加控件通知处理程序代码
	CFaultPara tempFaultPara;
	m_LineComboBox.GetWindowText(tempFaultPara.m_strProductionLineName);
	m_ModuleComboBox.GetWindowText(tempFaultPara.m_strProcessName);
	m_DeviceComboBox.GetWindowText(tempFaultPara.m_strDeviceName);

	m_PlcComboBox.GetWindowText(tempFaultPara.m_strPlcName);

	m_NameEdit.GetWindowText(tempFaultPara.m_strParaName);
	m_AddrIndexEdit.GetWindowText(tempFaultPara.m_strAddressIndex);

	m_DescriptionEdit.GetWindowText(tempFaultPara.m_strDescription);

	if (!m_ParaCheckUtil.FaultParaCheck(tempFaultPara))
	{
		m_pDataProvider->AddFaultParaToDatabase(tempFaultPara);
		ListOnPaint();
	}


}


void CEditErrorParaTabDlg::OnBnClickedClearEdit()
{
	// TODO:  在此添加控件通知处理程序代码
	m_NameEdit.SetWindowText(_T(""));
	m_AddrIndexEdit.SetWindowText(_T(""));
	m_DescriptionEdit.SetWindowText(_T(""));

}


void CEditErrorParaTabDlg::OnBnClickedClearAllTabdlg()
{
	// TODO:  在此添加控件通知处理程序代码
	int nResult = MessageBox(_T("该操作将删除所有的故障参数，是否继续当前操作？"), _T("警告"), MB_ICONEXCLAMATION | MB_YESNO);//警告//
	if (nResult == IDYES)
	{
		m_pDataProvider->m_vectFaultPara.clear();
		m_pDataProvider->DeleteDbTable(CDataProvider::tbFaultPara);
		OnBnClickedClearEdit();
	}

	ListOnPaint();
}


void CEditErrorParaTabDlg::OnCbnSelchangeLine()
{
	// TODO:  在此添加控件通知处理程序代码
	CString LineName, ModuleName;
	m_LineComboBox.GetWindowText(LineName);

	ModuleComboxPaint(LineName);

	m_ModuleComboBox.GetWindowText(ModuleName);
	DeviceComboxPaint(LineName, ModuleName);
}


void CEditErrorParaTabDlg::OnCbnSelchangeModule()
{
	// TODO:  在此添加控件通知处理程序代码
	CString LineName, ModuleName;
	m_LineComboBox.GetWindowText(LineName);
	m_ModuleComboBox.GetWindowText(ModuleName);

	DeviceComboxPaint(LineName, ModuleName);
}


BOOL CEditErrorParaTabDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	MyOnPaint();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


int CEditErrorParaTabDlg::MyOnPaint()
{
	ListOnPaint(); //绘制列表框//

	LineComboxPaint();
	CString LineName, ModuleName;
	m_LineComboBox.GetLBText(0, LineName);
	ModuleComboxPaint(LineName);

	m_ModuleComboBox.GetLBText(0, ModuleName);
	DeviceComboxPaint(LineName, ModuleName);

	PlcComboxPaint();

	return 0;
}

int CEditErrorParaTabDlg::LineComboxPaint()
{
	m_LineComboBox.ResetContent();
	for (int i = 0; i < m_pDataProvider->m_vectProductionLine.size(); i++)
	{
		m_LineComboBox.AddString(m_pDataProvider->m_vectProductionLine[i].m_strLineName);
	}
	m_LineComboBox.SetCurSel(0);
	return 0;

}
int CEditErrorParaTabDlg::ModuleComboxPaint(CString LineName)
{
	m_ModuleComboBox.ResetContent();
	for (int i = 0; i < m_pDataProvider->m_vectProcessModule.size(); i++)
	{
		if (m_pDataProvider->m_vectProcessModule[i].m_strProductionLineName == LineName)
		{
			m_ModuleComboBox.AddString(m_pDataProvider->m_vectProcessModule[i].m_strProcessModuleName);
		}
	}
	m_ModuleComboBox.SetCurSel(0);
	return 0;
}

int CEditErrorParaTabDlg::DeviceComboxPaint(CString LineName, CString ModuleName)
{
	m_DeviceComboBox.ResetContent();
	for (int i = 0; i < m_pDataProvider->m_vectDevice.size(); i++)
	{
		if ((m_pDataProvider->m_vectDevice[i].m_strProductionLineName == LineName)
			&& (m_pDataProvider->m_vectDevice[i].m_strProcessModuleName == ModuleName))
		{
			m_DeviceComboBox.AddString(m_pDataProvider->m_vectDevice[i].m_strDeviceName);
		}
	}
	m_DeviceComboBox.SetCurSel(0);
	return 0;
}

int CEditErrorParaTabDlg::PlcComboxPaint()
{
	m_PlcComboBox.ResetContent();
	for (int i = 0; i < m_pDataProvider->m_vectPlc.size(); i++)
	{
		m_PlcComboBox.AddString(m_pDataProvider->m_vectPlc[i].m_strPlcName);
	}
	m_PlcComboBox.SetCurSel(0);
	return 0;
}

int CEditErrorParaTabDlg::ListOnPaint()
{

	LV_ITEM litem;
	litem.mask = LVIF_TEXT;
	litem.iSubItem = 0;
	litem.pszText = _T("");
	//设置列表控件风格//
	CRect rect1;
	m_list1.GetWindowRect(&rect1);
	m_list1.SetExtendedStyle(m_list1.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LBS_OWNERDRAWVARIABLE);

	//清空列表//
	m_list1.DeleteAllItems();
	CHeaderCtrl *pmyHeaderCtrl = m_list1.GetHeaderCtrl();
	int nCount = pmyHeaderCtrl->GetItemCount();
	for (int i = nCount - 1; i >= 0; i--)
		m_list1.DeleteColumn(i);

	m_list1.InsertColumn(0, _T(""), LVCFMT_CENTER, 0, -1);
	m_list1.InsertColumn(1, _T("序号"), LVCFMT_CENTER, rect1.Width() / 15, -1);
	m_list1.InsertColumn(2, _T("所属生产线"), LVCFMT_CENTER, rect1.Width() / 15 * 2, -1);
	m_list1.InsertColumn(3, _T("所属模块"), LVCFMT_CENTER, rect1.Width() / 15 * 2, -1);
	m_list1.InsertColumn(4, _T("所属设备"), LVCFMT_CENTER, rect1.Width() / 15 * 2, -1);
	m_list1.InsertColumn(5, _T("所属PLC"), LVCFMT_CENTER, rect1.Width() / 15 * 2, -1);
	m_list1.InsertColumn(6, _T("参数名称"), LVCFMT_CENTER, rect1.Width() / 15 * 2, -1);
	m_list1.InsertColumn(7, _T("参数地址"), LVCFMT_CENTER, rect1.Width() / 15 * 2, -1);
	m_list1.InsertColumn(8, _T("备注"), LVCFMT_CENTER, rect1.Width() / 15 * 2, -1);
	//填写表单内容//
	int length = m_pDataProvider->m_vectFaultPara.size();
	for (int i = 0; i < length; i++)
	{
		litem.iItem = i;
		CString str;
		str.Format(_T("%d"), i + 1);
		m_list1.InsertItem(&litem);
		m_list1.SetItemText(i, 1, str);
		m_list1.SetItemText(i, 2, m_pDataProvider->m_vectFaultPara[i].m_strProductionLineName);
		m_list1.SetItemText(i, 3, m_pDataProvider->m_vectFaultPara[i].m_strProcessName);
		m_list1.SetItemText(i, 4, m_pDataProvider->m_vectFaultPara[i].m_strDeviceName);
		m_list1.SetItemText(i, 5, m_pDataProvider->m_vectFaultPara[i].m_strPlcName);
		m_list1.SetItemText(i, 6, m_pDataProvider->m_vectFaultPara[i].m_strParaName);
		m_list1.SetItemText(i, 7, m_pDataProvider->m_vectFaultPara[i].m_strAddressIndex);
		m_list1.SetItemText(i, 8, m_pDataProvider->m_vectFaultPara[i].m_strDescription);
	}
	return 0;
}




void CEditErrorParaTabDlg::OnNMRClickLi1EditerrorparaTabdlg(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;

	m_nSelectedItem = -1;
	LPNMITEMACTIVATE lpNMItemActivate = (LPNMITEMACTIVATE)pNMHDR;
	if (lpNMItemActivate != NULL)
	{
		m_nSelectedItem = lpNMItemActivate->iItem;
	}
	if (m_nSelectedItem == -1)
	{
		return;
	}
	m_list1.SetItemState(m_nSelectedItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);

	CMenu menu, *pSubMenu;
	menu.LoadMenu(IDR_INITPARADLG_POP_MENU1);
	pSubMenu = menu.GetSubMenu(0);
	CPoint point1;        //存储鼠标位置的临时变量//
	GetCursorPos(&point1);//得到光标处//
	UINT nItem1 = pSubMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RETURNCMD | TPM_TOPALIGN, point1.x, point1.y, GetParent());//确保右键点击在哪菜单出现在哪，并返回所选的菜单项//

	switch (nItem1)
	{
	case ID_PARA_MODIFY:  //右键菜单：修改//
		m_FaultParaPopDlg.m_nSelectedItem = m_nSelectedItem;
		m_FaultParaPopDlg.DoModal();
		break;
	case ID_PARA_DELETE:
		m_pDataProvider->DeleteDbTableItem(CDataProvider::tbFaultPara, m_pDataProvider->m_vectFaultPara[m_nSelectedItem].m_Id);
		m_pDataProvider->m_vectFaultPara.erase(m_pDataProvider->m_vectFaultPara.begin() + m_nSelectedItem);
		break;
	default:
		break;
	}

	ListOnPaint();

}




void CEditErrorParaTabDlg::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类//
	//CDialog::OnOK();
}
