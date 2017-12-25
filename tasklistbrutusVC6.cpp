// tasklistbrutusVC6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;



#if defined(_WIN64)
 typedef unsigned __int64 ULONG_PTR;
#else
 typedef unsigned long ULONG_PTR;
#endif

typedef ULONG_PTR SIZE_T;


struct SYSTEM_PROCESS_ID_INFORMATION 
{
	PVOID process_id;
	UNICODE_STRING image_name;
};

typedef LONG (WINAPI *PROCNTQSI)(SYSTEM_INFORMATION_CLASS, PVOID, ULONG, PULONG);
PROCNTQSI NtQuerySystemInformationEx;

int main(int argc, char* argv[])
{
	printf("Hello World!\n");
	SYSTEM_INFORMATION_CLASS class_id= static_cast<_SYSTEM_INFORMATION_CLASS>(0x58);
	auto size = sizeof(SYSTEM_PROCESS_ID_INFORMATION);
	for (size_t id = 0; id < 10000; id += 4)
	{
		SYSTEM_PROCESS_ID_INFORMATION buffer ={0};
		buffer.image_name.MaximumLength = 250;
		buffer.image_name.Buffer = new wchar_t[250];
		buffer.process_id = reinterpret_cast<PVOID>(id);
		PWSTR temp_buffer = buffer.image_name.Buffer; // NtQuerySystemInformation will null it if process name is not found
		ULONG return_length;
		//NtQuerySystemInformationEx = (PROCNTQSI)GetProcAddress(GetModuleHandle(TEXT("ntdll")), "NtQuerySystemInformation");
		//NtQuerySystemInformationEx(class_id, &buffer, size, &return_length);
		
		if (NtQuerySystemInformation(class_id, &buffer, size, &return_length) == ERROR_SUCCESS) // VALID PROCESS ID
		{
			if (buffer.image_name.Buffer)
			{
				std::wcout << id << " - " << buffer.image_name.Buffer << std::endl;
			}
			else
			{
				std::wcout << id << " - <empty>" << std::endl;
			}
		}

		delete temp_buffer;
	}

	MessageBox(0,TEXT("ntdll"),TEXT("ntdll"),0);

	return 0;
}

