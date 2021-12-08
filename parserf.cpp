#include "parser.h"

FullShape::FullShape(){}

FullShape::FullShape(std::ifstream &fin)
{
    ParseTextFile(fin);
}

FullShape::~FullShape(){}

int FullShape::GetShapeId()         const
{
    return shapeId;
}

ShapeType FullShape::GetShapeType()         const
{
    return currentShape;
}

std::vector<int> FullShape::GetShapeDimensions() const
{
    return shapeDimensions;
}

std::string FullShape::GetPenColor()        const
{
    return penColor;
}

int FullShape::GetPenWidth()                const
{
    return penWidth;
}

std::string FullShape::GetPenStyle()        const
{
    return penStyle;
}

std::string FullShape::GetPenCapStyle()     const
{
    return penCapStyle;
}

std::string FullShape::GetPenJoinStyle()    const
{
    return penJoinStyle;
}

std::string FullShape::GetBrushColor()      const
{
    return brushColor;
}

std::string FullShape::GetBrushStyle()      const
{
    return brushStyle;
}


std::string FullShape::GetTextString()      const
{
    return textString;
}

std::string FullShape::GetTextColor()       const
{
    return textColor;
}

std::string FullShape::GetTextAlignment()   const
{
    return textAlignment;
}

int FullShape::GetTextPointSize()           const
{
    return textPointSize;
}

std::string FullShape::GetTextFontFamily()  const
{
    return textFontFamily;
}

std::string FullShape::GetTextFontStyle()   const
{
    return textFontStyle;
}

std::string FullShape::GetTextFontWeight()  const
{
    return textFontWeight;
}

void FullShape::ParseTextFile(std::ifstream &fin)
{
    std::string unusedStr;
    //ShapeId
    fin >> shapeId;
    fin.ignore(10000,'\n');
    getline(fin, unusedStr);
    //ShapeType
    SetShapeType();
    char unused;
    if(shapeId == 2 || shapeId == 3) //8
    {
        shapeDimensions.resize(8);
        for(int i = 0; i < 8;i++)
        {
            fin >> shapeDimensions[i];
            if(i != 7) {
                fin.get(unused);
            }
        }
    }
    else if(shapeId == 5 || shapeId == 7) //3
    {
        shapeDimensions.resize(3);
        for(int i = 0; i < 3;i++)
        {
            fin >> shapeDimensions[i];
            if(i != 2) {
                fin.get(unused);
            }
        }
    }
    else //4
    {
        shapeDimensions.resize(4);
        for(int i = 0; i < 4;i++)
        {
            fin >> shapeDimensions[i];
            if(i != 3) {
                fin.get(unused);
            }
        }
    }
    fin.ignore(10000,'\n');

    if(shapeId == 8) //if Text
    {
        getline(fin, textString);
        getline(fin, textColor);
        getline(fin, textAlignment);
        fin >> textPointSize;
        fin.ignore(10000,'\n');
        getline(fin, textFontFamily);
        getline(fin, textFontStyle);
        getline(fin, textFontWeight);
    }
    else //if Shape
    {
        getline(fin, penColor);
        fin >> penWidth;
        fin.ignore(10000,'\n');
        getline(fin, penStyle);
        getline(fin, penCapStyle);
        getline(fin, penJoinStyle);

        if(shapeId != 1 && shapeId != 2)
        {
            getline(fin, brushColor);
            getline(fin, brushStyle);
        }

    }
    fin.ignore(10000,'\n');
}

void FullShape::SetShapeType()
{
    if(shapeId == 1)
    {
        currentShape = Line;
    }
    else if(shapeId == 2)
    {
        currentShape = Polyline;
    }
    else if(shapeId == 3)
    {
        currentShape = Polygon;
    }
    else if(shapeId == 4)
    {
        currentShape = Rectangle;
    }
    else if(shapeId == 5)
    {
        currentShape = Square;
    }
    else if(shapeId == 6)
    {
        currentShape = Ellipse;
    }
    else if(shapeId == 7)
    {
        currentShape = Circle;
    }
    else
    {
        currentShape = Text;
    }
}

