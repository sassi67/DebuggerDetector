#include "debuggerdetectorunix.h"

#ifdef Q_OS_LINUX
#include <sys/ptrace.h>
#endif
/**
 * @brief DebuggerDetectorUnix::DebuggerDetectorUnix
 * @param parent
 */
DebuggerDetectorUnix::DebuggerDetectorUnix(QObject *parent):
    DebuggerDetectorInterface(parent)
{

}
/**
 * @brief DebuggerDetectorUnix::run
 */
void DebuggerDetectorUnix::run()
{
#ifdef Q_OS_LINUX
    // all debuggers and program tracers use this call to setup debugging for a process
    // run only once!!
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) < 0) {
        emit debuggerDetected();
        stopped_ = false;
    }

    while(!stopped_) {

        msleep(1000);
    }
#endif
    emit(finished());
}
