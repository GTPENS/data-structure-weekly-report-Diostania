#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

const int MAX = 10;

void BinaryInsertSort(std::vector<int>& data)
{
    for (int i = 1; i < MAX; i++)
    {
        int x = data[i];
        int l = 0;
        int r = i - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (x < data[m])
                r = m - 1;
            else
                l = m + 1;
        }

        for (int j = i - 1; j >= l; j--)
            data[j + 1] = data[j];
        data[l] = x;
    }
}

int main()
{
    std::srand(std::time(0)); //menginisiasi random data
    std::vector<int> data(MAX);
    std::cout << "DATA BEFORE SORTING:\n";
    for(int i = 0; i < MAX; i++)
    {
        data[i] = std::rand() % 1000 + 1;
        std::cout << "Data[" << i << "]: " << data[i] << "\n";
    }
    // melakukan sort dengan Binary Insert sort
    BinaryInsertSort(data);
    // melakukan print dari sorted data
    std::cout << "\nDATA AFTER SORTING:\n";
    for(int i = 0; i < MAX; i++)
    {
        std::cout << "Data[" << i << "]: " << data[i] << "\n";
    }

    return 0;
}