#include <random>
#include <iostream>
#include <ctime>

void randomize_array(int *arr, unsigned int n, unsigned int limit = 0)
{
    std::srand(std::time(nullptr));

    if (limit == 0)
    {
        for (unsigned int i = 0; i < n; i++)
        {
            arr[i] = rand();
        }
    }
    else
    {
        for (unsigned int i = 0; i < n; i++)
        {
            arr[i] = rand() % limit;
        }
    }
}

void print_array(int *arr, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
