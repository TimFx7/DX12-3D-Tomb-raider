
#include <iostream>
#include <Windows.h>
using namespace std;

int WINAPI WinMain(HINSTANCE inst, HINSTANCE prev, LPSTR cmd, int show)
{
	HWND GameWindow;
	DWORD pID;
	HANDLE hnd;
	int kez = 0;

	// memory address of Shadow of the Tomb Raider 3d vision key
	DWORD StaticAddress = 0x806F14F4;
	DWORD Stereoscopic = 2;  // 3D Vision ON  (0= off  1= SBS  2= 3D Vision)

	GameWindow = FindWindowA(NULL, "Shadow of the Tomb Raider v1.0 build 296.0_64");

	while (GameWindow == NULL & kez <= 60)
	{
		Sleep(1000);
		GameWindow = FindWindowA(NULL, "Shadow of the Tomb Raider v1.0 build 296.0_64");
		kez ++;

		if (kez == 60)
		{
			MessageBox(nullptr, TEXT("Shadow of the Tomb Raider v1.0 build 296.0_64 uninitialized. \n		Please start the game first"), TEXT("WARNING : Enabling 3D Vision"), MB_SETFOREGROUND | MB_ICONASTERISK | MB_OK);
			return 0;
		}

	}	   

	GetWindowThreadProcessId(GameWindow, &pID);
	hnd = OpenProcess(PROCESS_ALL_ACCESS, false, pID);
	while (FindWindowA(NULL, "Shadow of the Tomb Raider v1.0 build 296.0_64")) {
		WriteProcessMemory(hnd, (LPVOID)(StaticAddress), &Stereoscopic, sizeof(DWORD), 0);
		Sleep(1000);
	}
	return 0;


}
