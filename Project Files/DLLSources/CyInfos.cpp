#include "CvGameCoreDLL.h"
#include "CyInfos.h"

int CyCivilizationInfo::getDefaultPlayerColor() const
{
	return CvCivilizationInfo::getDefaultPlayerColor();
}

int CyCivilizationInfo::getArtStyleType() const
{
	return CvCivilizationInfo::getArtStyleType();
}

int CyCivilizationInfo::getUnitArtStyleType() const
{
	return CvCivilizationInfo::getUnitArtStyleType();
}

int CyCivilizationInfo::getDefaultProfession() const
{
	return CvCivilizationInfo::getDefaultProfession();
}

int CyCivilizationInfo::getNumCityNames() const
{
	return CvCivilizationInfo::getNumCityNames();
}

int CyCivilizationInfo::getNumLeaders() const
{
	return CvCivilizationInfo::getNumLeaders();
}

int CyCivilizationInfo::getSelectionSoundScriptId() const
{
	return CvCivilizationInfo::getSelectionSoundScriptId();
}

int CyCivilizationInfo::getActionSoundScriptId() const
{
	return CvCivilizationInfo::getActionSoundScriptId();
}

int CyCivilizationInfo::getAdvancedStartPoints() const
{
	return CvCivilizationInfo::getAdvancedStartPoints();
}

int CyCivilizationInfo::getAreaMultiplier() const
{
	return CvCivilizationInfo::getAreaMultiplier();
}

int CyCivilizationInfo::getDensityMultiplier() const
{
	return CvCivilizationInfo::getDensityMultiplier();
}

int CyCivilizationInfo::getTreasure() const
{
	return CvCivilizationInfo::getTreasure();
}

int CyCivilizationInfo::getFavoredTerrain() const
{
	return CvCivilizationInfo::getFavoredTerrain();
}

int CyCivilizationInfo::getCapturedCityUnitClass() const
{
	return CvCivilizationInfo::getCapturedCityUnitClass();
}

int CyCivilizationInfo::getCivilizationBuildings(int i) const
{
	return CvCivilizationInfo::getCivilizationBuildings(i);
}

int CyCivilizationInfo::getCivilizationUnits(int i) const
{
	return CvCivilizationInfo::getCivilizationUnits(i);
}

int CyCivilizationInfo::getNumCivilizationFreeUnits() const
{
	return CvCivilizationInfo::getNumCivilizationFreeUnits();
}

int CyCivilizationInfo::getCivilizationFreeUnitsClass(int index) const
{
	return CvCivilizationInfo::getCivilizationFreeUnitsClass(index);
}

int CyCivilizationInfo::getCivilizationFreeUnitsProfession(int index) const
{
	return CvCivilizationInfo::getCivilizationFreeUnitsProfession(index);
}

int CyCivilizationInfo::getCivilizationInitialCivics(int i) const
{
	return CvCivilizationInfo::getCivilizationInitialCivics(i);
}

int CyCivilizationInfo::getFreeYields(int i) const
{
	return CvCivilizationInfo::getFreeYields(i);
}

int CyCivilizationInfo::getTeachUnitClassWeight(int i) const
{
	return CvCivilizationInfo::getTeachUnitClassWeight(i);
}

bool CyCivilizationInfo::isLeaders(int i) const
{
	return CvCivilizationInfo::isLeaders(i);
}

bool CyCivilizationInfo::isCivilizationFreeBuildingClass(int i) const
{
	return CvCivilizationInfo::isCivilizationFreeBuildingClass(i);
}

bool CyCivilizationInfo::isValidProfession(int i) const
{
	return CvCivilizationInfo::isValidProfession(i);
}

bool CyCivilizationInfo::hasTrait(int i) const
{
	return CvCivilizationInfo::hasTrait(i);
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
