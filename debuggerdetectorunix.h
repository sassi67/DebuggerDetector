#ifndef DEBUGGERDETECTORUNIX_H
#define DEBUGGERDETECTORUNIX_H

#include "debuggerdetectorinterface.h"

class DebuggerDetectorUnix : public DebuggerDetectorInterface
{
    Q_OBJECT
public:
    explicit DebuggerDetectorUnix(QObject *parent = 0);
private:
    virtual void run();
};

#endif // DEBUGGERDETECTORUNIX_H
