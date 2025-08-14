#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD parentPID = GetCurrentProcessId();
    
    // Print student bio
    printf("Student bio:\n");
    printf("ID   : 674244130\n");
    printf("Name : Chhortith Khay\n");
    printf("------------------------------\n");

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Command line: Child1.exe <parentPID>
    char cmdLine[256];
    sprintf(cmdLine, "C:\\Dev-C++\\Lap2\\Child1.exe %lu", (unsigned long)parentPID);

    // Create child process
    if (!CreateProcess(
        NULL,      // Application name
        cmdLine,   // Command line
        NULL,      // Process handle not inheritable
        NULL,      // Thread handle not inheritable
        FALSE,     // Handle inheritance
        0,         // Creation flags
        NULL,      // Use parent's environment
        NULL,      // Use parent's starting directory
        &si,
        &pi
    )) {
        printf("CreateProcess failed (%lu).\n", GetLastError());
        return 1;
    }

    printf("Parent PID: %lu\n", (unsigned long)parentPID);
    printf("Child PID:  %lu\n", (unsigned long)pi.dwProcessId);

    // Wait for child process to finish
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}

