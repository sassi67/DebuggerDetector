#ifndef DEBUGGERDETECTORWIN_H
#define DEBUGGERDETECTORWIN_H
#include "debuggerdetectorinterface.h"

class DebuggerDetectorWin : public DebuggerDetectorInterface
{
    Q_OBJECT
public:
    explicit DebuggerDetectorWin(QObject *parent = 0);
private:
    virtual void run();
};

#endif // DEBUGGERDETECTORWIN_H
