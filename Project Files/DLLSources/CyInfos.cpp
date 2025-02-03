#include "CvGameCoreDLL.h"
#include "CyInfos.h"

int CyCivilizationInfo::getUnitArtStyleType() const
{
	return CvCivilizationInfo::getUnitArtStyleType();
}

int CyProfessionInfo::getPediaUnitGraphics() const
{
	return CvProfessionInfo::getPediaUnitGraphics();
}

int CyUnitInfo::getDefaultProfession() const
{
	return CvUnitInfo::getDefaultProfession();
}

int CyUnitInfo::getLeaderPromotion() const
{
	return CvUnitInfo::getLeaderPromotion();
}

int CyUnitInfo::getUnitClassType() const
{
	return CvUnitInfo::getUnitClassType();
}

const CvArtInfoUnit* CyUnitInfo::getUnitArtStylesArtInfo(int index, int iProfession, int iStyle) const
{
	return CvUnitInfo::getUnitArtStylesArtInfo(index, static_cast<ProfessionTypes>(iProfession), static_cast<UnitArtStyleTypes>(iStyle));
}
