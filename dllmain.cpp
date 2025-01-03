// dllmain.cpp : Defines the entry point for the DLL application.

#if PROXY
    #include "version/version.h";
#else
    #include <Windows.h>
#endif

#include <iostream>


// Get handle from the injected process
HANDLE aoe_handle = GetCurrentProcess();


// Spawn thread to do work
DWORD WINAPI MainThread(LPVOID param) {
    // Get base address from the injected process
	uintptr_t base = (uintptr_t)GetModuleHandle(NULL);

	while (true) {


		Sleep(100);
	}
	return 0;
}


// Main DLL entry point
// Main DLL entry point
BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		// Allocate a console
		AllocConsole();
		FILE* f;
		freopen_s(&f, "CONOUT$", "w", stdout);

		// Log a message
		std::cout << "DLL loaded successfully!" << std::endl;

		// Handle proxy calls to version.dll
#if PROXY
		setupWrappers();
#endif

		// Create thread
		CreateThread(0, 0, MainThread, hModule, 0, 0);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		// Close the console when the DLL is detached
		if (ul_reason_for_call == DLL_PROCESS_DETACH) {
			FreeConsole();
		}
		break;
	}
	return TRUE;
}