std::string FullShape::GetShapeType()
{
    std::string shapeString;
    if(shapeId == 1)
    {
        shapeString = "Line";
    }
    else if(shapeId == 2)
    {
        shapeString = "Polyline";
    }
    else if(shapeId == 3)
    {
        shapeString = "Polygon";
    }
    else if(shapeId == 4)
    {
        shapeString = "Rectangle";
    }
    else if(shapeId == 5)
    {
        shapeString = "Square";
    }
    else if(shapeId == 6)
    {
        shapeString = "Ellipse";
    }
    else if(shapeId == 7)
    {
        shapeString = "Circle";
    }
    else
    {
        shapeString = "Text";
    }
    return shapeString;
}

std::string FullShape::GetShapeDimensions()
{
    std::ostringstream fout;
    if(shapeId == 2 || shapeId == 3) //8
    {
        for(int i = 0; i < 8;i++)
        {
            fout << shapeDimensions[i] << " ";
        }
    }
    else if(shapeId == 5 || shapeId == 7) //3
    {
        for(int i = 0; i < 3;i++)
        {
            fout << shapeDimensions[i] << " ";
        }
    }
    else //4
    {
        for(int i = 0; i < 4;i++)
        {
            fout << shapeDimensions[i] << " ";
        }
    }

    return fout.str();
}

void FullShape::PrintShape() //This is a public function
{
    std::cout << "ShapeId: "         << shapeId              << std::endl
              << "ShapeType: "       << GetShapeType()       << std::endl
              << "ShapeDimensions: " << GetShapeDimensions() << std::endl;
    if(shapeId == 8)
    {
        std::cout << "TextString: "     << textString      << std::endl
                  << "TextColor: "      << textColor       << std::endl
                  << "TextAlignment: "  << textAlignment   << std::endl
                  << "TextPointSize: "  << textPointSize   << std::endl
                  << "TextFontFamily: " << textFontFamily  << std::endl
                  << "TextFontStyle: "  << textFontStyle   << std::endl
                  << "TextFontWeight: " << textFontWeight  << std::endl;


    }
    else
    {
        std::cout << "PenColor: "     << penColor     << std::endl
                  << "PenWidth: "     << penWidth     << std::endl
                  << "PenStyle: "     << penStyle     << std::endl
                  << "PenCapStyle: "  << penCapStyle  << std::endl
                  << "PenJoinStyle: " << penJoinStyle << std::endl;
        if(shapeId != 1 && shapeId != 2)
        {

            std::cout << "BrushColor: "   << brushColor   << std::endl
                      << "BrushStyle: "   << brushStyle   << std::endl;
        }
    }
    std::cout << std::endl;


}

void FullShape::paintEvent(QPaintEvent *) {
    if(shapeId == 8) {
        QLabel *text = buildQLabel();
        text->show();
    } else {
        QPainter *painter = buildShape();

        // render line
        if(shapeId == 1) {
            QLine line;
            line.setLine(shapeDimensions[0], shapeDimensions[1], shapeDimensions[2], shapeDimensions[3]);
            painter->drawLine(line);
        // render polyline
        } else if(shapeId == 2) {
            QLine line1;
            line1.setLine(shapeDimensions[0], shapeDimensions[1], shapeDimensions[2], shapeDimensions[3]);
            QLine line2;
            line2.setLine(shapeDimensions[2], shapeDimensions[3], shapeDimensions[4], shapeDimensions[5]);
            QLine line3;
            line3.setLine(shapeDimensions[4], shapeDimensions[5], shapeDimensions[6], shapeDimensions[7]);

            painter->drawLine(line1);
            painter->drawLine(line2);
            painter->drawLine(line3);
        // render polygon
        } else if(shapeId == 3) {
            QVector<QPoint> points;
            points.resize(4);

            for(int i = 0; i < 4; i++) {
                points[i] = QPoint(shapeDimensions[2*i], shapeDimensions[2*i+1]);
            }

            QPolygon polygon(points);
            painter->drawConvexPolygon(polygon);
        // render rectangle
        } else if(shapeId == 4) {
            QRect rect(shapeDimensions[0], shapeDimensions[1], shapeDimensions[3], shapeDimensions[2]);
            painter->drawRect(rect);
        // render square
        } else if(shapeId == 5) {
            QRect square(shapeDimensions[0], shapeDimensions[1], shapeDimensions[2], shapeDimensions[2]);
            painter->drawRect(square);
        // render ellipse
        } else if(shapeId == 6) {
            // note: multiply semi-major and semi-minor axises by 2 because they are semi-axises, meaning half of the full length
            QRect ellipseBounds(shapeDimensions[0], shapeDimensions[1], 2*shapeDimensions[3], 2*shapeDimensions[2]);
            painter->drawEllipse(ellipseBounds);
        // render circle
        } else if(shapeId == 7) {
            QRect circleBounds(shapeDimensions[0], shapeDimensions[1], 2*shapeDimensions[2], 2*shapeDimensions[2]);
            painter->drawEllipse(circleBounds);
        }

        painter->end();
        delete painter;
    }

}

