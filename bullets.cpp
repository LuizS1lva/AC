#include <iostream>
#include <Windows.h>

using namespace std;

DWORD_PTR BULLETS_MEMO_ADDRESS = 0x0075C0C0;
LPCWSTR ac = L"AssaultCube"; /*"L" prefix, you indicate to the compiler that the string literal should be treated as a wide string literal, and its type will be const wchar_t* (wide character pointer). */

int in_bullets, ac_bullets;


int main() {
    HWND game = FindWindow(NULL, ac);

    if (!game) {
        cout << "Game Window Not Found.";

        exit;
    }

    DWORD process;

    GetWindowThreadProcessId(game, &process);
    HANDLE handler = OpenProcess(PROCESS_ALL_ACCESS, false, process);

    if (!handler) {
        cout << "Process not found.";
        exit;
    }


    //UM
    cout << "Bullets to Register > ";
    cin >> in_bullets;

    while (TRUE)
    {
        ReadProcessMemory(handler, (LPVOID)BULLETS_MEMO_ADDRESS, &ac_bullets, sizeof(int), 0);
        cout << "Actually Bullets in AC: " << ac_bullets << endl;
        system("cls");        /* code */


        //WriteProcessMemory(handler, (LPVOID)BULLETS_MEMO_ADDRESS, &in_bullets, sizeof(in_bullets), NULL);
        

    }


}