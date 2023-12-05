#include <iostream>
#include <Windows.h>

int health = 100000;

DWORD_PTR MAGS_ADDRESS = 0x0075C0C0; // Local Ammors Memory Address
DWORD_PTR HEALTH_ADDRESS = 0x0075C06C; // Local Health Memory Address
LPCWSTR ac = L"AssaultCube"; //Attach Window Name

int ac_bullets;
int health_read;
int ammor_read;
 
using namespace std;

int main() {
	
	HWND game = FindWindow(NULL, ac); //game window definition

	if (!game) {
		exit;
	}

	DWORD process; //process var

	GetWindowThreadProcessId(game, &process);
	HANDLE handler = OpenProcess(PROCESS_ALL_ACCESS, false, process); //opening handle from process and setup some perms

	if (!handler) {
		cout << "Process not found.";
		exit;
	}

	

	//UM
	while (TRUE){

		ReadProcessMemory(handler, (LPCVOID)HEALTH_ADDRESS, &health_read, sizeof(int), 0);
		ReadProcessMemory(handler, (LPCVOID)MAGS_ADDRESS, &ammor_read, sizeof(int), 0);

		if (GetAsyncKeyState('R') & 0x8000) {
			health_read += 10;
			WriteProcessMemory(
				handler, 
				(LPVOID)HEALTH_ADDRESS, 
				&health_read, sizeof(health_read), 
				NULL);
			std::cout << "Memory Overwrited." << std::endl;

		}

		if (GetAsyncKeyState('F') & 0x8000) {
			ammor_read += 1;
			WriteProcessMemory(
				handler,
				(LPVOID)MAGS_ADDRESS,
				&ammor_read, sizeof(ammor_read),
				NULL);
			std::cout << "Memory Overwrited." << std::endl;

		}


	}




}