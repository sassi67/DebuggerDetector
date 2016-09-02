#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

#ifdef Q_OS_WIN
#include "debuggerdetectorwin.h"
#else

#endif
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
#ifdef Q_OS_WIN
    dbgDetector_(new DebuggerDetectorWin(this))
#else

#endif

{
    connect(dbgDetector_, SIGNAL(finished()),
            dbgDetector_, SLOT(deleteLater()));

    connect(dbgDetector_, SIGNAL(debuggerDetected()),
            this, SLOT(displayMessage()));

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    dbgDetector_->stop();
    dbgDetector_->wait();
    delete ui;
}

void MainWindow::displayMessage()
{
    QMessageBox::critical(this, "Attention!", "Debugger detected.");
    close();
}

void MainWindow::closeEvent(QEvent *)
{
    dbgDetector_->stop();
    dbgDetector_->wait();
}
