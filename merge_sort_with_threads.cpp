#include <iostream>
#include <vector>
#include <math.h>
#include <utility>
#include <time.h>
#include <typeinfo>

#include <thread>

// DON'T FORGET TO ADD -pthread DURING COMPILATION


void merge(int left, std::vector<int> &array ,int right) 
{
    
    if (right == left)
        return; // one element is always sorted
    if (right - left == 1) 
    { 
        if (array[right] < array[left])
            std::swap(array[right], array[left]); // sort two elements

        return;
    }

    int middle = (right + left) / 2;

    merge(left, array, middle); // tupo rekurentno 
    merge(middle + 1, array, right);

    // merging:

    std::vector<int> buffer;

    int firstPart = left;
    int secondPart = middle + 1;
    int current = 0;

    while ((right - left + 1) != current) 
    {
        if (firstPart > middle)
        {    
            buffer.push_back(array[secondPart]);
            current++;
            secondPart++;
        }

        else if (secondPart > right)
        {   
            buffer.push_back(array[firstPart]);
            current++;
            firstPart++;

        }

        else if (array[firstPart] > array[secondPart])
        {
            buffer.push_back(array[secondPart]);
            current++;
            secondPart++;
        }

        else 
        {    
            buffer.push_back(array[firstPart]);
            current++;
            firstPart++;
        }

    }
    
    for (int i = 0; i < current; i++)
    {   
        array[i + left] = buffer[i];
    }
}

void lastMerge(std::vector<int> &array)
{
    int left = 0;
    int right = array.size();
    int middle = (right + left) / 2;

    std::vector<int> buffer;

    int firstPart = left;
    int secondPart = middle + 1;
    int current = 0;

    while ((right - left + 1) != current) 
    {
        if (firstPart > middle)
        {    
            buffer.push_back(array[secondPart]);
            current++;
            secondPart++;
        }

        else if (secondPart > right)
        {   
            buffer.push_back(array[firstPart]);
            current++;
            firstPart++;

        }

        else if (array[firstPart] > array[secondPart])
        {
            buffer.push_back(array[secondPart]);
            current++;
            secondPart++;
        }

        else 
        {    
            buffer.push_back(array[firstPart]);
            current++;
            firstPart++;
        }

    }
    
    for (int i = 0; i < current; i++)
    {   
        array[i] = buffer[i];
    }
}

main()
{
    // INITALISATION:
    std::vector<int> vectorToSort;
    int size;

    std::cout << "write array size: " << '\n';
    std::cin >> size;
    
    for(int i = 0; i < size; i++)
        vectorToSort.push_back(rand() % 50);

    // WORK WITH THREADS:
    int middle = vectorToSort.size() / 2;

    std::thread thread1(merge, 0, std::ref(vectorToSort), middle);
    std::thread thread2(merge, middle + 1, std::ref(vectorToSort), size);

    thread1.join();
    thread2.join();

    lastMerge(vectorToSort); // because we have two sorted parts, not whole vector

    for(int i = 0; i < size; i++)
        std::cout << vectorToSort[i] << " ";
    
    std::cout << '\n';

    return 0;

}