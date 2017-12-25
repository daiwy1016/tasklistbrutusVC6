#pragma once

#include <windows.h>


#pragma comment(lib,"ntdll.lib")

extern "C"
{
	PVOID  __stdcall RtlImageDirectoryEntryToData(IN PVOID ,IN BOOLEAN ,IN USHORT ,OUT PULONG );
};




