#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "debuggerdetectorinterface.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    DebuggerDetectorInterface* dbgDetector_;
private slots:
    void displayMessage();
    void closeEvent(QEvent*);
};

#endif // MAINWINDOW_H
