#pragma once
#include <algorithm>

#define uint unsigned int

void insertion_sort(int *arr, uint n)
{
    uint i;
    int j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
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

    delete[] L;
    delete[] R;
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

uint partition(int *arr, uint p, uint r)
{
    int x = arr[r];
    uint i = p - 1;
    for (uint j = i; j < r; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quick_sort_from(int *arr, uint p, uint r)
{
    if (p < r)
    {
        uint q = partition(arr, p, r);
        quick_sort_from(arr, p, q - 1);
        quick_sort_from(arr, q + 1, r);
    }
}

void quick_sort(int *arr, uint n)
{
    quick_sort_from(arr, 0, n - 1);
}
