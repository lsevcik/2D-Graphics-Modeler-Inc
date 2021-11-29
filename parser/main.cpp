#include"Parser.h"

int main()
{
    FullShape Test[4];
    int index = 0;
    std::ifstream fin;
    fin.open("data.txt");

    while(fin && index < 4)
    {

        Test[index].ParseTextFile(fin);
        Test[index].PrintShape();
        index++;
    }

    fin.close();
    return 0;
}
