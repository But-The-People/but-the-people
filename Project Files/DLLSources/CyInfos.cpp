#include "CvGameCoreDLL.h"
#include "CyInfos.h"

int CyCivilizationInfo::getUnitArtStyleType() const
{
	return CvCivilizationInfo::getUnitArtStyleType();
}

int CyFeatureInfo::getYieldChange(int iYield) const
{
	return CvFeatureInfo::getYieldChange(static_cast<YieldTypes>(iYield));
}

int CyFeatureInfo::getRiverYieldIncrease(int iYield) const
{
	return CvFeatureInfo::getRiverYieldIncrease(static_cast<YieldTypes>(iYield));
}

bool CyFeatureInfo::isTerrain(int iTerrain) const
{
	return CvFeatureInfo::isTerrain(static_cast<TerrainTypes>(iTerrain));
}

int CyLeaderHeadInfo::getContactRand(int iContact) const
{
	return CvLeaderHeadInfo::getContactRand(static_cast<ContactTypes>(iContact));
}

int CyLeaderHeadInfo::getContactDelay(int iContact) const
{
	return CvLeaderHeadInfo::getContactDelay(static_cast<ContactTypes>(iContact));
}

int CyLeaderHeadInfo::getMemoryDecayRand(int iMemory) const
{
	return CvLeaderHeadInfo::getMemoryDecayRand(static_cast<MemoryTypes>(iMemory));
}

int CyLeaderHeadInfo::getMemoryAttitudePercent(int iMemory) const
{
	return CvLeaderHeadInfo::getMemoryAttitudePercent(static_cast<MemoryTypes>(iMemory));
}

int CyLeaderHeadInfo::getNoWarAttitudeProb(int iAttitude) const
{
	return CvLeaderHeadInfo::getNoWarAttitudeProb(static_cast<AttitudeTypes>(iAttitude));
}

int CyLeaderHeadInfo::getUnitAIWeightModifier(int iUnitAI) const
{
	return CvLeaderHeadInfo::getUnitAIWeightModifier(static_cast<UnitAITypes>(iUnitAI));
}

int CyLeaderHeadInfo::getImprovementWeightModifier(int iImprovement) const
{
	return CvLeaderHeadInfo::getImprovementWeightModifier(static_cast<ImprovementTypes>(iImprovement));
}

bool CyLeaderHeadInfo::hasTrait(int iTrait) const
{
	return CvLeaderHeadInfo::hasTrait(static_cast<TraitTypes>(iTrait));
}

int CyProfessionInfo::getPediaUnitGraphics() const
{
	return CvProfessionInfo::getPediaUnitGraphics();
}

int CyTerrainInfo::getRiverYieldIncrease(int iYield) const
{
	return CvTerrainInfo::getRiverYieldIncrease(static_cast<YieldTypes>(iYield));
}

int CyTerrainInfo::getYield(int iYield) const
{
	return CvTerrainInfo::getYield(static_cast<YieldTypes>(iYield));
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
