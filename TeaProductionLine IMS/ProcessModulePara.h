#pragma once
class CProcessPara
{
public:
	CProcessPara();
	~CProcessPara();
	enum enumValueType {
		EM_VALUETYPE_BOOL, EM_VALUETYPE_BYTE, EM_VALUETYPE_SHORT, EM_VALUETYPE_LONG, EM_VALUETYPE_FLOAT, EM_VALUETYPE_DOUBLE	};

	int m_Id;
	int m_ProcessModuleId;
	int m_ProductionLineId;
	CString m_strCreatedDateTime;
	CString  m_strLastUpdatedDateTime;
	CString m_strProductionLineName;
	CString m_strProcessModuleName;
	CString m_strPlcName;
	CString m_strDescription;
	int m_ParaValue;
	CString m_strParaName;
	int m_IsConfig;
	int m_IsVisible;
	int m_ValueType;
	CString m_strAddressIndex;
	CString m_strAddressType;
	int m_PlcId;
};

