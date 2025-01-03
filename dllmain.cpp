// dllmain.cpp : Defines the entry point for the DLL application.

#if PROXY
    #include "version/version.h";
#else
    #include <Windows.h>
#endif


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
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
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
        break;
    }
    return TRUE;
}

