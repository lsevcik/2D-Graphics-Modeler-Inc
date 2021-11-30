#include "TextHeader.h"

void TextEditor::AssignTextString(string text)
{
    textString = text;
}

void TextEditor::TextDimmensions(int boxHeight, int boxWidth)
{
    height = boxHeight;
    width = boxWidth;
}

void TextEditor::TextColor(string color)
{
    textColor = color;
}

void TextEditor::TextAllignment(string allignment)
{
    textAllignment = allignment;
}

void TextEditor::TextPointSize(int size)
{
    textPointSize = size;
}

void TextEditor::TextFont(string family, string style, string weight)
{
    textFontFamily = family;
    textFontStyle = style;
    textFontWeight = weight;
}
