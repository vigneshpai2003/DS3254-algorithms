#include "linkedlist.h"

template <class T>
class Queue
{
private:
    LinkedList<T> queue;

public:
    Queue() : queue(LinkedList<T>()) {}

    void enqueue(T value)
    {
        queue.append(value);
    }

    T dequeue()
    {
        if (queue.is_empty())
            throw std::runtime_error("Queue is empty");
        return queue.removeFirst();
    }
};