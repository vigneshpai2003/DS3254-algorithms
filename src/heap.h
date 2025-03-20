#pragma once

#include <algorithm>
#include <climits>

#define uint unsigned int

class Heap
{
public:
    int *arr;
    uint size;

    Heap(int *arr, uint size) : arr(arr), size(size) {}

    uint left(uint i)
    {
        return 2 * i + 1;
    }

    uint right(uint i)
    {
        return 2 * i + 2;
    }

    uint parent(uint i)
    {
        return (i - 1) / 2;
    }

    void max_heapify(uint i)
    {
        uint l = left(i);
        uint r = right(i);
        uint largest = i;

        if (l < size && arr[l] > arr[largest])
            largest = l;

        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            std::swap(arr[i], arr[largest]);
            max_heapify(largest);
        }
    }

    void build_max_heap()
    {
        for (uint i = size / 2 - 1; i >= 0; i--)
            max_heapify(i);
    }

    int remove_max()
    {
        if (size < 1)
            return -1;

        int max = arr[0];
        arr[0] = arr[size - 1];
        size--;
        max_heapify(0);

        return max;
    }

    void increase_key(uint i, int key)
    {
        if (key < arr[i])
            return;

        arr[i] = key;

        while (i > 0 && arr[parent(i)] < arr[i])
        {
            std::swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void insert(int key)
    {
        size++;
        arr[size - 1] = INT_MIN;
        increase_key(size - 1, key);
    }
};
