#include "CvGameCoreDLL.h"
#include "CvTradeRoute.h"
#include "CvDLLInterfaceIFaceBase.h"
#include "CvSavegame.h"
#include "CvCity.h"
#include "CvEnums.h"

CvTradeRoute::CvTradeRoute() :
	m_iId(ANYWHERE_CITY_ID),
	m_eYield(NO_YIELD)
{

}

CvTradeRoute::~CvTradeRoute()
{

}

void CvTradeRoute::init(const IDInfo& kSourceCity, const IDInfo& kDestinationCity, YieldTypes eYield)
{
	m_kSourceCity = kSourceCity;
	m_kDestinationCity = kDestinationCity;
	m_eYield = eYield;
}

int CvTradeRoute::getID() const
{
	return m_iId;
}

void CvTradeRoute::setID(int iId)
{
	m_iId = iId;
}

const IDInfo& CvTradeRoute::getSourceCity() const
{
	return m_kSourceCity;
}

void CvTradeRoute::setSourceCity(const IDInfo& kCity)
{
	if (getSourceCity() != kCity)
	{
		setActiveDirty();
		const IDInfo& kOldCity = getSourceCity();

		m_kSourceCity = kCity;

		CvCity* pCity = ::getCity(getSourceCity());
		FAssert(pCity != NULL);
		if (pCity != NULL)
		{
			pCity->updateExport(getYield());
		}

		pCity = ::getCity(kOldCity);
		FAssert(pCity != NULL);
		if (pCity != NULL)
		{
			pCity->updateExport(getYield());
		}

		setActiveDirty();
	}
}

const wchar* CvTradeRoute::getSourceCityNameKey() const
{
	if (getSourceCity().iID == EUROPE_CITY_ID)
	{
		return L"TXT_KEY_CONCEPT_EUROPE";
	}

	CvCity* pCity = ::getCity(getSourceCity());
	FAssert(pCity != NULL);
	if (pCity != NULL)
	{
		return pCity->getNameKey();
	}

	return L"";
}

const IDInfo& CvTradeRoute::getDestinationCity() const
{
	return m_kDestinationCity;
}

void CvTradeRoute::setDestinationCity(const IDInfo& kCity)
{
	if (getDestinationCity() != kCity)
	{
		setActiveDirty();
		const IDInfo& kOldCity = getDestinationCity();

		m_kDestinationCity = kCity;

		CvCity* pCity = ::getCity(getDestinationCity());
		FAssert(pCity != NULL || getDestinationCity().iID == EUROPE_CITY_ID);
		if (pCity != NULL)
		{
			pCity->updateImport(getYield());
		}

		pCity = ::getCity(kOldCity);
		FAssert(pCity != NULL || getDestinationCity().iID == EUROPE_CITY_ID);
		if (pCity != NULL)
		{
			pCity->updateImport(getYield());
		}

		setActiveDirty();
	}
}

const wchar* CvTradeRoute::getDestinationCityNameKey() const
{
	if (getDestinationCity().iID == EUROPE_CITY_ID)
	{
		return L"TXT_KEY_CONCEPT_EUROPE";
	}

	CvCity* pCity = ::getCity(getDestinationCity());
	FAssert(pCity != NULL);
	if (pCity != NULL)
	{
		return pCity->getNameKey();
	}

	return L"";
}


YieldTypes CvTradeRoute::getYield() const
{
	return m_eYield;
}

void CvTradeRoute::setYield(YieldTypes eYield)
{
	if (getYield() != eYield)
	{
		YieldTypes  eOldYield = getYield();

		m_eYield = eYield;

		CvCity* pCity = ::getCity(getDestinationCity());
		FAssert(pCity != NULL);
		if (pCity != NULL)
		{
			pCity->updateImport(getYield());
			pCity->updateImport(eOldYield);
		}

		pCity = ::getCity(getSourceCity());
		FAssert(pCity != NULL);
		if (pCity != NULL)
		{
			pCity->updateExport(getYield());
			pCity->updateExport(eOldYield);
		}

		setActiveDirty();
	}
}

bool CvTradeRoute::checkValid(PlayerTypes ePlayer) const
{
	CvPlayer& kPlayer = GET_PLAYER(ePlayer);

	if (!kPlayer.canLoadYield(getSourceCity().eOwner))
	{
		return false;
	}

	if (!kPlayer.canLoadYield(getDestinationCity().eOwner))
	{
		return false;
	}

	if (getDestinationCity().iID == EUROPE_CITY_ID)
	{
		if (!kPlayer.isYieldEuropeTradable(getYield()))
		{
			return false;
		}
	}

	return true;
}

void CvTradeRoute::setActiveDirty()
{
	if (getDestinationCity().eOwner == GC.getGameINLINE().getActivePlayer())
	{
		gDLL->getInterfaceIFace()->setDirty(Domestic_Advisor_DIRTY_BIT, true);
	}

	if (getSourceCity().eOwner == GC.getGameINLINE().getActivePlayer())
	{
		gDLL->getInterfaceIFace()->setDirty(Domestic_Advisor_DIRTY_BIT, true);
	}
}

// Custom_House_Mod Start
int CvTradeRoute::getBestPortCityID(PlayerTypes ePlayer) const
{
	return (GET_PLAYER(ePlayer).AI_findBestPort()->getIDInfo().iID);
}

int CvTradeRoute::getDistanceBetweenCities() const
{
	CvCity* sourceCity = getCity(m_kSourceCity);
	CvCity* destinationCity = getCity(m_kDestinationCity);

	if (NULL == sourceCity)
	{
		return -1;
	}

	if (NULL == destinationCity)
	{
		return -1;
	}

	return GC.getMap().calculatePathDistance(sourceCity->getCityIndexPlot(CITY_HOME_PLOT), destinationCity->getCityIndexPlot(CITY_HOME_PLOT));
}

int CvTradeRoute::getImportAmount() const
{
	CvCity* destinationCity = getCity(m_kDestinationCity);

	if (NULL == destinationCity)
	{
		return -1;
	}

	return destinationCity->getMaxImportAmount(m_eYield);
}

// Custom_House_Mod End
