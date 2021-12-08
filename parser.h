#ifndef PARSER_H
#define PARSER_H


#include<fstream>
#include<string>
#include<vector>
#include<iostream>
#include<sstream>
#include <QApplication>
#include <QMainWindow>
#include <QtGui>
#include <QApplication>
#include <QtGui>
#include <QFile>
#include <QLabel>

enum ShapeType
{
    Line,
    Polyline,
    Polygon,
    Rectangle,
    Square,
    Ellipse,
    Circle,
    Text
};

class FullShape : public QWidget
{
    public:
             FullShape(QWidget *obj = 0) : QWidget(obj) {}
             FullShape();
             FullShape(std::ifstream &fin);
             FullShape(FullShape&) = delete;
             ~FullShape();
             FullShape operator=(FullShape&) = delete;

             int GetShapeId()                 const;
             ShapeType GetShapeType()         const;
             std::vector<int> GetShapeDimensions() const;

             std::string GetPenColor()        const;
             int GetPenWidth()                const;
             std::string GetPenStyle()        const;
             std::string GetPenCapStyle()     const;
             std::string GetPenJoinStyle()    const;
             std::string GetBrushColor()      const;
             std::string GetBrushStyle()      const;

             std::string GetTextString()      const;
             std::string GetTextColor()       const;
             std::string GetTextAlignment()   const;
             int GetTextPointSize()           const;
             std::string GetTextFontFamily()  const;
             std::string GetTextFontStyle()   const;
             std::string GetTextFontWeight()  const;

             void ParseTextFile(std::ifstream &fin);
             void PrintShape(); //For testing purposes only


             void paintEvent(QPaintEvent *);
             QLabel* buildQLabel();
             QPainter* buildShape();
             void DrawShape();

    private:
             int shapeId;
             ShapeType currentShape;
             std::vector<int> shapeDimensions;

             //For Shapes only
             std::string penColor;
             int penWidth;
             std::string penStyle;
             std::string penCapStyle;
             std::string penJoinStyle;
             std::string brushColor;
             std::string brushStyle;

             //For Text only
             std::string textString;
             std::string textColor;
             std::string textAlignment;
             int textPointSize;
             std::string textFontFamily;
             std::string textFontStyle;
             std::string textFontWeight;

             void SetShapeType();
             std::string GetShapeType();
             std::string GetShapeDimensions();





};

#endif // PARSER_H
