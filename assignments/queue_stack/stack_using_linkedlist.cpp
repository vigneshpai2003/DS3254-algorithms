#include "linkedlist.h"
#include <stdexcept>

template <class T>
class Stack
{
private:
    LinkedList<T> stack;

public:
    Stack() : stack(LinkedList<T>()) {}

    void push(T value)
    {
        stack.prepend(value);
    }

    T pop()
    {
        if (stack.is_empty())
            throw std::runtime_error("Stack is empty");
        return stack.removeFirst();
    }

    int size()
    {
        return stack.size();
    }

    bool is_empty()
    {
        return (stack.size() == 0);
    }

    bool is_full()
    {
        return false;
    }
};
