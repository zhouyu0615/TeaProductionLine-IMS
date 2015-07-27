#pragma once
#include <vector>
#include "UserClass.h"
#include "ProcessModuleClass.h"
#include "ProductionLineClass.h"
#include "PlcClass.h"
#include "DeviceClass.h"
#include "VideoClass.h"

#include "LoginUser.h"
#include "StatePara.h"
#include "FaultPara.h"
#include "DevicePara.h"
#include "ProcessModulePara.h"






class CDataProvider
{

private:
	CDataProvider();
	CDataProvider(const CDataProvider&);
	CDataProvider& operator=(const CDataProvider &);

	static CDataProvider *Instance;
	


public:

	static CDataProvider* getInstance();
	
	~CDataProvider();



	enum enumDBTABLE {	tbUser, tbProductionLine, tbProcessModule,
		tbDevice, tbPLc, tbVideo, tbLoginUser, tbFaultPara,
		tbProcessPara, tbStatePara, tbDevicePara};

	std::vector<CLoginUser> m_vectLoginUser;

	std::vector<CUserClass> m_vectUser;
	std::vector<CProductionLineClass> m_vectProductionLine;
	std::vector<CProcessModuleClass> m_vectProcessModule;
	std::vector<CDeviceClass>  m_vectDevice;
	std::vector<CPlcClass>  m_vectPlc;
	std::vector<CVideoClass> m_vectVideo;

	std::vector<CStatePara> m_vectStatePara;
	std::vector<CFaultPara> m_vectFaultPara;
	std::vector<CProcessPara> m_vectProModulePara;
	std::vector<CDevicePara>  m_vectDevicePara;





	std::vector<CProductionLineClass>::iterator pProlineIter;
	std::vector<CProcessModuleClass>::iterator  pModuleIter;
	std::vector<CDeviceClass>::iterator        pDeviceIter;
	std::vector<CPlcClass>::iterator            pPlcIter;
	std::vector<CVideoClass>::iterator		pVideoIter;
	
	std::vector<CLoginUser>::iterator pLoginUserIter;
	std::vector<CStatePara>::iterator pStateParaIter;
	std::vector<CProcessPara>::iterator pProcessParaIter;
	std::vector<CFaultPara>::iterator pFaultParaIter;
	std::vector<CDevicePara>::iterator pDeviceParaIter;



	void  InitDataProvider();
	
	void ReadLoginUserFormDatabase();
	void AddLoginUserToDatabase(CLoginUser tempLoginUser);

	void AddUserToDatabase(CUserClass tempUser);
	void ReadUserFromDatabase();
	void AddProLineToDatabase(CProductionLineClass tempProLine);
	void ReadProLineFromDatabase();

	void AddProModuleToDatabase(CProcessModuleClass tempProModule);
	void ReadProModuleFromDatabase();
	void ReadDeviceFromDatabase();
	void AddDeviceToDatabase(CDeviceClass tempDevice);
	void ReadPlcFromDatabase();
	void AddPlcToDatabase(CPlcClass tempPlc);
	void ReadVideoFromDatabase();
	void AddVideoToDatabase(CVideoClass tempVideo);


	void ReadDeviceParaFromDatabase();
	void AddDeviceParaToDatabase(CDevicePara tempDevice);

	void ReadFaultParaFromDatabase();
	void AddFaultParaToDatabase(CFaultPara tempFaultPara);
	
	void ReadProcessParaFromDatabase();
	void AddProcessParaToDatabase(CProcessPara tempProcessPara);

	void ReadStateParaFromDatabase();
	void AddStateParaToDatabase(CStatePara tempStatePara);

	int UpdateTableItem(enumDBTABLE dbTable, int Id);

	int DeleteDbTable(enumDBTABLE dbTable);

    int DeleteDbTableItem(enumDBTABLE dbTable, int Id);


	


	int DeleteModule(CString ProductionLineName);
	int DeleteDevice(CString ProductionLineName, CString ModuleName=_T(""));
	int DeletePlc(CString ProductionLineName);
	int DeleteVideo(CString ProductionLineName, CString ModuleName=_T(""));


	
	//�����ṩ�����������������ҵ������ߵ�ID,����ʧ���򷵻�0
	int FindProLineId(CString ProducitonLineName);
	//�����ṩ������������ģ�����������ҵ�����������ģ���ID,����ʧ���򷵻�0
	int FindProModuleId(CString ProductionLineName, CString ModuleName);

	int FindPlcId(CString PlcName);
	int FindDeviceId(CString ProductionLineName, CString ModuleName, CString DeviceName);


	//��ΪSearch Device,PlcPara,Video ������ʱ�洢���м�����
	std::vector<CDeviceClass> m_vTempDevice;
	std::vector<CVideoClass> m_vTempVideo;

	int SearchDevice(CString ProductionLineName, CString ModuleName);
	int SearchVideo(CString ProducitonLinaName, CString ModuleName);



	

};

