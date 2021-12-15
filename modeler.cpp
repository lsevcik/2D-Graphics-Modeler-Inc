#ifndef MODELER_CPP
#define MODELER_CPP

#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QFile>
#include <QLabel>


Widget::Widget(QWidget *obj)
        : QWidget(obj)
    {
    }
//Run when the user decides to load a file
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //"loads" shapes file from build file.
    QFile file("shapes.txt");
    QTextStream in(&file);

    //Checks that shapes actually opens.
    if(!file.open(QFile::ReadOnly | QFile::Text))
        {
            qDebug() << "Could not open the file for reading";
            return;
        }

        //Parses the information in the shapes file.
        while(!in.atEnd()) { //repeats until it reaches the end of shapes.
            in.readLine();//reads the shape ID (NO IMPLEMENTATION AS OF YET).

            //Seperates the text before the colon from the actual data after it.
            QString currentLine = in.readLine(); //takes in the entire line as a qstring.
            QPolygon polygon; //(NO APPARENT USE, SHOULD BE EXPLAINED OR REMOVED).
            QString type = (currentLine.split(' '))[1]; //

            //Determines what kind of shape will be created
            if(type == "Text") { //If the shapes file is making text.
                QLabel *text = buildText(in); //Calls the private buildText function, passing the contents of shapes.
                text->show(); //makes the text object created visible.
            /*}else if(type == "") { //(FORMAT FOR OTHER SHAPES [REPEAT FOR EACH]).
            *
            */}

        }

        //Closes shapes
        file.close();
    }

//Function used to build text objects. Passed the contents of the shapes file.
QLabel* Widget::buildText(QTextStream &in) {
    QLabel *text = new QLabel(this);

    //Handles the shape dimensions part of the shapes file. "ShapeDimensions".
    QString currentLine = in.readLine();

    QString xPos = currentLine.split(' ')[1]; //Looks for the first space between the ":" and the actual data.
    xPos.chop(1); //Removes the "," at the end of the split string.

    QString yPos = currentLine.split(' ')[2]; //Looks for the second space between the "," and the actual data.
    yPos.chop(1); //Removes the "," at the end of the split string.

    QString l = currentLine.split(' ')[3]; //Looks for the third space between the "," and the actual data.
    l.chop(1); //Removes the "," at the end of the split string.

    QString w = currentLine.split(' ')[4]; //Looks for the fourth space between the "," and the actual data.

    text->setGeometry(xPos.toInt(), yPos.toInt(), l.toInt(), w.toInt()); //Uses the above parsed data to set the shape's geometry

    //Handles the actual text of the object. "TextString".
    text->setText(((in.readLine()).split(':'))[1].remove(0, 1));

    //Handles the color of the text. "TextColor".
    text->setStyleSheet("QLabel { background-color : transparent; color : "+((in.readLine()).split(':'))[1].remove(0, 1)+"; }");

    //Handles the alignment of the text. "TextAllignment".
    currentLine = in.readLine(); //reads the next line.
    QString vertStr = currentLine.split(' ')[1]; //Seperates the data from everything before the space
    QString horizStr = (vertStr != "AlignCenter") ? currentLine.split(' ')[2] : ""; //Either centers the text or also seperates the horizontal alignment.
    Qt::Alignment vert;
    Qt::Alignment horiz;

    //Finds the actual allignment based on the text in shapes.
    if(vertStr != "AlignCenter") { //If the alignment is not AlignCenter, checks for other possible allignments.
        if(vertStr == "AlignTop") { //Handles vertical allignment.
            vert = Qt::AlignTop;
        } else if(vertStr == "AlignBottom") {
            vert = Qt::AlignBottom;
        } else if(vertStr == "AlignVCenter") {
            vert = Qt::AlignVCenter;
        } else if(vertStr == "AlignBottom") {
            vert = Qt::AlignBottom;
        }

        if(horizStr == "AlignLeft") { //Handles horizontal allignment.
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

#endif
