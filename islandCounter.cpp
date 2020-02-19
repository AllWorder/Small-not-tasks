#include <iostream>
#include <vector>
#include <fstream>

std::vector< std::vector<int> > readTextFromFile()
{
    int string = 0;
    int column = 0;

    std::ifstream file;
    file.open("file.txt");
    file >> string;
    file >> column;

    std::vector< std::vector<int> > text(string, std::vector<int>(column)); //two-dim array

    for(int i = 0; i < string; i++)
    {
        for(int j = 0; j < column; j++)
        {
            file >> text[i][j];
        }
    }

    return text;
}

void printTwoDimArray(std::vector< std::vector<int> > vector)
{
    int string = vector.size();
    int column = vector[0].size();

    for(int i = 0; i < string; i++)
    {
        for(int j = 0; j < column; j++)
        {
            std::cout << vector[i][j] << ' ';
        }

        std::cout << '\n';
    }
}

void markOneIsland(std::vector< std::vector<int> >& vector, int string, int column, int i, int j)
{
    vector[i][j] = 0;

    if((i - 1 >= 0) and (vector[i-1][j] == 1))
        markOneIsland(vector, string, column, i, i - 1);

    if((j + 1 < column) and (vector[i][j+1] == 1))
        markOneIsland(vector, string, column, i, j + 1);

    if((i + 1 < string) and (vector[i+1][j] == 1))
        markOneIsland(vector, string, column, i + 1, j );

    if((j - 1 >= 0) and (vector[i][j-1] == 1))
        markOneIsland(vector, string, column, i, j - 1);

}

int getIslandsNumber(std::vector< std::vector<int> > vector)
{
    int num = 0;
    int string = vector.size();
    int column = vector[0].size();

    for(int i = 0; i < string; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(vector[i][j] == 1)
            {
                num += 1;
                markOneIsland(vector, string, column, i, j);
            }
        }
    }

    return num;
}



main()
{
    std::vector< std::vector<int> > text = readTextFromFile();
    printTwoDimArray(text); // just to check it's work

    int islandsNum = getIslandsNumber(text);

    std::cout << "Number of islands: " << islandsNum << '\n';

}