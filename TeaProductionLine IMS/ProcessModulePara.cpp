#include "stdafx.h"
#include "ProcessModulePara.h"


CProcessPara::CProcessPara()
{
	m_Id = 0;
	m_ProcessModuleId = 0;
	m_ProductionLineId = 0;
	m_strProductionLineName = _T("");
	m_strProcessModuleName = _T("");
	m_strPlcName = _T("");
	m_strDescription = _T("");
	m_ParaValue = 0;
	m_strParaName = _T("");
	m_IsConfig = 0;
	m_IsReadOnly = 0;
	m_ValueType = 0;
	m_strAddressIndex = _T("");
	m_strAddressType = _T("");
	m_PlcId = 0;
	m_strCreatedDateTime = _T("");
	m_strLastUpdatedDateTime = _T("");
}


CProcessPara::~CProcessPara()
{
}
