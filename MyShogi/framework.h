// header.h : include file for standard system include files,
// or project specific include files
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#pragma comment(lib, "Msimg32.lib")     // for TransparentBlt
// C RunTime Header Files
#include <cstdlib>
#include <memory>
#include <vector>
#include <tuple>
