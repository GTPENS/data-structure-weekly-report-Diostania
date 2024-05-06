#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

const int MAX = 10;

// Fungsi untuk melakukan penukaran
void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

//Fungsi untuk melakukan Insertion sort
void InsertionSort(std::vector<int>& data)
{
    for(int i = 1; i < MAX; i++)
    {
        int key = data[i];
        int j = i - 1;
        while(j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
        //melakukan print hasil dari insertion sort
        std::cout << "Iteration " << i << ":\t";
        for(int k = 0; k < MAX; k++)
        {
            std::cout << data[k] << " ";
        }
        std::cout << "\n";
    }
}

// Fungsi untuk melakukan binary sort
void BinaryInsertionSort(std::vector<int>& data)
{
    for(int i = 1; i < MAX; i++)
    {
        int key = data[i];
        int left = 0;
        int right = i - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(data[mid] > key)
                right = mid - 1;
            else
                left = mid + 1;
        }
        for(int j = i - 1; j >= left; j--)
        {
            data[j + 1] = data[j];
        }
        data[left] = key;
        //melakukan print hasil insertion sort
        std::cout << "Iteration " << i << ":\t";
        for(int k = 0; k < MAX; k++)
        {
            std::cout << data[k] << " ";
        }
        std::cout << "\n";
    }
}

// fungsi untuk melakukan selection sort
void SelectionSort(std::vector<int>& data)
{
    for(int i = 0; i < MAX - 1; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j < MAX; j++)
        {
            if(data[j] < data[minIndex])
            {
                minIndex = j;
            }
        }
        Swap(data[minIndex], data[i]);
        // Print iteration
        std::cout << "Iteration " << i+1 << ":\t";
        for(int k = 0; k < MAX; k++)
        {
            std::cout << data[k] << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    std::srand(std::time(0)); //menginisiasi random generator
    std::vector<int> data(MAX);
    std::cout << "DATA BEFORE SORTING:\n";
    for(int i = 0; i < MAX; i++)
    {
        data[i] = std::rand() % 1000 + 1;
        std::cout << "Data[" << i << "]: " << data[i] << "\n";
    }
    std::cout << "\nINSERTION SORT PROCESS:\n";
    InsertionSort(data);
    std::cout << "\nBINARY INSERTION SORT PROCESS:\n";
    BinaryInsertionSort(data);
    std::cout << "\nSELECTION SORT PROCESS:\n";
    SelectionSort(data);
    // print sorted data
    std::cout << "\nDATA AFTER SORTING:\n";
    for(int i = 0; i < MAX; i++)
    {
        std::cout << "Data[" << i << "]: " << data[i] << "\n";
    }
    return 0;
}
