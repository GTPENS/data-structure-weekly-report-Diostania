#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

const int MAX = 10;

//fungsi untuk melakukan penukaran
void Tukar(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

//fungsi untuk melakukan sort dari Selection Sort
void SelectionSort(std::vector<int>& data)
{
    for(int i = 0; i < MAX - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < MAX; j++)
            if (data[k] > data[j])
                k = j;

        Tukar(data[i], data[k]);
    }
}

int main()
{
    std::srand(std::time(0)); //Menginisiasi random data
    std::vector<int> data(MAX);
    std::cout << "DATA BEFORE SORTING:\n";
    for(int i = 0; i < MAX; i++)
    {
        data[i] = std::rand() % 1000 + 1;
        std::cout << "Data[" << i << "]: " << data[i] << "\n";
    }

    // melakukan sort data menggunakan Selection Sort
    SelectionSort(data);

    // melakukan print dari sorted data
    std::cout << "\nDATA AFTER SORTING:\n";
    for(int i = 0; i < MAX; i++)
    {
        std::cout << "Data[" << i << "]: " << data[i] << "\n";
    }

    return 0;
}