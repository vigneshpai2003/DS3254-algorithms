#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include "array.cpp"

#define uint unsigned int

void insertion_sort(int *arr, uint n)
{
    uint i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(int *arr, uint n)
{
    uint i, j, min;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;

        std::swap(arr[min], arr[i]);
    }
}

void merge(int *arr, uint left, uint mid, uint right)
{
    uint i, j, k;
    uint n1 = mid - left + 1;
    uint n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    i = 0;
    j = 0;

    for (k = left; i < n1 && j < n2; k++)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }

    for (; i < n1; i++)
    {
        arr[k] = L[i];
        k++;
    }

    for (; j < n2; j++)
    {
        arr[k] = R[j];
        k++;
    }

    delete[] L, R;
}

void merge_sort_from(int *arr, uint left, uint right)
{
    if (left >= right)
        return;

    uint mid = left + (right - left) / 2;

    merge_sort_from(arr, left, mid);
    merge_sort_from(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void merge_sort(int *arr, uint n)
{
    merge_sort_from(arr, 0, n - 1);
}

void collect_data(std::function<void(int *, uint)> algorithm, std::string fname, uint start, uint end, uint step, uint samples, uint limit = 0)
{
    std::ofstream file;
    file.open(fname);

    for (uint n = start; n <= end; n += step)
    {
        file << n << ", ";

        for (uint i = 0; i < samples; i++)
        {
            int *arr = new int[n];

            randomize_array(arr, n, limit);

            auto start = std::chrono::high_resolution_clock::now();

            algorithm(arr, n);

            auto time = std::chrono::high_resolution_clock::now() - start;

            file << time.count() << ", ";

            delete[] arr;
        }

        file << std::endl;
    }

    file.close();
}

int main()
{
    uint start = 10000, end = 200000, step = 10000, samples = 5;
    collect_data(selection_sort, "selection_sort.csv", start, end, step, samples);
    collect_data(insertion_sort, "insertion_sort.csv", start, end, step, samples);

    start = 100000, end = 2000000, step = 100000, samples = 5;
    collect_data(merge_sort, "merge_sort.csv", start, end, step, samples);

    return 0;
}
