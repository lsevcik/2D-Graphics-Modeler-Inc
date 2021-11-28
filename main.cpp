#include "mainwindow.h"
#include <QApplication>
#include <QtGui>

#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QFile>
#include <QLabel>


class Widget : public QWidget
{
public:
    Widget(QWidget *obj = 0)
        : QWidget(obj)
    {
    }
    void paintEvent(QPaintEvent *)
    {
        QPainter painter(this);

        QFile file("/Users/dgeyfman/DrawPrimitivesTest/shapes.txt");
        QTextStream in(&file);


        if(!file.open(QFile::ReadOnly |
                      QFile::Text))
        {
            qDebug() << "Could not open the file for reading";
            return;
        }

        while(!in.atEnd()) {
            // this is where you would do something with the id but I haven't implemented that yet
            in.readLine();


            QString currentLine = in.readLine();
            QPolygon polygon;
            QString type = (currentLine.split(' '))[1];

            if(type == "Text") {
                QLabel *text = buildText(in);
                text->show();
            }

        }

        file.close();
    }

private:
    QLabel* buildText(QTextStream &in) {
        QLabel *text = new QLabel(this);

        QString currentLine = in.readLine();

        QString xPos = currentLine.split(' ')[1];
        xPos.chop(1);

        QString yPos = currentLine.split(' ')[2];
        yPos.chop(1);

        QString l = currentLine.split(' ')[3];
        l.chop(1);

        QString w = currentLine.split(' ')[4];

        text->setGeometry(xPos.toInt(), yPos.toInt(), l.toInt(), w.toInt());



        text->setText(((in.readLine()).split(':'))[1].remove(0, 1));

        text->setStyleSheet("QLabel { background-color : transparent; color : "+((in.readLine()).split(':'))[1].remove(0, 1)+"; }");



        currentLine = in.readLine();
        QString vertStr = currentLine.split(' ')[1];
        QString horizStr = (vertStr != "AlignCenter") ? currentLine.split(' ')[3] : "";
        Qt::Alignment vert;
        Qt::Alignment horiz;

        if(vertStr != "AlignCenter") {
            if(vertStr == "AlignTop") {
                vert = Qt::AlignTop;
            } else if(vertStr == "AlignBottom") {
                vert = Qt::AlignBottom;
            } else if(vertStr == "AlignVCenter") {
                vert = Qt::AlignVCenter;
            } else if(vertStr == "AlignBottom") {
                vert = Qt::AlignBottom;
            }

            if(horizStr == "AlignLeft") {
                horiz = Qt::AlignLeft;
            } else if(horizStr == "AlignRight") {
                horiz = Qt::AlignRight;
            } else if(horizStr == "AlignHCenter") {
                horiz = Qt::AlignHCenter;
            } else if(horizStr == "AlignJustify") {
                horiz = Qt::AlignJustify;
            }

            text->setAlignment(vert | horiz);
        } else {
            text->setAlignment(Qt::AlignCenter);
        }


        int size = (((in.readLine()).split(':'))[1].remove(0, 1)).toInt();
        QString fontFamily = (((in.readLine()).split(':'))[1]).remove(0, 1);


        currentLine = (in.readLine()).split(' ')[1];

        QFont::Style style = QFont::StyleNormal;

        if(currentLine == "StyleNormal") {
            style = QFont::StyleNormal;
        } else if(currentLine == "StyleItalic") {
            style = QFont::StyleItalic;
        } else if(currentLine == "StyleOblique") {
            style = QFont::StyleOblique;
        }


        currentLine = (in.readLine()).split(' ')[1];
        int weight = 50;

        if(currentLine == "Thin") {
            weight = 0;
        } else if(currentLine == "ExtraLight") {
            weight = 12;
        } else if(currentLine == "Light") {
            weight = 25;
        } else if(currentLine == "Normal") {
            weight = 50;
        } else if(currentLine == "Medium") {
            weight = 57;
        } else if(currentLine == "DemiBold") {
            weight = 63;
        } else if(currentLine == "Bold") {
            weight = 75;
        } else if(currentLine == "ExtraBold") {
            weight = 81;
        } else if(currentLine == "Black") {
            weight = 87;
        }


        QFont font(fontFamily, size);
        font.setStyle(style);
        font.setWeight(weight);
        text->setFont(font);

        return text;
    }
};



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget wgt5;


    wgt5.resize(1000, 1000);
    wgt5.show();



    return app.exec();
}
