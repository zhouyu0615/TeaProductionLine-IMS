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
	void UpdateUserLoginTime(int LoginUserId);

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


	
	//根据提供的生产线名，返回找到生产线的ID,查找失败则返回0
	int FindProLineId(CString ProducitonLineName);
	//根据提供的生产线名，模块名，返回找到的所属工艺模块的ID,查找失败则返回0
	int FindProModuleId(CString ProductionLineName, CString ModuleName);

	int FindPlcId(CString PlcName);
	int FindDeviceId(CString ProductionLineName, CString ModuleName, CString DeviceName);


	//作为Search Device,PlcPara,Video 方法临时存储的中间容器
	std::vector<CDeviceClass> m_vTempDevice;
	std::vector<CVideoClass> m_vTempVideo;

	int SearchDevice(CString ProductionLineName, CString ModuleName);
	int SearchVideo(CString ProducitonLinaName, CString ModuleName);


	int UpdateRelatedToLine(int LineId, CString modifyLineName);
	int UpdateRelatedToModule(int ModuleId, CString modifyModuleName);
	int UpdateRelatedToPlc(int PlcId, CString modifyPlcName);

	

};

