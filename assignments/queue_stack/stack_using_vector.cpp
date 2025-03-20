#include <vector>
#include <iostream>
#include <stdexcept>

template <class T>
class Stack
{
private:
    std::vector<T> stack;

public:
    Stack() : stack({}) {}

    void push(T value)
    {
        stack.push_back(value);
    }

    T pop()
    {
        if (stack.empty())
        {
            throw std::runtime_error("Stack is empty");
        }
        T value = stack.back();
        stack.pop_back();
        return value;
    }

    int size()
    {
        return stack.size();
    }

    bool is_empty()
    {
        return stack.empty();
    }

    bool is_full()
    {
        return false;
    }
};

int main()
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);

    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;

    return 0;
}
