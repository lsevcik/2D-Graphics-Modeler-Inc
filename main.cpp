#include "parser.h"
#include <QApplication>
#include <QtGui>
#include <QFile>
#include <QLabel>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString curPath = QDir::currentPath();
    curPath.append("/shapes.txt");

    std::ifstream in(curPath.toStdString());
    FullShape shape(in);


    shape.resize(1000, 1000);
    shape.show();

    in.close();

    return app.exec();
}
