#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modeler.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,  m_loginDialog(new loginDialog(this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete m_loginDialog;
    delete ui;
}

void MainWindow::loginCallback(bool succ)
{
    if (succ)
        return;
}

void MainWindow::on_actionLogin_triggered()
{
    m_loginDialog->exec();
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::aboutQt(this, "About");
}

void MainWindow::on_actionOpen_triggered()
{
    wgt5.resize(1000, 1000);
    wgt5.show();
}
