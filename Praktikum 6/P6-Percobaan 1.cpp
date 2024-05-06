#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

const int MAX = 10;

int main()
{
    std::srand(std::time(0)); // menginisiasi random data
    std::vector<int> data(MAX);
    std::cout << "DATA BEFORE SORTING:\n";
    for(int i = 0; i < MAX; i++)
    {
        data[i] = std::rand() % 1000 + 1;
        std::cout << "Data[" << i << "]: " << data[i] << "\n";
    }
    // sort data using insertion sort
    for(int i = 1; i < MAX; i++)
    {
        int j = i - 1;
        int x = data[i];
        while (j >= 0 && data[j] > x)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = x;
    }

    //melakukan print dari sorted data
    std::cout << "\nDATA AFTER SORTING:\n";
    for(int i = 0; i < MAX; i++)
    {
        std::cout << "Data[" << i << "]: " << data[i] << "\n";
    }

    return 0;
}