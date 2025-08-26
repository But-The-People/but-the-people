#pragma once

#include "../CvGameCoreDLL.h"

class CvSavegameReader;
class CvSavegameWriter;

class EventTriggeredData
{
public:
	EventTriggeredData();

	int m_iId;
	EventTriggerTypes m_eTrigger;
	int m_iTurn;
	PlayerTypes m_ePlayer;
	int m_iCityId;
	int m_iPlotX;
	int m_iPlotY;
	int m_iUnitId;
	PlayerTypes m_eOtherPlayer;
	int m_iOtherPlayerCityId;
	BuildingTypes m_eBuilding;
	CvWString m_szText;
	CvWString m_szGlobalText;

	int getID() const;
	void setID(int iID);

	void resetSavedData();

	void read(CvSavegameReader& reader);
	void readVanilla(CvSavegameReader& reader);
	void write(CvSavegameWriter& writer) const;

};
