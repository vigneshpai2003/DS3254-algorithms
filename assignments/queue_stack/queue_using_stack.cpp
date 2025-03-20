#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

template <class T>
class Queue
{
private:
    stack<T> s1, s2;

public:
    void enqueue(T x)
    {
        s1.push(x);
    }

    T dequeue()
    {
        if (isEmpty())
            throw std::runtime_error("Queue is empty!");

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int front = s2.top();
        s2.pop();
        return front;
    }

    bool isEmpty()
    {
        return s1.empty() && s2.empty();
    }

    int front()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }
};
