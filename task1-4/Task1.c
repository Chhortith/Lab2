#include <windows.h>
#include <stdio.h>

int main() {
    printf("Current Process ID: %lu\n", GetCurrentProcessId());
    printf("Current Thread ID : %lu\n", GetCurrentThreadId());
    return 0;
}
