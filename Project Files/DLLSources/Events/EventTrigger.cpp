#include "EventTrigger.h"

EventTriggeredData::EventTriggeredData()
{
	resetSavedData();
}

int EventTriggeredData::getID() const
{
	return m_iId;
}

void EventTriggeredData::setID(int iID)
{
	m_iId = iID;
}