QLabel* FullShape::buildQLabel() {
    QLabel *text = new QLabel(this); // define new qlabel

    text->setGeometry(shapeDimensions[0], shapeDimensions[1], shapeDimensions[2], shapeDimensions[3]); // use the shapeDimensions vector to set the shape geometry

    text->setText(QString::fromStdString(textString)); // set the text string of the QLabel

    text->setStyleSheet("QLabel { background-color : transparent; color : "+QString::fromStdString(textColor)+"; }"); // use a qlabel palette to set the color of the text

    QString vertStr = (QString::fromStdString(textAlignment) != "AlignCenter") ? (QString::fromStdString(textAlignment)).split(' ')[0] : "AlignCenter"; // get vertical alignment string
    QString horizStr = (vertStr != "AlignCenter") ? (QString::fromStdString(textAlignment)).split(' ')[1] : ""; // get horizontal alignment string
    Qt::Alignment vert;
    Qt::Alignment horiz;

    // convert strings to Qt::Alignment types through if-else statements(no faster way to do it)
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

    // convert style string to QFont::Style type through if-else statements(no faster way to do it)
    QFont::Style style = QFont::StyleNormal;

    if(textFontStyle == "StyleNormal") {
        style = QFont::StyleNormal;
    } else if(textFontStyle == "StyleItalic") {
        style = QFont::StyleItalic;
    } else if(textFontStyle == "StyleOblique") {
        style = QFont::StyleOblique;
    }


    // convert text font weight string to integer(based on qt docs reference I found which gives a table converting strings like "Light" to numbers like 25)
    int weight = 50;

    if(textFontWeight == "Thin") {
        weight = 0;
    } else if(textFontWeight == "ExtraLight") {
        weight = 12;
    } else if(textFontWeight == "Light") {
        weight = 25;
    } else if(textFontWeight == "Normal") {
        weight = 50;
    } else if(textFontWeight == "Medium") {
        weight = 57;
    } else if(textFontWeight == "DemiBold") {
        weight = 63;
    } else if(textFontWeight == "Bold") {
        weight = 75;
    } else if(textFontWeight == "ExtraBold") {
        weight = 81;
    } else if(textFontWeight == "Black") {
        weight = 87;
    }

    // set the full font
    QFont font(QString::fromStdString(textFontFamily), weight);
    font.setStyle(style);
    font.setWeight(weight);
    text->setFont(font);

    return text;
}

