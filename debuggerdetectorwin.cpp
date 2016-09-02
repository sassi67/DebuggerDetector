#include "debuggerdetectorwin.h"
#include <Windows.h>
#include <stdio.h>

/**
 * @brief DebuggerDetectorWin::DebuggerDetectorWin
 * @param parent
 */
DebuggerDetectorWin::DebuggerDetectorWin(QObject *parent):
    DebuggerDetectorInterface(parent)
{

}
/**
 * @brief DebuggerDetectorWin::run
 */
void DebuggerDetectorWin::run()
{
    while(!stopped_) {
        // user-mode debuggers
        if (IsDebuggerPresent()) {
            stopped_ = true;
            emit debuggerDetected();
            break;
        }
        // kernel-mode debuggers
        {
            typedef long NTSTATUS;
            HANDLE hProcess = GetCurrentProcess();

            typedef struct _SYSTEM_KERNEL_DEBUGGER_INFORMATION {
                BOOLEAN DebuggerEnabled;
                BOOLEAN DebuggerNotPresent;
            } SYSTEM_KERNEL_DEBUGGER_INFORMATION, *PSYSTEM_KERNEL_DEBUGGER_INFORMATION;

            enum SYSTEM_INFORMATION_CLASS { SystemKernelDebuggerInformation = 35 };
            typedef NTSTATUS  (__stdcall *ZW_QUERY_SYSTEM_INFORMATION)(IN SYSTEM_INFORMATION_CLASS SystemInformationClass, IN OUT PVOID SystemInformation, IN ULONG SystemInformationLength, OUT PULONG ReturnLength);
            ZW_QUERY_SYSTEM_INFORMATION ZwQuerySystemInformation;
            SYSTEM_KERNEL_DEBUGGER_INFORMATION Info;
            // load the ntdll.dll
            HMODULE hModule = LoadLibrary(L"ntdll.dll");
            ZwQuerySystemInformation = (ZW_QUERY_SYSTEM_INFORMATION)GetProcAddress(hModule, "ZwQuerySystemInformation");
            if (NULL == ZwQuerySystemInformation) {
                CloseHandle(hProcess);
                continue;
            }

            // #define STATUS_SUCCESS    ((NTSTATUS)0L)
            if (0L == ZwQuerySystemInformation(SystemKernelDebuggerInformation, &Info, sizeof(Info), NULL)) {
                if (Info.DebuggerEnabled && !Info.DebuggerNotPresent) {
                    // System debugger is present
                    CloseHandle(hProcess);
                    stopped_ = true;
                    emit debuggerDetected();
                    break;
                }
            }
        }
        msleep(1000);
    }

    emit(finished());
}