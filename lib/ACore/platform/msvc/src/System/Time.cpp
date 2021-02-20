
#include "Time.h"

#include <Windows.h>

namespace Time {

F8 ACORE_DLL_EXPORT getTime(){
	LARGE_INTEGER pc;
	QueryPerformanceCounter(&pc);
	LARGE_INTEGER freq;
	QueryPerform