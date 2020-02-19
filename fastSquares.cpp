#include <iostream>
#include <vector>


std::vector<int> returnSortedSquares(std::vector<int>& inVector)
{
    int firstPositive = inVector.size() - 1; // if all are negative
    for(int i = 0; i < inVector.size(); i++)
    {
        if( inVector[i] >= 0)
        {
            firstPositive = i;
            break;
        }        
    }


    std::vector<int> result = {0}; // Nikita, pochemu obyazatel'no nado odin element pomestit', chtobi ne segFault?

    int currentResPos = 0;
    int i = firstPositive;
    int j = inVector.size();
    if(firstPositive < inVector.size() - 1 )
        j = firstPositive + 1;
    

    while((i >= 0) and (j < (inVector.size())))
    {
        if( inVector[i]*inVector[i] <= inVector[j]*inVector[j] )
        {
            result[currentResPos] = inVector[i] * inVector[i];
            i = i - 1;
            currentResPos += 1;

        }
        else
        {
            result[currentResPos] = inVector[j] * inVector[j];
            j = j + 1;
            currentResPos += 1;
        }     
    }

    while( i >= 0)
    {
        result[currentResPos] = inVector[i]*inVector[i];
        i = i - 1;
        currentResPos += 1;
    }

    while( j < (inVector.size()))
    {
        result[currentResPos] = inVector[j]*inVector[j];
        j = j + 1;
        currentResPos += 1;
    }

    return result;
}


main()
{
    std::vector<int> testVector;
    testVector.push_back(-10);
    testVector.push_back(-9);
    testVector.push_back(-8);
    testVector.push_back(-6);
    testVector.push_back(0);
    testVector.push_back(1);
    testVector.push_back(5);
    testVector.push_back(7);
    testVector.push_back(15);

    std::vector<int> result = returnSortedSquares(testVector);

    for(int i = 0; i < testVector.size(); i++)
    {
        std::cout << result[i] << ' ';
    }

    std::cout << '\n';

}