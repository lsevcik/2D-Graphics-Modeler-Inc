#ifndef MODELER_CPP
#define MODELER_CPP

#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QFile>
#include <QLabel>

//Default constructor for Widget.
Widget::Widget(QWidget *obj)
    : QWidget(obj)
{

}

//Run when the user decides to load a file.
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
    while(!in.atEnd()) //repeats until it reaches the end of shapes.
    {
        QLabel *text;

        in.readLine();//reads the shape ID (NO IMPLEMENTATION AS OF YET).

        //Seperates the text before the colon from the actual data after it.
        QString currentLine = in.readLine(); //takes in the entire line as a qstring.
        QPolygon polygon; //(NO APPARENT USE, SHOULD BE EXPLAINED OR REMOVED).
        QString type = (currentLine.split(' '))[1]; //

        //Determines what kind of shape will be created
        if(type == "Text") //If the shapes file is making text.
        {
            text = buildText(in); //Calls the private buildText function, passing the contents of shapes.
            text->show(); //makes the text object created visible.
        }
        else if(type == "Line") //If the shapes file is making a line.
        {

        }
        else if(type == "Polyline") //If the shapes file is making a polyline.
        {

        }
        else if(type == "Polygon") //If the shapes file is making a polygon.
        {

        }
        else if(type == "Rectangle") //If the shapes file is making a rectangle.
        {

        }
        else if(type == "Square") //If the shapes file is making a square.
        {

        }
        else if(type == "Ellipse") //If the shapes file is making a ellipse.
        {

        }
        else if(type == "Circle") //If the shapes file is making a circle.
        {

        }
        else
        {
            for(int skip = 0; skip < 8; skip++)
                in.readLine();
        }
    }
    //Closes shapes
    file.close();
};

//Function used to build text objects. Passed the contents of the shapes file.
QLabel* Widget::buildText(QTextStream &in)
{
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

    //Handles the alignment of the text. "TextAlignment".
    currentLine = in.readLine(); //reads the next line.
    QString vertStr = currentLine.split(' ')[1]; //Seperates the data from everything before the space
    QString horizStr = (vertStr != "AlignCenter") ? currentLine.split(' ')[2] : ""; //Either centers the text or also seperates the horizontal alignment.
    Qt::Alignment vert;
    Qt::Alignment horiz;

    //Finds the actual allignment based on the text in shapes.
    if(vertStr != "AlignCenter") //If the alignment is not AlignCenter, checks for other possible allignments.
    {
        if(vertStr == "AlignTop") //Handles vertical allignment.
        {
            vert = Qt::AlignTop;
        }
        else if(vertStr == "AlignBottom")
        {
            vert = Qt::AlignBottom;
        }
        else if(vertStr == "AlignVCenter")
        {
            vert = Qt::AlignVCenter;
        }
        else if(vertStr == "AlignBottom")
        {
            vert = Qt::AlignBottom;
        }
        else
        {
            std::cout << "Unrecognized Vertical Allignment";
            vert = Qt::AlignVCenter;
        }

        if(horizStr == "AlignLeft") //Handles horizontal allignment.
        {
            horiz = Qt::AlignLeft;
        }
        else if(horizStr == "AlignRight")
        {
            horiz = Qt::AlignRight;
        }
        else if(horizStr == "AlignHCenter")
        {
            horiz = Qt::AlignHCenter;
        }
        else if(horizStr == "AlignJustify")
        {
            horiz = Qt::AlignJustify;
        }
        else
        {
            std::cout << "Unrecognized Horizontal Allignment";
            horiz = Qt::AlignHCenter;
        }

        text->setAlignment(vert | horiz);
    }
    else
    {
        text->setAlignment(Qt::AlignCenter);
    }

    //Handles the size of the text. "TextPointSize".
    int size = (((in.readLine()).split(':'))[1].remove(0, 1)).toInt();

    //Handles the font of the text. "TextFontFamily".
    QString fontFamily = (((in.readLine()).split(':'))[1]).remove(0, 1);

    currentLine = (in.readLine()).split(' ')[1];

    //Handles the style of the text (oblique, italics, or normal). "TextFontStyle".
    QFont::Style style = QFont::StyleNormal;

    if(currentLine == "StyleNormal")
    {
        style = QFont::StyleNormal;
    }
    else if(currentLine == "StyleItalic")
    {
        style = QFont::StyleItalic;
    }
    else if(currentLine == "StyleOblique")
    {
        style = QFont::StyleOblique;
    }

    //Handles the thickness of the letters. "TextFontWeight".
    currentLine = (in.readLine()).split(' ')[1];
    int weight = 50;

    if(currentLine == "Thin")
    {
        weight = 0;
    }
    else if(currentLine == "ExtraLight")
    {
        weight = 12;
    }
    else if(currentLine == "Light")
    {
        weight = 25;
    }
    else if(currentLine == "Normal")
    {
        weight = 50;
    }
    else if(currentLine == "Medium")
    {
        weight = 57;
    }
    else if(currentLine == "DemiBold")
    {
        weight = 63;
    }
    else if(currentLine == "Bold")
    {
        weight = 75;
    }
    else if(currentLine == "ExtraBold")
    {
        weight = 81;
    }
    else if(currentLine == "Black")
    {
        weight = 87;
    }

    //Creates a QFont object with the appropriate font, size, style, and weight using what was already read.
    QFont font(fontFamily, size); //Creates the actual object (initializes with family and size).
    font.setStyle(style); //Sets the correct style for the font.
    font.setWeight(weight); //Sets the correct weight for the font.
    text->setFont(font); //Ensures that the new text object uses the new QFont.

    return text;
}

//New Function used to build shape objects. Passed the contents of the shapes file.
QLabel* Widget::buildShape(QTextStream &in)
{
    QLabel *shape = new QLabel(this);

    shape->setGeometry(20, 90, 100, 20);


    return shape;
}

//Sets the pen styles and such

#endif
