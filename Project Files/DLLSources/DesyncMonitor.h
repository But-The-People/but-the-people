#pragma once

// This class adds the abiilty to detect network OOS even in singleplayer
//
// The concept is that functions, which are called in async mode only will start by declaring an instance of CxDesyncMonitor
// It will never be used. It just has to be there to be allocated as a local variable.
// Examples of this would be the exe calling UI elements in the DLL like widgets and popup windows.
//
// CxDesyncMonitor::isSynced() can then be called in code, which has to be synced.
// THe function relies on an internal counter, which tells if any instances have been allocated, hence exist in the call stack.

class CxDesyncMonitor
{
public:
	CxDesyncMonitor();
	~CxDesyncMonitor();

	static bool isSynced();
};
