#include "stdafx.h"
#include "DataProvider.h"

#include "tbUser.h"
#include "tbProductionLine.h"
#include "tbProcessModule.h"
#include "tbDevice.h"
#include "tbPLc.h"
#include "tbVideo.h"


#include "tbLoginUser.h"
#include "tbDevicePara.h"
#include "tbFaultPara.h"
#include "tbProcessPara.h"
#include "tbStatePara.h"





CDataProvider::CDataProvider()
{

}


CDataProvider::~CDataProvider()
{
	delete(Instance);
}

CDataProvider::CDataProvider(const CDataProvider&)
{
};

CDataProvider*   CDataProvider::Instance = NULL;

CRITICAL_SECTION Cs;
CDataProvider* CDataProvider::getInstance(){
	
	InitializeCriticalSection(&Cs);
	if (Instance==NULL)
	{
		EnterCriticalSection(&Cs);
		if (Instance==NULL)
		{
			Instance = new CDataProvider();
		}	
		LeaveCriticalSection(&Cs);
	}

	return Instance;
}

void CDataProvider::InitDataProvider()
{

	this->ReadUserFromDatabase();
	this->ReadProLineFromDatabase();
	this->ReadProModuleFromDatabase();
	this->ReadDeviceFromDatabase();
	this->ReadPlcFromDatabase();
	this->ReadVideoFromDatabase();
}



int CDataProvider::FindProLineId(CString ProducitonLineName)
{
	int ProLineId;
	for (int i = 0; i < m_vectProductionLine.size(); i++)
	{
		if (ProducitonLineName == m_vectProductionLine[i].m_strLineName)
		{
			ProLineId = m_vectProductionLine[i].m_Id;
			return ProLineId;
		}
	}
	return 0;
}


int CDataProvider::FindProModuleId(CString ProductionLineName, CString ModuleName)
{
	int ProModuleId;
	for (int i = 0; i < m_vectProcessModule.size(); i++)
	{
		if (ProductionLineName == m_vectProcessModule[i].m_strProcessModuleName
			&&ModuleName == m_vectProcessModule[i].m_strProductionLineName)
		{
			ProModuleId = m_vectProcessModule[i].m_Id;
			return ProModuleId;
		}
	}
	return 0;
}


int CDataProvider::FindPlcId(CString PlcName)
{
	int PlcId;
	for (int i = 0; i < m_vectPlc.size();i++)
	{
		if (PlcName==m_vectPlc[i].m_strPlcName)
		{
			PlcId = m_vectPlc[i].m_Id;
			return PlcId;
		}
	}
	return 0;

}

int CDataProvider::FindDeviceId(CString ProductionLineName, CString ModuleName, CString DeviceName)
{
	int DeviceId;
	for (int i = 0; i < m_vectDevice.size();i++)
	{
		if (ProductionLineName==m_vectDevice[i].m_strProductionLineName
			&&ModuleName==m_vectDevice[i].m_strProcessModuleName
			&&DeviceName==m_vectDevice[i].m_strDeviceName)
		{
			DeviceId = m_vectDevice[i].m_Id;
			return DeviceId;
		}
	}

	return 0;
}



