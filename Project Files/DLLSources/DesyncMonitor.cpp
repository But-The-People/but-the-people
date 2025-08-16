#include "DesyncMonitor.h"

static int COUNT = 0;

CxDesyncMonitor::CxDesyncMonitor()
{
	COUNT++;
}

CxDesyncMonitor::~CxDesyncMonitor()
{
	COUNT--;
}

bool CxDesyncMonitor::isSynced()
{
	return COUNT == 0;
}

