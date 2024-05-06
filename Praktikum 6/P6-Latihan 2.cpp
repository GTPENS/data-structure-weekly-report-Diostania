#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int MAX = 10;

//Fungsi untuk melakukan penukaran
void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Fungsi untuk melakukan insertion sort dan melakukan pembandingan dan perhitungan dari perubahan yang ada
void InsertionSort(std::vector<int>& data, int& comparisons, int& shifts)
{
    for(int i = 1; i < MAX; i++)
    {
        int key = data[i];
        int j = i - 1;
        comparisons++;
        while(j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j = j - 1;
            shifts++;
            comparisons++;
        }
        data[j + 1] = key;
    }
}

// Fungsi untuk melakukan binary sort dan melakukan pembandingan dan perhitungan dari perubahan yang ada
void BinaryInsertionSort(std::vector<int>& data, int& comparisons, int& shifts)
{
    for(int i = 1; i < MAX; i++)
    {
        int key = data[i];
        int left = 0;
        int right = i - 1;
        comparisons++;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(data[mid] > key)
                right = mid - 1;
            else
                left = mid + 1;
            comparisons++;
        }
        for(int j = i - 1; j >= left; j--)
        {
            data[j + 1] = data[j];
            shifts++;
        }
        data[left] = key;
    }
}

// Fungsi untuk melakukan binary sort dan melakukan pembandingan dan perhitungan dari perubahan yang ada
void SelectionSort(std::vector<int>& data, int& comparisons, int& shifts)
{
    for(int i = 0; i < MAX - 1; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j < MAX; j++)
        {
            comparisons++;
            if(data[j] < data[minIndex])
            {
                minIndex = j;
            }
        }
        Swap(data[minIndex], data[i]);
        shifts++;
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

    int comparisons_insertion = 0, shifts_insertion = 0;
    int comparisons_binary = 0, shifts_binary = 0;
    int comparisons_selection = 0, shifts_selection = 0;
    // Insertion Sort
    std::vector<int> data_insertion = data;
    InsertionSort(data_insertion, comparisons_insertion, shifts_insertion);
    // Binary Insertion Sort
    std::vector<int> data_binary = data;
    BinaryInsertionSort(data_binary, comparisons_binary, shifts_binary);
    // Selection Sort
    std::vector<int> data_selection = data;
    SelectionSort(data_selection, comparisons_selection, shifts_selection);
    // Print Results
    std::cout << "\nINSERTION SORT RESULTS:\n";
    std::cout << "Sorted Data:\n";
    for(int i = 0; i < MAX; i++)
    {
        std::cout << "Data[" << i << "]: " << data_insertion[i] << "\n";
    }
    std::cout << "Comparisons: " << comparisons_insertion << "\n";
    std::cout << "Shifts: " << shifts_insertion << "\n";
    std::cout << "\nBINARY INSERTION SORT RESULTS:\n";
    std::cout << "Sorted Data:\n";
    for(int i = 0; i < MAX; i++)
    {
        std::cout << "Data[" << i << "]: " << data_binary[i] << "\n";
    }
    std::cout << "Comparisons: " << comparisons_binary << "\n";
    std::cout << "Shifts: " << shifts_binary << "\n";
    std::cout << "\nSELECTION SORT RESULTS:\n";
    std::cout << "Sorted Data:\n";
    for(int i = 0; i < MAX; i++)
    {
        std::cout << "Data[" << i << "]: " << data_selection[i] << "\n";
    }
    std::cout << "Comparisons: " << comparisons_selection << "\n";
    std::cout << "Shifts: " << shifts_selection << "\n";
    return 0;
}