QPainter* FullShape::buildShape() {
    QPainter *painter = new QPainter(this);
    QBrush brush;
    QPen pen;

    // set pen color
    QColor color = Qt::white;
    if(penColor == "white") {
        color = Qt::white;
    } else if(penColor == "black") {
        color = Qt::black;
    } else if(penColor == "cyan") {
        color = Qt::cyan;
    } else if(penColor == "red") {
        color = Qt::red;
    } else if(penColor == "magenta") {
        color = Qt::magenta;
    } else if(penColor == "green") {
        color = Qt::green;
    } else if(penColor == "yellow") {
        color = Qt::yellow;
    } else if(penColor == "blue") {
        color = Qt::blue;
    } else if(penColor == "gray") {
        color = Qt::gray;
    }
    pen.setColor(color);

    // set pen width
    pen.setWidth(penWidth);

    // set pen style
    Qt::PenStyle style = Qt::SolidLine;
    if(penStyle == "SolidLine") {
        style = Qt::SolidLine;
    } else if(penStyle == "DashLine") {
        style = Qt::DashLine;
    } else if(penStyle == "DotLine") {
        style = Qt::DotLine;
    } else if(penStyle == "DashDotLine") {
        style = Qt::DashDotLine;
    } else if(penStyle == "DashDotDotLine") {
        style = Qt::DashDotDotLine;
    }
    pen.setStyle(style);

    // set pen cap style
    Qt::PenCapStyle capStyle = Qt::SquareCap;
    if(penCapStyle == "SquareCap") {
        capStyle = Qt::SquareCap;
    } else if(penCapStyle == "FlatCap") {
        capStyle = Qt::FlatCap;
    } else if(penCapStyle == "RoundCap") {
        capStyle = Qt::RoundCap;
    }
    pen.setCapStyle(capStyle);

    // set pen join style
    Qt::PenJoinStyle joinStyle = Qt::MiterJoin;
    if(penJoinStyle == "BevelJoin") {
        joinStyle = Qt::BevelJoin;
    } else if(penJoinStyle == "MiterJoin") {
        joinStyle = Qt::MiterJoin;
    } else if(penJoinStyle == "RoundJoin") {
        joinStyle = Qt::RoundJoin;
    }
    pen.setJoinStyle(joinStyle);

    // set brush color
    if(brushColor == "white") {
        color = Qt::white;
    } else if(brushColor == "black") {
        color = Qt::black;
    } else if(brushColor == "cyan") {
        color = Qt::cyan;
    } else if(brushColor == "red") {
        color = Qt::red;
    } else if(penColor == "magenta") {
        color = Qt::magenta;
    } else if(penColor == "green") {
        color = Qt::green;
    } else if(brushColor == "yellow") {
        color = Qt::yellow;
    } else if(brushColor == "blue") {
        color = Qt::blue;
    } else if(brushColor == "gray") {
        color = Qt::gray;
    }
    brush.setColor(color);

    // set brush style
    Qt::BrushStyle QbrushStyle = Qt::SolidPattern;
    if(brushStyle == "SolidPattern") {
        QbrushStyle = Qt::SolidPattern;
    } else if(brushStyle == "Dense1Pattern") {
        QbrushStyle = Qt::Dense1Pattern;
    } else if(brushStyle == "Dense2Pattern") {
        QbrushStyle = Qt::Dense2Pattern;
    } else if(brushStyle == "Dense3Pattern") {
        QbrushStyle = Qt::Dense3Pattern;
    } else if(brushStyle == "Dense4Pattern") {
        QbrushStyle = Qt::Dense4Pattern;
    } else if(brushStyle == "Dense5Pattern") {
        QbrushStyle = Qt::Dense5Pattern;
    } else if(brushStyle == "Dense6Pattern") {
        QbrushStyle = Qt::Dense6Pattern;
    } else if(brushStyle == "Dense7Pattern") {
        QbrushStyle = Qt::Dense7Pattern;
    } else if(brushStyle == "NoBrush") {
        QbrushStyle = Qt::NoBrush;
    } else if(brushStyle == "HorPattern") {
        QbrushStyle = Qt::HorPattern;
    } else if(brushStyle == "VerPattern") {
        QbrushStyle = Qt::VerPattern;
    } else if(brushStyle == "CrossPattern") {
        QbrushStyle = Qt::CrossPattern;
    } else if(brushStyle == "BDiagPattern") {
        QbrushStyle = Qt::BDiagPattern;
    } else if(brushStyle == "FDiagPattern") {
        QbrushStyle = Qt::FDiagPattern;
    } else if(brushStyle == "DiagCrossPattern") {
        QbrushStyle = Qt::DiagCrossPattern;
    } else if(brushStyle == "LinearGradientPattern") {
        QbrushStyle = Qt::LinearGradientPattern;
    } else if(brushStyle == "RadialGradientPattern") {
        QbrushStyle = Qt::RadialGradientPattern;
    } else if(brushStyle == "ConicalGradientPattern") {
        QbrushStyle = Qt::ConicalGradientPattern;
    }
    brush.setStyle(QbrushStyle);


    // attach the brush to the painter
    pen.setBrush(brush);

    // attach the pen to the painter
    painter->setPen(pen);


    return painter;
}
