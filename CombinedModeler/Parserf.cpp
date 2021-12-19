#include "Parser.h"

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

    //ShapeId
    fin >> shapeId;
    fin.ignore(10000,'\n');

    //ShapeType
    SetShapeType();
    if(shapeId == 2 || shapeId == 3) //8
    {
        shapeDimensions.resize(8);
        for(int i = 0; i < 8;i++)
        {
            fin >> shapeDimensions[i];
        }
    }
    else if(shapeId == 5 || shapeId == 7) //3
    {
        shapeDimensions.resize(3);
        for(int i = 0; i < 3;i++)
        {
            fin >> shapeDimensions[i];
        }
    }
    else //4
    {
        shapeDimensions.resize(4);
        for(int i = 0; i < 4;i++)
        {
            fin >> shapeDimensions[i];
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
