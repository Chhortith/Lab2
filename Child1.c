#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    DWORD childPID = GetCurrentProcessId();
    DWORD parentPID = 0;

    // Read parent PID if passed as argument
    if (argc > 1) {
        parentPID = (DWORD)strtoul(argv[1], NULL, 10);
    }


    // Print PIDs
    printf("Current Child Process ID: %lu\n", (unsigned long)childPID);
    if (parentPID != 0) {
        printf("Parent Process ID: %lu\n", (unsigned long)parentPID);
    }

    return 0;
}

