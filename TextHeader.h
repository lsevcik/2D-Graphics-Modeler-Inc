#ifndef TEXTHEADER_H
#define TEXTHEADER_H


// included all libraries for the parser for sake of convienience. pls forgive spelling ;p
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

// again for convinience
using namespace std;

// all functions in TextEditor are to allow editing in ui, to assign from parser just call with relevant information
class TextEditor
{
public:

    void AssignTextString(string text);             // edits string, use for editing in ui

    void TextDimmensions(int height, int width);    // size of the text box, if we are using decimals change type to float

    void TextColor(string color);                   // color of the text

    void TextAllignment(string allignment);         // allignment of text in the box

    void TextPointSize(int size);                   // size of the text

    void TextFont(string family, string style, string weight);      // applies the text font family, style, and weight

private:
    // copies of data from the parser.
    // I was unsure whether to store all text data in text class or if we wanted to just draw for the FullShape class in the parser.
    // for testing data is stored and assigned here, change later as needed

    string textString;      //Where the text string is stored

    string textColor;       // Where text color information is stored

    string textAllignment;  // Where text allignment is stored. Left, right, center.

    int textPointSize;      // Where the text point size is stored

    string textFontFamily;  // holds font family information

    string textFontStyle;   // holds font style information

    string textFontWeight;  // holds font weight information

};


#endif // TEXTHEADER_H
