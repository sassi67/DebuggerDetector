#include "debuggerdetectorinterface.h"
/**
 * @brief DebuggerDetectorInterface::DebuggerDetectorInterface
 * @param parent
 */
DebuggerDetectorInterface::DebuggerDetectorInterface(QObject *parent) :
    QThread(parent),
    stopped_(false)
{
    start();
}

void DebuggerDetectorInterface::stop()
{
    stopped_ = true;
}
/**
 * @brief DebuggerDetectorInterface::run
 */
void DebuggerDetectorInterface::run()
{
    // let the sublasses to implement this method
}
