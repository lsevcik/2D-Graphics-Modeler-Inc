#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QStandardItem>
#include <QStandardItemModel>
#include <QMainWindow>
#include <QtDebug>
#include <QMessageBox>
#include "loginDialog.h"

class Widget : public QWidget
{
public:
    Widget(QWidget *obj = 0);
    void paintEvent(QPaintEvent *);
private:
    QLabel* buildText(QTextStream &in);
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loginCallback(bool);

public slots:

private slots:
    void on_actionLogin_triggered();
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();
    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
    loginDialog *m_loginDialog;
    Widget wgt5;
};

class Shape {
public:
    virtual void draw() = 0;
    virtual void move() = 0;
    virtual double perimeter() = 0;
    virtual double area() = 0;

protected:
    QPainter *painter;
};

class Text: public Shape {

};

#endif // MAINWINDOW_H
