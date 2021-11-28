#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
