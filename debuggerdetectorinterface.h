#ifndef DEBUGGERDETECTORINTERFACE_H
#define DEBUGGERDETECTORINTERFACE_H

#include <QObject>
#include <QThread>
#include <QHash>

class DebuggerDetectorInterface : public QThread
{
    Q_OBJECT
public:
    explicit DebuggerDetectorInterface(QObject *parent = 0);
    void stop();

protected:
    volatile bool stopped_;

private:
    virtual void run();

signals:
    void debuggerDetected();

public slots:
};

#endif // DEBUGGERDETECTORINTERFACE_H
