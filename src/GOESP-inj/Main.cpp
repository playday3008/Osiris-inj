﻿#include <Windows.h>
#include <TlHelp32.h>
// Junk code to make injector undetected
#include "JunkCode.h"
#include <iostream>
#include <filesystem>

#include "JunkDef.h"

#define DLL_NAME "GOESP.dll"

// Don't change this!
#define _JUNK_BLOCK(s) __asm jmp s JUNKS __asm s:


/////////////////////////////////////////////////////////////////////////////////////
//                                 INJECTOR CODE                                   //
/////////////////////////////////////////////////////////////////////////////////////

DWORD Process(char* ProcessName)
{
	_JUNK_BLOCK(jmp_label1)
	HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	
	_JUNK_BLOCK(jmp_label2)
	PROCESSENTRY32 ProcEntry;
	
	_JUNK_BLOCK(jmp_label3)
	ProcEntry.dwSize = sizeof(ProcEntry);
	
	_JUNK_BLOCK(jmp_label4)
	do
	{
		_JUNK_BLOCK(jmp_label5)
		if (!strcmp(ProcEntry.szExeFile, ProcessName))
		{
			_JUNK_BLOCK(jmp_label6)
			DWORD dwPID = ProcEntry.th32ProcessID;
			
			_JUNK_BLOCK(jmp_label7)
			CloseHandle(hPID);
			
			_JUNK_BLOCK(jmp_label8)
			return dwPID;
		}
		
		_JUNK_BLOCK(jmp_label9)
	}
	while (Process32Next(hPID, &ProcEntry));
	
	_JUNK_BLOCK(jmp_label10)
}

//   ____    ___                      ____                                                      
//  /\  _`\ /\_ \                    /\  _`\                                                    
//  \ \ \L\ \//\ \      __     __  __\ \ \/\ \     __     __  __                                
//   \ \ ,__/ \ \ \   /'__`\  /\ \/\ \\ \ \ \ \  /'__`\  /\ \/\ \                               
//    \ \ \/   \_\ \_/\ \L\.\_\ \ \_\ \\ \ \_\ \/\ \L\.\_\ \ \_\ \                              
//     \ \_\   /\____\ \__/.\_\\/`____ \\ \____/\ \__/.\_\\/`____ \                             
//      \/_/   \/____/\/__/\/_/ `/___/> \\/___/  \/__/\/_/ `/___/> \                            
//                                 /\___/                     /\___/                            
//   

void bypass(DWORD dwProcess)
{
	// Restore original NtOpenFile from external process
	//credits: Daniel Krupiñski(pozdro dla ciebie byczku <3)
	_JUNK_BLOCK(jmp_label11)
	HANDLE csgoProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcess);
	_JUNK_BLOCK(jmp_label12)
	LPVOID ntOpenFile = GetProcAddress(LoadLibraryW(L"ntdll"), "NtOpenFile");
	if (ntOpenFile) {
		_JUNK_BLOCK(jmp_label13)
		char originalBytes[5];
		_JUNK_BLOCK(jmp_label4)
		memcpy(originalBytes, ntOpenFile, 5);
		_JUNK_BLOCK(jmp_label15)
		WriteProcessMemory(csgoProcessHandle, ntOpenFile, originalBytes, 5, NULL);
	}
}

int main()
{
	std::cout << "   ____       _      _         __   __________  ___________ ____ " << std::endl;
	Sleep(50);
	std::cout << "  / __ \\_____(_)____(_)____   / /  / ____/ __ \\/ ____/ ___// __ \\" << std::endl;
	Sleep(50);
	std::cout << " / / / / ___/ / ___/ / ___/  / /  / / __/ / / / __/  \\__ \\/ /_/ /" << std::endl;
	Sleep(50);
	std::cout << "/ /_/ (__  ) / /  / (__  )  / /  / /_/ / /_/ / /___ ___/ / ____/ " << std::endl;
	Sleep(50);
	std::cout << "\\____/____/_/_/  /_/____/  / /   \\____/\\____/_____//____/_/      " << std::endl;
	Sleep(50);
	std::cout << "    ____  __            __///                                    " << std::endl;
	Sleep(50);
	std::cout << "   / __ \\/ /___ ___  __/ __ \\____ ___  __                        " << std::endl;
	Sleep(50);
	std::cout << "  / /_/ / / __ `/ / / / / / / __ `/ / / /                        " << std::endl;
	Sleep(50);
	std::cout << " / ____/ / /_/ / /_/ / /_/ / /_/ / /_/ /                         " << std::endl;
	Sleep(50);
	std::cout << "/_/   /_/\\__,_/\\__, /_____/\\__,_/\\__, /                          " << std::endl;
	Sleep(50);
	std::cout << "              /____/            /____/                           " << std::endl << std::endl;
	Sleep(50);
		if (std::filesystem::exists(DLL_NAME)) {
				std::cout << "Founded DLL: " << DLL_NAME << std::endl;
		}
		else if (!std::filesystem::exists(DLL_NAME)) {
				std::cout << "Can't find: " << DLL_NAME << std::endl;
				system("pause");
				return 0;
		}
	Sleep(2000);
	_JUNK_BLOCK(jmp_label16)
	DWORD dwProcess;
	
	_JUNK_BLOCK(jmp_label17)
	char myDLL[MAX_PATH];
	
	_JUNK_BLOCK(jmp_label18)
	GetFullPathName(DLL_NAME, MAX_PATH, myDLL, 0);
	
	_JUNK_BLOCK(jmp_label9)
	dwProcess = Process("csgo.exe");

	_JUNK_BLOCK(jmp_label20)
	bypass(dwProcess);

	_JUNK_BLOCK(jmp_label21)
	pBut();
	yAD();
	mop();
	LlKk();
	AfUh();
	HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, dwProcess);

	_JUNK_BLOCK(jmp_label22)
	xtXP();
	BNxW();
	Wchh();
	Xze();
	DbL();
	LPVOID allocatedMem = VirtualAllocEx(hProcess, NULL, sizeof(myDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

	_JUNK_BLOCK(jmp_label23)
	dmfc();
	tXm();
	dgm();
	qmY();
	MYa();
	WriteProcessMemory(hProcess, allocatedMem, myDLL, sizeof(myDLL), NULL);

	_JUNK_BLOCK(jmp_label24)
	gHo();
	iHj();
	TNsp();
	DHaz();
	SieU();
	CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, allocatedMem, 0, 0);

	_JUNK_BLOCK(jmp_label25)
	CloseHandle(hProcess);

	_JUNK_BLOCK(jmp_label26)
	return 0;
}