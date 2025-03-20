#pragma once

#include "heap.h"

class PriorityQueue
{
private:
    Heap heap;

public:
    PriorityQueue(int *arr, uint n) : heap(arr, n) {}

    void enqueue(int key)
    {
        heap.insert(key);
    }

    int dequeue()
    {
        return heap.remove_max();
    }
};
