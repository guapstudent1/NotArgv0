// Программа получает полное имя запускаемого процесса
#include "windows.h"
#include "tchar.h"
#include "stdio.h"
#include "psapi.h"
#include <iostream>
#include <locale>

void main()
{
    //UNREFERENCED_PARAMETER();
    HANDLE Handle = OpenProcess(
        PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
        FALSE,
        GetCurrentProcessId() /* Это PID, который вы можете найти в диспечере задач */
    );
    if (Handle) 
    {
        TCHAR Buffer[MAX_PATH];
        
        if (GetModuleFileNameEx(Handle, 0, Buffer, MAX_PATH))
        {
            // Указать правильную локаль для русских символов
            setlocale(LC_ALL, "Russian");
            SetConsoleOutputCP(866);
            std::cout << Buffer << std::endl;
        }
        else
        {
            // Здесь лучше вызвать GetLastError()
        }
        CloseHandle(Handle);
    }
}