void CDataProvider::AddLoginUserToDatabase(CLoginUser tempLoginUser)
{
	int length = m_vectLoginUser.size();
	if (length==0)
	{
		tempLoginUser.m_Id = 1000; //��½�û���ʼID
	}
	else{
		tempLoginUser.m_Id = m_vectLoginUser[length - 1].m_Id + 1;
	}

	m_vectLoginUser.push_back(tempLoginUser);

	CtbLoginUser m_tbLoginUserSet;
	try{
		if (m_tbLoginUserSet.IsOpen())
			m_tbLoginUserSet.Close();
		if (!m_tbLoginUserSet.Open(CRecordset::dynaset)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}

	if (m_tbLoginUserSet.CanUpdate()){
		m_tbLoginUserSet.AddNew();

		CTime time = CTime::GetCurrentTime();
		m_tbLoginUserSet.m_Id = tempLoginUser.m_Id;
		m_tbLoginUserSet.m_CreatedDateTime = time;
		m_tbLoginUserSet.m_LastUpdatedDateTime = time;
		m_tbLoginUserSet.m_LoginName = tempLoginUser.m_strLoginName;
		m_tbLoginUserSet.m_LoginPassWd = tempLoginUser.m_strLoginPassWd;

		m_tbLoginUserSet.Update();

	}
	m_tbLoginUserSet.Close();

}

void CDataProvider::AddUserToDatabase(CUserClass tempUser)
{
	CtbUser m_tbUserSet;
	try{
		if (m_tbUserSet.IsOpen())
			m_tbUserSet.Close();
		if (!m_tbUserSet.Open(CRecordset::dynaset)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}
	

	int length = m_vectUser.size();
	if (m_vectUser.size() == 0) //���õ�һ���û���ID
	{
		tempUser.m_UserId = 1000;
	}
	else
	{
		tempUser.m_UserId = m_vectUser[length - 1].m_UserId + 1;
	}

	m_vectUser.push_back(tempUser);


	if (m_tbUserSet.CanUpdate()){
		m_tbUserSet.AddNew();

		CTime time = CTime::GetCurrentTime();
		m_tbUserSet.m_Id = tempUser.m_UserId;
		m_tbUserSet.m_CreatedDateTime = time;
		m_tbUserSet.m_LastUpdatedDateTime = time;
		m_tbUserSet.m_UserName = tempUser.m_strUserName;
		m_tbUserSet.m_UserPassword = tempUser.m_strUserPasswd;
		m_tbUserSet.m_UserCode = tempUser.m_strUserCode;
		m_tbUserSet.m_Note = tempUser.m_strNote;
		m_tbUserSet.Update();

	}
	m_tbUserSet.Close();
}




void CDataProvider::AddProLineToDatabase(CProductionLineClass tempProLine)
{

	CtbProductionLine tbProductionLine;
	try{
		if (tbProductionLine.IsOpen())
			tbProductionLine.Close();
		if (!tbProductionLine.Open(CRecordset::dynaset)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}
	
	int length = m_vectProductionLine.size();

	if (length == 0)//���õ�һ�������ߵ�ID
	{
		tempProLine.m_Id = 1000;
	}
	else{
		tempProLine.m_Id = m_vectProductionLine[length - 1].m_Id + 1;
	}
	tempProLine.m_UserId = m_vectUser[0].m_UserId; ////Ψһ�û�ID

	m_vectProductionLine.push_back(tempProLine);

	if (tbProductionLine.CanUpdate()){
		tbProductionLine.AddNew();

		CTime time = CTime::GetCurrentTime();
		tbProductionLine.m_Id = tempProLine.m_Id;
		tbProductionLine.m_CreatedDateTime = time;
		tbProductionLine.m_LastUpdatedDateTime = time;
		tbProductionLine.m_LineName = tempProLine.m_strLineName;
		tbProductionLine.m_UserId = tempProLine.m_UserId; 
		tbProductionLine.m_Capacity = tempProLine.m_strCapacity;
		tbProductionLine.m_Description = tempProLine.m_strDescription;
		tbProductionLine.Update();

	}

	tbProductionLine.Close();
}




void CDataProvider::AddProModuleToDatabase(CProcessModuleClass tempProModule)
{
	CtbProcessModule tbProcessModule;
	try{
		if (tbProcessModule.IsOpen())
			tbProcessModule.Close();
		if (!tbProcessModule.Open(CRecordset::dynaset)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}

	int length = m_vectProcessModule.size();
	if (length == 0)//���õ�һ��ģ��ID
	{
		tempProModule.m_Id = 1000;
	}
	else{
		tempProModule.m_Id = m_vectProcessModule[length - 1].m_Id + 1;
	}

	//�洢ģ�������û�ID
	tempProModule.m_UserId = m_vectUser[0].m_UserId;
	//�ҳ�����ģ�����������ߵ�ID
	int ProLineId = FindProLineId(tempProModule.m_strProductionLineName);
	tempProModule.m_ProcessLineId = ProLineId;

	m_vectProcessModule.push_back(tempProModule);
	
	if (tbProcessModule.CanUpdate()){
		tbProcessModule.AddNew();

		CTime time = CTime::GetCurrentTime();
		tbProcessModule.m_Id = tempProModule.m_Id;
		tbProcessModule.m_CreatedDateTime = time;
		tbProcessModule.m_LastUpdatedDateTime = time;
		tbProcessModule.m_ProductionLineName = tempProModule.m_strProductionLineName;
		tbProcessModule.m_UserId = tempProModule.m_UserId; //Ψһ�û�ID
		tbProcessModule.m_ProductionLineId = tempProModule.m_ProcessLineId; //����������ID
		tbProcessModule.m_ModuleName = tempProModule.m_strProcessModuleName;
		tbProcessModule.m_Description = tempProModule.m_strDescription;
		tbProcessModule.Update();
	}

	tbProcessModule.Close();


}

void CDataProvider::AddDeviceToDatabase(CDeviceClass tempDevice)
{
	CtbDevice tbDevice;
	try{
		if (tbDevice.IsOpen())
			tbDevice.Close();
		if (!tbDevice.Open(CRecordset::dynaset)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}
	
	int length = m_vectDevice.size();
	if (length == 0)//���õ�һ��ģ��ID
	{
		tempDevice.m_Id = 1000;
	}
	else{
		tempDevice.m_Id = m_vectDevice[length - 1].m_Id + 1;
	}
	

	int ProLineId, ProModuleId;
	//�ҵ����豸���������ߵ�ID
	ProLineId = FindProLineId(tempDevice.m_strProductionLineName);
	//�ҵ��豸�����Ĺ���ģ���ID
	ProModuleId = FindProModuleId(tempDevice.m_strProductionLineName, tempDevice.m_strProcessModuleName);

	tempDevice.m_ProductionLineId = ProLineId;
	tempDevice.m_ProcessModuleId = ProModuleId;

	m_vectDevice.push_back(tempDevice);

	if (tbDevice.CanUpdate()){
		tbDevice.AddNew();

		CTime time = CTime::GetCurrentTime();
		tbDevice.m_Id = tempDevice.m_Id;
		tbDevice.m_CreatedDateTime = time;
		tbDevice.m_LastUpdatedDateTime = time;
		tbDevice.m_ProductionLineName = tempDevice.m_strProductionLineName;
		tbDevice.m_ProcessModuleName = tempDevice.m_strProcessModuleName;
		tbDevice.m_DeviceName = tempDevice.m_strDeviceName;
		tbDevice.m_DeviceType = tempDevice.m_strDeviceType;
		tbDevice.m_ProductionLineId = tempDevice.m_ProductionLineId; //���������ߵ�ID
		tbDevice.m_ProcessModuleId = tempDevice.m_ProcessModuleId;// ��������ģ���ID

		tbDevice.Update();

	}

	tbDevice.Close();
}


void CDataProvider::AddPlcToDatabase(CPlcClass tempPlc)
{
	CtbPLc tbPlc;
	try{
		if (tbPlc.IsOpen())
			tbPlc.Close();
		if (!tbPlc.Open(CRecordset::dynaset)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}
	

	int length = m_vectPlc.size();
	if (length == 0)//���õ�һ��PLC ID
	{
		tempPlc.m_Id = 1000;
	}
	else{
		tempPlc.m_Id = m_vectPlc[length - 1].m_Id + 1;
	}
	
	tempPlc.m_UserId = m_vectUser[0].m_UserId;
	int ProlineId = FindProLineId(tempPlc.m_strProductionLineName); //�ҳ�PLC���������ߵ�ID
	tempPlc.m_ProductionLineId = ProlineId;

	m_vectPlc.push_back(tempPlc);

	if (tbPlc.CanUpdate()){
		tbPlc.AddNew();

		CTime time = CTime::GetCurrentTime();
		tbPlc.m_Id = tempPlc.m_Id;
		tbPlc.m_CreatedDateTime = time;
		tbPlc.m_LastUpdatedDateTime = time;
		tbPlc.m_ProductionLineName = tempPlc.m_strProductionLineName;
		tbPlc.m_UserId = tempPlc.m_UserId; //Ψһ�û�ID
		tbPlc.m_PLCName = tempPlc.m_strPlcName;
		tbPlc.m_strIPAddr = tempPlc.m_strIPAddr;

		tbPlc.m_ReadStartAddr = tempPlc.m_ReadStartAddr;
		tbPlc.m_ReadLength = tempPlc.m_ReadLength;
		tbPlc.m_WriteStartAddr = tempPlc.m_WriteStartAddr;
		tbPlc.m_WriteLength = tempPlc.m_WriteLength;

		tbPlc.m_Description = tempPlc.m_strDescription;
		tbPlc.Update();

	}

	tbPlc.Close();
}


void CDataProvider::AddVideoToDatabase(CVideoClass tempVideo)
{

	CtbVideo tbVideo;
	try{
		if (tbVideo.IsOpen())
			tbVideo.Close();
		if (!tbVideo.Open(CRecordset::dynaset)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}


	int length = m_vectVideo.size();
	if (length == 0)//���õ�һ��ģ��ID
	{
		tempVideo.m_Id = 1000;
	}
	else{
		tempVideo.m_Id = m_vectVideo[length - 1].m_Id + 1;
	}
	
	
	tempVideo.m_ProductionLineId = FindProLineId(tempVideo.m_strProductionLineName);
	tempVideo.m_ModuleId = FindProModuleId(tempVideo.m_strProductionLineName, tempVideo.m_strProcessModuleName);


	m_vectVideo.push_back(tempVideo);

	if (tbVideo.CanUpdate()){
		tbVideo.AddNew();

		CTime time = CTime::GetCurrentTime();
		tbVideo.m_Id = tempVideo.m_Id;
		tbVideo.m_CreatedDateTime = time;
		tbVideo.m_LastUpdatedDateTime = time;
		tbVideo.m_ProductionLineName = tempVideo.m_strProductionLineName;
		tbVideo.m_ProcessModuleName = tempVideo.m_strProcessModuleName;
		tbVideo.m_VideoName = tempVideo.m_strVideoName;
		tbVideo.m_strIPAddr = tempVideo.m_strIPAddr;
		tbVideo.m_Port = tempVideo.m_port;

		tbVideo.m_ProductionLineId = tempVideo.m_ProductionLineId;
		tbVideo.m_ProcessModuleId = tempVideo.m_ModuleId;
		tbVideo.Update();

	}

	tbVideo.Close();

}


void CDataProvider::AddDeviceParaToDatabase(CDevicePara tempDevicePara)
{
	CtbDevicePara tbDevicePara;
	try{
		if (tbDevicePara.IsOpen())
			tbDevicePara.Close();
		if (!tbDevicePara.Open(CRecordset::dynaset)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}


	int length = m_vectDevicePara.size();
	if (length == 0)//���õ�һ��ģ��ID
	{
		tempDevicePara.m_Id = 1000;
	}
	else{
		tempDevicePara.m_Id = m_vectDevicePara[length - 1].m_Id + 1;
	}

	tempDevicePara.m_ProductionLineId = FindProLineId(tempDevicePara.m_strProductionLineName);
	tempDevicePara.m_ProcessModuleId = FindProModuleId(tempDevicePara.m_strProductionLineName, tempDevicePara.m_strProcessModuleName);
	tempDevicePara.m_PlcId = FindPlcId(tempDevicePara.m_strPlcName);


	m_vectDevicePara.push_back(tempDevicePara);

	if (tbDevicePara.CanUpdate()){
		tbDevicePara.AddNew();

		CTime time = CTime::GetCurrentTime();
		tbDevicePara.m_Id = tempDevicePara.m_Id;
		tbDevicePara.m_CreatedDateTime = time;
		tbDevicePara.m_LastUpdatedDateTime = time;
		tbDevicePara.m_ProductionLineName = tempDevicePara.m_strProductionLineName;
		tbDevicePara.m_ProcessModuleName = tempDevicePara.m_strProcessModuleName;
		tbDevicePara.m_PlcName = tempDevicePara.m_strPlcName;
		tbDevicePara.m_PLCId = tempDevicePara.m_PlcId;
		tbDevicePara.m_DeviceName = tempDevicePara.m_strDeviceName;
		tbDevicePara.m_DeviceId = tempDevicePara.m_DeviceId;
		tbDevicePara.m_ProductionLineId = tempDevicePara.m_ProductionLineId;
		tbDevicePara.m_ProcessModuleId = tempDevicePara.m_ProcessModuleId;
		tbDevicePara.m_ControlAddrIndex = tempDevicePara.m_strControlAddrIndex;
		tbDevicePara.m_ControlValue = tempDevicePara.m_ControlValue;
		tbDevicePara.m_StateValue = tempDevicePara.m_StateValue;
		tbDevicePara.m_StateAddrIndex = tempDevicePara.m_strStateAddrIndex;
		tbDevicePara.m_ParaName = tempDevicePara.m_strParaName;
		tbDevicePara.m_Description = tempDevicePara.m_strDescription;


		tbDevicePara.Update();

	}

	tbDevicePara.Close();
}


void CDataProvider::AddFaultParaToDatabase(CFaultPara tempFaultPara)
{
	CtbFaultPara tbFaultPara;
	try{
		if (tbFaultPara.IsOpen())
			tbFaultPara.Close();
		if (!tbFaultPara.Open(CRecordset::dynaset)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}


	int length = m_vectFaultPara.size();
	if (length == 0)//���õ�һ��ģ��ID
	{
		tempFaultPara.m_Id = 1000;
	}
	else{
		tempFaultPara.m_Id = m_vectFaultPara[length - 1].m_Id + 1;
	}

	tempFaultPara.m_ProductionLineId = FindProLineId(tempFaultPara.m_strProductionLineName);
	tempFaultPara.m_ProcessModuleId = FindProModuleId(tempFaultPara.m_strProductionLineName, tempFaultPara.m_strProcessName);



	m_vectFaultPara.push_back(tempFaultPara);

	if (tbFaultPara.CanUpdate()){
		tbFaultPara.AddNew();

		CTime time = CTime::GetCurrentTime();
		tbFaultPara.m_Id = tempFaultPara.m_Id;
		tbFaultPara.m_CreatedDateTime = time;
		tbFaultPara.m_LastUpdatedDateTime = time;
		tbFaultPara.m_ProductionLineName = tempFaultPara.m_strProductionLineName;
		tbFaultPara.m_ProcessModuleName = tempFaultPara.m_strProcessName;
		tbFaultPara.m_ProductionLineId = tempFaultPara.m_ProductionLineId;
		tbFaultPara.m_ProcessModuleId = tempFaultPara.m_ProcessModuleId;
		tbFaultPara.m_DeviceName = tempFaultPara.m_strDeviceName;
		tbFaultPara.m_DeviceId = tempFaultPara.m_DeviceId;
		tbFaultPara.m_PlcName = tempFaultPara.m_strPlcName;
		tbFaultPara.m_PLCId = tempFaultPara.m_PLCId;
		tbFaultPara.m_AddressIndex = tempFaultPara.m_strAddressIndex;
		tbFaultPara.m_ParaValue = tempFaultPara.m_ParaValue;
		tbFaultPara.m_ParaName = tempFaultPara.m_strParaName;
		tbFaultPara.m_Description = tempFaultPara.m_strDescription;

		tbFaultPara.Update();

	}

	tbFaultPara.Close();

}

void CDataProvider::AddProcessParaToDatabase(CProcessPara tempProcessPara)
{
	CtbProcessPara tbProcessPara;
	try{
		if (tbProcessPara.IsOpen())
			tbProcessPara.Close();
		if (!tbProcessPara.Open(CRecordset::dynaset)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}


	int length = m_vectProModulePara.size();
	if (length == 0)//���õ�һ��ģ��ID
	{
		tempProcessPara.m_Id = 1000;
	}
	else{
		tempProcessPara.m_Id = m_vectProModulePara[length - 1].m_Id + 1;
	}

	tempProcessPara.m_ProductionLineId = FindProLineId(tempProcessPara.m_strProductionLineName);
	tempProcessPara.m_ProcessModuleId = FindProModuleId(tempProcessPara.m_strProductionLineName, tempProcessPara.m_strProcessModuleName);



	m_vectProModulePara.push_back(tempProcessPara);

	if (tbProcessPara.CanUpdate()){
		tbProcessPara.AddNew();

		CTime time = CTime::GetCurrentTime();
		tbProcessPara.m_Id = tempProcessPara.m_Id;
		tbProcessPara.m_CreatedDateTime = time;
		tbProcessPara.m_LastUpdatedDateTime = time;
		tbProcessPara.m_ProductionLineName = tempProcessPara.m_strProductionLineName;
		tbProcessPara.m_ProcessModuleName = tempProcessPara.m_strProcessModuleName;
		tbProcessPara.m_ProductionLineId = tempProcessPara.m_ProductionLineId;
		tbProcessPara.m_ProcessModuleId = tempProcessPara.m_ProcessModuleId;
		tbProcessPara.m_PlcName = tempProcessPara.m_strPlcName;
		tbProcessPara.m_PLCId = tempProcessPara.m_PlcId;
		tbProcessPara.m_AddressIndex = tempProcessPara.m_strAddressIndex;
		tbProcessPara.m_AddressType = tempProcessPara.m_strAddressType;
		tbProcessPara.m_ParaValue = tempProcessPara.m_ParaValue;
		tbProcessPara.m_ParaName = tempProcessPara.m_strParaName;
		tbProcessPara.m_Description = tempProcessPara.m_strDescription;
		tbProcessPara.m_ValueType = tempProcessPara.m_ValueType;
		tbProcessPara.m_IsConfig = tempProcessPara.m_IsConfig;
		tbProcessPara.m_IsReadOnly = tempProcessPara.m_IsReadOnly;

		tbProcessPara.Update();

	}

	tbProcessPara.Close();

}

void CDataProvider::AddStateParaToDatabase(CStatePara tempStatePara)
{
	CtbStatePara tbStatePara;
	try{
		if (tbStatePara.IsOpen())
			tbStatePara.Close();
		if (!tbStatePara.Open(CRecordset::dynaset)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}


	int length = m_vectStatePara.size();
	if (length == 0)//���õ�һ��ģ��ID
	{
		tempStatePara.m_Id = 1000;
	}
	else{
		tempStatePara.m_Id = m_vectStatePara[length - 1].m_Id + 1;
	}

	tempStatePara.m_ProductionLineId = FindProLineId(tempStatePara.m_strProductionLineName);
	tempStatePara.m_ProcessModuleId = FindProModuleId(tempStatePara.m_strProductionLineName, tempStatePara.m_strProcessModuleName);



	m_vectStatePara.push_back(tempStatePara);

	if (tbStatePara.CanUpdate()){
		tbStatePara.AddNew();

		CTime time = CTime::GetCurrentTime();
		tbStatePara.m_Id = tempStatePara.m_Id;
		tbStatePara.m_CreatedDateTime = time;
		tbStatePara.m_LastUpdatedDateTime = time;
		tbStatePara.m_ProductionLineName = tempStatePara.m_strProductionLineName;
		tbStatePara.m_ProcessModuleName = tempStatePara.m_strProcessModuleName;
		tbStatePara.m_ProductionLineId = tempStatePara.m_ProductionLineId;
		tbStatePara.m_ProcessModuleId = tempStatePara.m_ProcessModuleId;
		tbStatePara.m_PlcName = tempStatePara.m_strPlcName;
		tbStatePara.m_PLCId = tempStatePara.m_PlcId;
		tbStatePara.m_AddressIndex = tempStatePara.m_strAddressIndex;
		tbStatePara.m_ParaValue = tempStatePara.m_ParaValue;
		tbStatePara.m_ParaName = tempStatePara.m_strParaName;
		tbStatePara.m_Description = tempStatePara.m_strDescription;


		tbStatePara.Update();

	}

	tbStatePara.Close();
	

}


void CDataProvider::ReadDeviceParaFromDatabase()
{
	CString strsql;
	strsql.Format(_T("select * from tbDevicePara order by Id"));

	CtbDevicePara  tbDevicePara;
	try{
		if (tbDevicePara.IsOpen())
			tbDevicePara.Close();
		if (!tbDevicePara.Open(CRecordset::dynaset, strsql)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}

	if (tbDevicePara.IsBOF())
	{
		return;
	}


	CDevicePara tempDevicePara;
	tbDevicePara.MoveFirst();
	while (!tbDevicePara.IsEOF()){
		tempDevicePara.m_Id = tbDevicePara.m_Id;
		tempDevicePara.m_strCreatedDateTime = tbDevicePara.m_CreatedDateTime.Format(_T("%Y-%m-%d %H:%M:%S"));
		tempDevicePara.m_strLastUpdatedDateTime=tbDevicePara.m_LastUpdatedDateTime.Format(_T("%Y-%m-%d %H:%M:%S"));
		tempDevicePara.m_strProductionLineName = tbDevicePara.m_ProductionLineName;
		tempDevicePara.m_strProcessModuleName = tbDevicePara.m_ProcessModuleName;		
		tempDevicePara.m_strPlcName=tbDevicePara.m_PlcName ;

		tempDevicePara.m_strDeviceName=tbDevicePara.m_DeviceName ;
		tempDevicePara.m_DeviceId=tbDevicePara.m_DeviceId;
		tempDevicePara.m_PlcId = tbDevicePara.m_PLCId;
		tempDevicePara.m_ProductionLineId = tbDevicePara.m_ProductionLineId;
		tempDevicePara.m_ProcessModuleId=tbDevicePara.m_ProcessModuleId;
		tempDevicePara.m_strControlAddrIndex=tbDevicePara.m_ControlAddrIndex ;
		tempDevicePara.m_ControlValue=tbDevicePara.m_ControlValue;
		tempDevicePara.m_StateValue=tbDevicePara.m_StateValue;
		tempDevicePara.m_strStateAddrIndex=tbDevicePara.m_StateAddrIndex;
		tempDevicePara.m_strParaName=tbDevicePara.m_ParaName;
		tempDevicePara.m_strDescription=tbDevicePara.m_Description;



		m_vectDevicePara.push_back(tempDevicePara);
		tbDevicePara.MoveNext();
	}

	tbDevicePara.Close();




}

void CDataProvider::ReadFaultParaFromDatabase()
{
	CString strsql;
	strsql.Format(_T("select * from tbFaultPara order by Id"));

	CtbFaultPara  tbFaultPara;
	try{
		if (tbFaultPara.IsOpen())
			tbFaultPara.Close();
		if (!tbFaultPara.Open(CRecordset::dynaset, strsql)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}

	if (tbFaultPara.IsBOF())
	{
		return;
	}

	CFaultPara tempFaultPara;
	
	tbFaultPara.MoveFirst();
	while (!tbFaultPara.IsEOF()){

		tempFaultPara.m_Id=tbFaultPara.m_Id;
		tempFaultPara.m_strCreatedDateTime = tbFaultPara.m_CreatedDateTime.Format(_T("%Y-%m-%d %H:%M:%S"));
		tempFaultPara.m_strLastUpdatedDateTime=tbFaultPara.m_LastUpdatedDateTime.Format(_T("%Y-%m-%d %H:%M:%S"));
		tempFaultPara.m_strProductionLineName=tbFaultPara.m_ProductionLineName;
		tempFaultPara.m_strProcessName=tbFaultPara.m_ProcessModuleName;
		tempFaultPara.m_ProductionLineId=tbFaultPara.m_ProductionLineId;
		tempFaultPara.m_ProcessModuleId=tbFaultPara.m_ProcessModuleId;
		tempFaultPara.m_strDeviceName=tbFaultPara.m_DeviceName;
		tempFaultPara.m_DeviceId=tbFaultPara.m_DeviceId;
		tempFaultPara.m_strPlcName=tbFaultPara.m_PlcName;
		tempFaultPara.m_PLCId=tbFaultPara.m_PLCId;
		tempFaultPara.m_strAddressIndex=tbFaultPara.m_AddressIndex;
		tempFaultPara.m_ParaValue=tbFaultPara.m_ParaValue;
		tempFaultPara.m_strParaName=tbFaultPara.m_ParaName;
		tempFaultPara.m_strDescription=tbFaultPara.m_Description;

		m_vectFaultPara.push_back(tempFaultPara);
		tbFaultPara.MoveNext();
	}
	tbFaultPara.Close();

}

void CDataProvider::ReadProcessParaFromDatabase()
{
	CString strsql;
	strsql.Format(_T("select * from tbProcessPara order by Id"));

	CtbProcessPara  tbProcessPara;
	try{
		if (tbProcessPara.IsOpen())
			tbProcessPara.Close();
		if (!tbProcessPara.Open(CRecordset::dynaset, strsql)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}

	if (tbProcessPara.IsBOF())
	{
		return;
	}

	CProcessPara tempProcessPara;

	tbProcessPara.MoveFirst();
	while (!tbProcessPara.IsEOF()){

		tempProcessPara.m_Id=tbProcessPara.m_Id;
		tempProcessPara.m_strCreatedDateTime= tbProcessPara.m_CreatedDateTime.Format(_T("%Y-%m-%d %H:%M:%S"));
		tempProcessPara.m_strLastUpdatedDateTime = tbProcessPara.m_LastUpdatedDateTime.Format(_T("%Y-%m-%d %H:%M:%S"));
		tempProcessPara.m_strProductionLineName=tbProcessPara.m_ProductionLineName;
		tempProcessPara.m_strProcessModuleName=tbProcessPara.m_ProcessModuleName;
		tempProcessPara.m_ProductionLineId=tbProcessPara.m_ProductionLineId;
		tempProcessPara.m_ProcessModuleId=tbProcessPara.m_ProcessModuleId;
		tempProcessPara.m_strPlcName=tbProcessPara.m_PlcName;
		tempProcessPara.m_PlcId=tbProcessPara.m_PLCId;
		tempProcessPara.m_strAddressIndex=tbProcessPara.m_AddressIndex;
		tempProcessPara.m_strAddressType=tbProcessPara.m_AddressType;
		tempProcessPara.m_ParaValue=tbProcessPara.m_ParaValue;
		tempProcessPara.m_strParaName=tbProcessPara.m_ParaName;
		tempProcessPara.m_strDescription=tbProcessPara.m_Description;
		tempProcessPara.m_ValueType=tbProcessPara.m_ValueType;
		tempProcessPara.m_IsConfig=tbProcessPara.m_IsConfig;
		tempProcessPara.m_IsReadOnly=tbProcessPara.m_IsReadOnly;

		m_vectProModulePara.push_back(tempProcessPara);
		tbProcessPara.MoveNext();
	}
	tbProcessPara.Close();

}

void CDataProvider::ReadStateParaFromDatabase()
{
	CString strsql;
	strsql.Format(_T("select * from tbStatePara order by Id"));

	CtbStatePara  tbStatePara;
	try{
		if (tbStatePara.IsOpen())
			tbStatePara.Close();
		if (!tbStatePara.Open(CRecordset::dynaset, strsql)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}

	if (tbStatePara.IsBOF())
	{
		return;
	}

	CStatePara tempStatePara;

	tbStatePara.MoveFirst();
	while (!tbStatePara.IsEOF()){
		tempStatePara.m_Id=tbStatePara.m_Id;
		tempStatePara.m_strCreatedDateTime = tbStatePara.m_CreatedDateTime.Format(_T("%Y-%m-%d %H:%M:%S"));
		tempStatePara.m_strLastUpdateDateTime=tbStatePara.m_LastUpdatedDateTime.Format(_T("%Y-%m-%d %H:%M:%S"));
		tempStatePara.m_strProductionLineName=tbStatePara.m_ProductionLineName;
		tempStatePara.m_strProcessModuleName=tbStatePara.m_ProcessModuleName;
		tempStatePara.m_ProductionLineId=tbStatePara.m_ProductionLineId;
		tempStatePara.m_ProcessModuleId=tbStatePara.m_ProcessModuleId;
		tempStatePara.m_strPlcName=tbStatePara.m_PlcName;
		tempStatePara.m_PlcId=tbStatePara.m_PLCId;
		tempStatePara.m_strAddressIndex=tbStatePara.m_AddressIndex;
		tempStatePara.m_ParaValue=tbStatePara.m_ParaValue;
		tempStatePara.m_strParaName=tbStatePara.m_ParaName;
		tempStatePara.m_strDescription=tbStatePara.m_Description;

		m_vectStatePara.push_back(tempStatePara);
		tbStatePara.MoveNext();
	}
	tbStatePara.Close();



}

void CDataProvider::ReadLoginUserFormDatabase()
{
	CString strsql;
	strsql.Format(_T("select * from tbLoginUser order by Id"));

	CtbLoginUser tbLoginUser;
	try{
		if (tbLoginUser.IsOpen())
			tbLoginUser.Close();
		if (!tbLoginUser.Open(CRecordset::dynaset, strsql)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}

	if (tbLoginUser.IsBOF())
	{
		return;
	}

	CLoginUser tempLoginUser;
	tbLoginUser.MoveFirst();
	while (!tbLoginUser.IsEOF()){
		//��ȡ���Ա���� Ψһ�� �û�ID
		tempLoginUser.m_Id = tbLoginUser.m_Id;
		tempLoginUser.m_strCreatedDateTime = tbLoginUser.m_CreatedDateTime.Format(_T("%Y-%m-%d %H:%M:%S"));
		tempLoginUser.m_strLastUpdatedDateTime = tbLoginUser.m_LastUpdatedDateTime.Format(_T("%Y-%m-%d %H:%M:%S"));
		tempLoginUser.m_strLastLoginInTime = tbLoginUser.m_LastLoginInTime.Format(_T("%Y-%m-%d %H:%M:%S"));
		tempLoginUser.m_strLoginName = tbLoginUser.m_LoginName;
		tempLoginUser.m_strLoginPassWd = tbLoginUser.m_LoginPassWd;

		tempLoginUser.m_PermissionLevel = tbLoginUser.m_PermissionLevel;
		tempLoginUser.m_IsRememberPasswd = tbLoginUser.m_IsRememberPasswd;
		tempLoginUser.m_IsAutoLogin = tbLoginUser.m_IsAutoLogin;

		tbLoginUser.MoveNext();
	}

	tbLoginUser.Close();
}


void CDataProvider::ReadUserFromDatabase(){
	CString strsql;
	strsql.Format(_T("select * from tbUser order by Id"));

	CtbUser tbUser;
	try{
		if (tbUser.IsOpen())
			tbUser.Close();
		if (!tbUser.Open(CRecordset::dynaset, strsql)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}

	if (tbUser.IsBOF())
	{
		return;
	}

	CUserClass tempUser;
	tbUser.MoveFirst();
	while (!tbUser.IsEOF()){
		//��ȡ���Ա���� Ψһ�� �û�ID
		tempUser.m_UserId = tbUser.m_Id;
		tempUser.m_strUserName = tbUser.m_UserName;
		tempUser.m_strUserPasswd = tbUser.m_UserPassword;
		tempUser.m_strUserCode = tbUser.m_UserCode;
		tempUser.m_strNote = tbUser.m_Note;
		m_vectUser.push_back(tempUser);

		tbUser.MoveNext();

	}

	tbUser.Close();

}



void CDataProvider::ReadProLineFromDatabase(){
	CString strsql;
	strsql.Format(_T("select * from tbProductionLine order by Id"));

	CtbProductionLine tbProductionLine;
	try{
		if (tbProductionLine.IsOpen())
			tbProductionLine.Close();
		if (!tbProductionLine.Open(CRecordset::dynaset, strsql)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}

	if (tbProductionLine.IsBOF())
	{
		return;
	}

	CProductionLineClass tempProductionLine;
	tbProductionLine.MoveFirst();
	while (!tbProductionLine.IsEOF()){

		tempProductionLine.m_Id = tbProductionLine.m_Id;
		tempProductionLine.m_strLineName = tbProductionLine.m_LineName;
		tempProductionLine.m_strCapacity = tbProductionLine.m_Capacity;
		tempProductionLine.m_strDescription = tbProductionLine.m_Description;

		tempProductionLine.m_UserId = tbProductionLine.m_UserId;

		m_vectProductionLine.push_back(tempProductionLine);
		tbProductionLine.MoveNext();
	}

	tbProductionLine.Close();

}


void CDataProvider::ReadProModuleFromDatabase()
{
	CString strsql;
	strsql.Format(_T("select * from tbProcessModule order by Id"));

	CtbProcessModule  tbProcessModule;
	try{
		if (tbProcessModule.IsOpen())
			tbProcessModule.Close();
		if (!tbProcessModule.Open(CRecordset::dynaset, strsql)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}

	if (tbProcessModule.IsBOF())
	{
		return;
	}


	CProcessModuleClass tempModule;
	tbProcessModule.MoveFirst();
	while (!tbProcessModule.IsEOF()){

		tempModule.m_Id = tbProcessModule.m_Id;
		tempModule.m_strProductionLineName = tbProcessModule.m_ProductionLineName;
		tempModule.m_strProcessModuleName = tbProcessModule.m_ModuleName;
		tempModule.m_strDescription = tbProcessModule.m_Description;

		tempModule.m_ProcessLineId = tbProcessModule.m_ProductionLineId;

		tempModule.m_UserId = tbProcessModule.m_UserId;

		m_vectProcessModule.push_back(tempModule);
		tbProcessModule.MoveNext();
	}

	tbProcessModule.Close();

}


void CDataProvider::ReadDeviceFromDatabase()
{
	CString strsql;
	strsql.Format(_T("select * from tbDevice order by Id"));

	CtbDevice  tbDevice;
	try{
		if (tbDevice.IsOpen())
			tbDevice.Close();
		if (!tbDevice.Open(CRecordset::dynaset, strsql)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}
	if (tbDevice.IsEOF())
	{
		return;
	}


	CDeviceClass tempDevice;
	tbDevice.MoveFirst();
	while (!tbDevice.IsEOF()){

		tempDevice.m_Id = tbDevice.m_Id;
		tempDevice.m_strProductionLineName = tbDevice.m_ProductionLineName;
		tempDevice.m_strProcessModuleName = tbDevice.m_ProcessModuleName;
		tempDevice.m_strDeviceName = tbDevice.m_DeviceName;
		tempDevice.m_strDeviceType = tbDevice.m_DeviceType;
		tempDevice.m_ProcessModuleId = tbDevice.m_ProcessModuleId;
		tempDevice.m_ProductionLineId = tbDevice.m_ProductionLineId;

		m_vectDevice.push_back(tempDevice);
		tbDevice.MoveNext();
	}

	tbDevice.Close();

}





void CDataProvider::ReadPlcFromDatabase()
{
	CString strsql;
	strsql.Format(_T("select * from tbPLc order by Id"));

	CtbPLc  tbPlc;
	try{
		if (tbPlc.IsOpen())
			tbPlc.Close();
		if (!tbPlc.Open(CRecordset::dynaset, strsql)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}

	if (tbPlc.IsEOF())
	{
		return;
	}

	CPlcClass tempPlc;
	tbPlc.MoveFirst();
	while (!tbPlc.IsEOF()){

		tempPlc.m_Id = tbPlc.m_Id;
		tempPlc.m_strProductionLineName = tbPlc.m_ProductionLineName;
		tempPlc.m_strPlcName = tbPlc.m_PLCName;
		tempPlc.m_strIPAddr = tbPlc.m_strIPAddr;
		tempPlc.m_strDescription = tbPlc.m_Description;
		tempPlc.m_ProductionLineId = tbPlc.m_ProductionLineId;


		m_vectPlc.push_back(tempPlc);
		tbPlc.MoveNext();
	}

	tbPlc.Close();


}




void CDataProvider::ReadVideoFromDatabase()
{
	CString strsql;
	strsql.Format(_T("select * from tbVideo order by Id"));

	CtbVideo  tbVideo;
	try{
		if (tbVideo.IsOpen())
			tbVideo.Close();
		if (!tbVideo.Open(CRecordset::dynaset, strsql)){
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}

	if (tbVideo.IsEOF())
	{
		tbVideo.Close();
		return;
	}

	CVideoClass tempVideo;
	tbVideo.MoveFirst();
	while (!tbVideo.IsEOF()){

		tempVideo.m_Id = tbVideo.m_Id;
		tempVideo.m_strProductionLineName = tbVideo.m_ProductionLineName;
		tempVideo.m_strProcessModuleName = tbVideo.m_ProcessModuleName;
		tempVideo.m_strIPAddr = tbVideo.m_strIPAddr;
		tempVideo.m_strVideoName = tbVideo.m_VideoName;

		tempVideo.m_port = tbVideo.m_Port;

		tempVideo.m_ProductionLineId = tbVideo.m_ProductionLineId;
		tempVideo.m_ModuleId = tbVideo.m_ProcessModuleId;

		m_vectVideo.push_back(tempVideo);
		tbVideo.MoveNext();
	}

	tbVideo.Close();


}

/*�������ܣ�ɾ��ö������dbTable�������ṩ�ĸ�����������
������DeleteDbTable(tbProductionLine)ɾ�������߱��������������е���
*/
int CDataProvider::DeleteDbTable(enumDBTABLE dbTable)
{
	CString strsql;

	switch (dbTable)
	{
	case CDataProvider::tbUser:
		strsql.Format(_T("DELETE FROM tbUser"));
		break;
	case CDataProvider::tbProductionLine:
		strsql.Format(_T("DELETE FROM tbProductionLine"));
		break;
	case CDataProvider::tbProcessModule:
		strsql.Format(_T("DELETE FROM tbProcessModule"));
		break;
	case CDataProvider::tbDevice:
		strsql.Format(_T("DELETE FROM tbDevice"));
		break;
	case CDataProvider::tbPLc:
		strsql.Format(_T("DELETE FROM tbPLc"));
		break;
	case CDataProvider::tbVideo:
		strsql.Format(_T("DELETE FROM tbVideo"));
		break;
	case CDataProvider::tbLoginUser:
		strsql.Format(_T("DELETE FROM tbLoginUser"));
		break;
	case CDataProvider::tbDevicePara:
		strsql.Format(_T("DELETE FROM tbDevicePara"));
		break;
	case CDataProvider::tbFaultPara:
		strsql.Format(_T("DELETE FROM tbFaultPara"));
		break;
	case CDataProvider::tbProcessPara:
		strsql.Format(_T("DELETE FROM tbProcessPara"));
		break;
	case CDataProvider::tbStatePara:
		strsql.Format(_T("DELETE FROM tbStatePara"));
		break;
	default:
		break;
	}

	CtbUser tbUser;
	try{
		if (tbUser.Open(CRecordset::dynaset)){
			tbUser.m_pDatabase->ExecuteSQL(strsql);
		}
		else{
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			tbUser.Close();
			return 1;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}
	tbUser.Close();
	return 0;
}


/*�������ܣ��ض�ɾ��ö������dbTable�ṩ�ı���ɾ���ض�ID����*/

 int CDataProvider::DeleteDbTableItem(enumDBTABLE dbTable, int Id)
{
	CString strsql;

	switch (dbTable)
	{
	case CDataProvider::tbUser:
		strsql.Format(_T("DELETE FROM tbUser WHERE Id = '%d'"), Id);
		break;
	case CDataProvider::tbProductionLine:
		strsql.Format(_T("DELETE FROM tbProductionLine WHERE Id = '%d'"), Id);
		break;
	case CDataProvider::tbProcessModule:
		strsql.Format(_T("DELETE FROM tbProcessModule WHERE Id = '%d'"), Id);
		break;
	case CDataProvider::tbDevice:
		strsql.Format(_T("DELETE FROM tbDevice WHERE Id = '%d'"), Id);
		break;
	case CDataProvider::tbPLc:
		strsql.Format(_T("DELETE FROM tbPLc WHERE Id = '%d'"), Id);
		break;
	case CDataProvider::tbVideo:
		strsql.Format(_T("DELETE FROM tbVideo WHERE Id = '%d'"), Id);
		break;

	case CDataProvider::tbLoginUser:
		strsql.Format(_T("DELETE FROM tbLoginUser WHERE Id = '%d'"), Id);
		break;
	case CDataProvider::tbDevicePara:
		strsql.Format(_T("DELETE FROM tbDevicePara WHERE Id = '%d'"), Id);
		break;
	case CDataProvider::tbFaultPara:
		strsql.Format(_T("DELETE FROM tbFaultPara WHERE Id = '%d'"), Id);
		break;
	case CDataProvider::tbProcessPara:
		strsql.Format(_T("DELETE FROM tbProcessPara WHERE Id = '%d'"), Id);
		break;
	case CDataProvider::tbStatePara:
		strsql.Format(_T("DELETE FROM tbStatePara WHERE Id = '%d'"), Id);
		break;
	default:
		break;
	}

	CtbUser tbUser;
	try{
		if (tbUser.Open(CRecordset::dynaset)){
			tbUser.m_pDatabase->ExecuteSQL(strsql);
		}
		else{
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			tbUser.Close();
			return 1;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}
	tbUser.Close();
	return 0;
}



/*
����˵�������޸Ķ�Ӧ��m_vect+��Ӧ���е�ֵ���ٵ��ô˺������޸����ݿ��е�ֵ
�������ܣ���ö������dbDBTABLE �еļ������У��޸��ض�ID����Ŀ��Ӧ����Ϣ
*/
int CDataProvider::UpdateTableItem(enumDBTABLE dbTable, int Id)
{
	CString strsql;
	CProductionLineClass tempProLine;
	CProcessModuleClass tempModule;
	CDeviceClass    tempDevice;
	CPlcClass      tempPlc;
	CVideoClass    tempVideo;

	CLoginUser tempLoginUser;
	CDevicePara tempDevicePara;
	CFaultPara tempFaultPara;
	CProcessPara tempProModule;
	CStatePara tempStatePara;



	switch (dbTable)
	{
	case CDataProvider::tbUser: //�û�����һ��
		strsql.Format(_T("UPDATE tbUser SET LastUpdatedDateTime=getdate(), UserName = '%s',UserPassword='%s',UserCode='%s',Note='%s' WHERE Id ='%d'"),
			m_vectUser[0].m_strUserName, m_vectUser[0].m_strUserPasswd,
			m_vectUser[0].m_strUserCode, m_vectUser[0].m_strNote, Id);

		break;
	case CDataProvider::tbProductionLine:

		for (int i = 0; i < m_vectProductionLine.size(); i++)
		{
			if (Id == m_vectProductionLine[i].m_Id)
			{
				tempProLine = m_vectProductionLine[i];
				break;
			}

		}
		strsql.Format(_T("UPDATE tbProductionLine SET LastUpdatedDateTime=getdate(), LineName = '%s',Capacity='%s',Description='%s' WHERE Id = '%d'"),
			tempProLine.m_strLineName, tempProLine.m_strCapacity,
			tempProLine.m_strDescription, Id);
		break;
	case CDataProvider::tbProcessModule:
		for (int i = 0; i < m_vectProcessModule.size(); i++)
		{
			if (Id == m_vectProcessModule[i].m_Id)
			{
				tempModule = m_vectProcessModule[i];
				break;
			}

		}
		strsql.Format(_T("UPDATE tbProcessModule SET LastUpdatedDateTime=getdate(), ModuleName = '%s',ProductionLineName='%s',Description='%s' WHERE Id = '%d'"),
			tempModule.m_strProcessModuleName, tempModule.m_strProductionLineName,
			tempModule.m_strDescription, Id);
		break;
	case CDataProvider::tbDevice:
		for (int i = 0; i < m_vectDevice.size(); i++)
		{
			if (Id == m_vectDevice[i].m_Id)
			{
				tempDevice = m_vectDevice[i];
				break;
			}

		}
		strsql.Format(_T("UPDATE tbDevice  SET LastUpdatedDateTime=getdate(), ProductionLineName='%s',ProcessModuleName = '%s',DeviceName='%s',DeviceType='%s' WHERE Id = '%d'"),
			tempDevice.m_strProductionLineName, tempDevice.m_strProcessModuleName,
			tempDevice.m_strDeviceName, tempDevice.m_strDeviceType, Id);

		break;
	case CDataProvider::tbPLc:
		for (int i = 0; i < m_vectPlc.size(); i++)
		{
			if (Id == m_vectPlc[i].m_Id)
			{
				tempPlc = m_vectPlc[i];
				break;
			}

		}
		strsql.Format(_T("UPDATE tbPLc SET LastUpdatedDateTime=getdate(), ProductionLineName = '%s',PLCName='%s',strIPAddr='%s',ReadStartAddr='%d',ReadLength='%d',WriteStartAddr='%d',WriteLength='%d',Description='%s' WHERE Id = '%d'"),
			tempPlc.m_strProductionLineName, tempPlc.m_strPlcName,
			tempPlc.m_strIPAddr,
			tempPlc.m_ReadStartAddr,
			tempPlc.m_ReadLength,
			tempPlc.m_WriteStartAddr,
			tempPlc.m_WriteLength,
			tempPlc.m_strDescription, 
			Id);
		break;
	case CDataProvider::tbVideo:
		for (int i = 0; i < m_vectVideo.size(); i++)
		{
			if (Id == m_vectVideo[i].m_Id)
			{
				tempVideo = m_vectVideo[i];
				break;
			}

		}
		strsql.Format(_T("UPDATE tbVideo SET LastUpdatedDateTime=getdate(), ProductionLineName = '%s',ProcessModuleName='%s',VideoName='%s',IPAddr='%s' WHERE Id = '%d'"),
			tempVideo.m_strProductionLineName, tempVideo.m_strProcessModuleName,
			tempVideo.m_strVideoName, tempVideo.m_strIPAddr, Id);
		break;

	case CDataProvider::tbLoginUser:
		for (int i = 0; i < m_vectLoginUser.size(); i++)
		{
			if (Id == m_vectLoginUser[i].m_Id)
			{
				tempLoginUser = m_vectLoginUser[i];
				break;
			}
		}

		strsql.Format(_T("UPDATE tbLoginUser SET  LastLoginInTime=getdate(), LoginName = '%s',LoginPassWd='%s',PermissionLevel='%d',IsAutoLogin='%d',IsRememberPasswd='%d' WHERE Id = '%d'"),
			tempLoginUser.m_strLoginName,
			tempLoginUser.m_strLoginPassWd,
			tempLoginUser.m_PermissionLevel,
			tempLoginUser.m_IsAutoLogin,
			tempLoginUser.m_IsRememberPasswd,
			Id);
		break;
  
	case CDataProvider::tbDevicePara:
		for (int i = 0; i < m_vectDevicePara.size();i++)
		{
			if (Id==m_vectDevicePara[i].m_Id)
			{
				tempDevicePara = m_vectDevicePara[i];
				break;
			}

		}

		strsql.Format(_T("UPDATE tbDevicePara SET LastUpdatedDateTime=getdate(), ProductionLineId='%d',ProcessModuleId='%d',PLCId='%d',DeviceId='%d',ProductionLineName='%s',ProcessModuleName=%s',PlcName='%s',DeviceName='%s',ParaName='%s',ControlValue='%d',StateValue='%d',ControlAddrIndex='%s',StateAddrIndex='%s',Description='%s' WHERE Id='%d'"),
			tempDevicePara.m_ProductionLineId,
			tempDevicePara.m_ProcessModuleId,
			tempDevicePara.m_PlcId,
			tempDevicePara.m_DeviceId,
			tempDevicePara.m_strProductionLineName,
			tempDevicePara.m_strProcessModuleName,
			tempDevicePara.m_strPlcName,
			tempDevicePara.m_strDeviceName,
			tempDevicePara.m_strParaName,
			tempDevicePara.m_ControlValue,
			tempDevicePara.m_StateValue,
			tempDevicePara.m_strControlAddrIndex,
			tempDevicePara.m_strStateAddrIndex,
			tempDevicePara.m_strDescription,
			Id);
		break;

	case CDataProvider::tbFaultPara:
		for (int i = 0; i < m_vectFaultPara.size(); i++)
		{
			if (Id == m_vectFaultPara[i].m_Id)
			{
				tempFaultPara = m_vectFaultPara[i];
				break;
			}

		}

		strsql.Format(_T("UPDATE tbFaultPara SET LastUpdatedDateTime=getdate(), ProductionLineId='%d',ProcessModuleId='%d',PLCId='%d',DeviceId='%d',ProductionLineName='%s',ProcessModuleName=%s',PlcName='%s',DeviceName='%s',ControlValue='%d',StateValue='%d',ControlAddrIndex='%s',StateAddrIndex='%s',Description='%s' WHERE Id='%d'"),
			tempDevicePara.m_ProductionLineId,
			tempDevicePara.m_ProcessModuleId,
			tempDevicePara.m_PlcId,
			tempDevicePara.m_DeviceId,
			tempDevicePara.m_strProductionLineName,
			tempDevicePara.m_strProcessModuleName,
			tempDevicePara.m_strPlcName,
			tempDevicePara.m_strDeviceName,
			tempDevicePara.m_ControlValue,
			tempDevicePara.m_StateValue,
			tempDevicePara.m_strControlAddrIndex,
			tempDevicePara.m_strStateAddrIndex,
			tempDevicePara.m_strDescription,
			Id);
		break;



	default:
		break;
	}

	CtbUser tbUser;
	try{
		if (tbUser.Open(CRecordset::dynaset)){
			tbUser.m_pDatabase->ExecuteSQL(strsql);
		}
		else{
			AfxMessageBox(_T("�����ݿ�ʧ�ܣ�"));
			tbUser.Close();
			return 1;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}
	tbUser.Close();
	return 0;
}







int CDataProvider::DeleteModule(CString ProductionLineName){

	for (pModuleIter = m_vectProcessModule.begin();
		pModuleIter != m_vectProcessModule.end();)
	{
		if (pModuleIter->m_strProductionLineName == ProductionLineName)
		{
			//ɾ�����ݿ����������
			DeleteDbTableItem(CDataProvider::tbProcessModule, pModuleIter->m_Id);
			//ɾ���ڴ��������������
			pModuleIter = m_vectProcessModule.erase(pModuleIter);
		}
		else
		{
			pModuleIter++;
		}

	}
	return 0;
}


int CDataProvider::DeleteDevice(CString ProductionLineName, CString ModuleName){

	for (pDeviceIter = m_vectDevice.begin();
		pDeviceIter != m_vectDevice.end();
		)
	{
		if (pDeviceIter->m_strProductionLineName == ProductionLineName
			&& (ModuleName.IsEmpty() || pDeviceIter->m_strProcessModuleName == ModuleName))
		{
			//ɾ�����ݿ����������
			DeleteDbTableItem(CDataProvider::tbDevice, pDeviceIter->m_Id);
			//ɾ���ڴ��������������
			pDeviceIter = m_vectDevice.erase(pDeviceIter);
		}
		else{
			pDeviceIter++;
		}

	}
	return 0;

}


int CDataProvider::DeletePlc(CString ProductionLineName){

	for (pPlcIter = m_vectPlc.begin();
		pPlcIter != m_vectPlc.end();
		)
	{
		if (pPlcIter->m_strProductionLineName == ProductionLineName)
		{
			//ɾ�����ݿ����������
			DeleteDbTableItem(CDataProvider::tbPLc, pPlcIter->m_Id);
			//ɾ���ڴ��������������
			pPlcIter = m_vectPlc.erase(pPlcIter);
		}
		else
		{
			pPlcIter++;
		}

	}
	return 0;
}

int CDataProvider::DeleteVideo(CString ProductionLineName, CString ModuleName)
{

	for (pVideoIter = m_vectVideo.begin();
		pVideoIter != m_vectVideo.end();
		)
	{
		if (pVideoIter->m_strProductionLineName == ProductionLineName
			&& (ModuleName.IsEmpty() || pVideoIter->m_strProcessModuleName == ModuleName))
		{
			//ɾ�����ݿ����������
			DeleteDbTableItem(CDataProvider::tbVideo, pVideoIter->m_Id);
			//ɾ���ڴ��������������
			pVideoIter = m_vectVideo.erase(pVideoIter);
		}
		else
		{
			pVideoIter++;
		}
	}
	return 0;
}





/*  ���ݴ���Ĳ��� ProductionLineName ModuleName��
   ��m_vectDevice�������ҳ���ص�Device
   �洢����Ա���� m_vTempDevice��

   */
int CDataProvider::SearchDevice(CString ProductionLineName, CString ModuleName)
{
	m_vTempDevice.clear();
	for (pDeviceIter = m_vectDevice.begin(); pDeviceIter != m_vectDevice.end(); pDeviceIter++)
	{
		if (pDeviceIter->m_strProductionLineName==ProductionLineName
			&&pDeviceIter->m_strProcessModuleName==ModuleName)
		{
			m_vTempDevice.push_back(*pDeviceIter);
		}

	}
	return 0;
}




int CDataProvider::SearchVideo(CString ProductionLineName, CString ModuleName)
{
	m_vTempVideo.clear();
	for (pVideoIter = m_vectVideo.begin(); pVideoIter != m_vectVideo.end(); pVideoIter++)
	{
		if (pVideoIter->m_strProductionLineName == ProductionLineName
			&&pVideoIter->m_strProcessModuleName == ModuleName)
		{
			m_vTempVideo.push_back(*pVideoIter);
		}
	}
	return 0;
}
