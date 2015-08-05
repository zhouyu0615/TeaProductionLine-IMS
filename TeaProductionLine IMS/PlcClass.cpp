#include "stdafx.h"
#include "PlcClass.h"


CPlcClass::CPlcClass()
{
	m_Id = 0;
	m_strPlcName = _T("");
	m_strDescription = _T("");
	m_strProductionLineName = _T("");
	m_strIPAddr = _T("");
	m_UserId = 0;
	m_ReadStartAddr = 0;
	m_ReadLength = 0;
	m_WriteStartAddr = 0;
	m_WriteLength = 0;
	m_SortIndex = 0;
}


CPlcClass::~CPlcClass()
{
}
