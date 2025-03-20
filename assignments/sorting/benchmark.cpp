#include <string>
#include <bits/stdc++.h>
#include "array_utils.h"
#include "sort.h"

void collect_data(std::function<void(int *, uint)> algorithm, std::string fname, uint start, uint end, uint step, uint samples, uint limit = 0)
{
    std::ofstream file;
    file.open(fname);

    for (uint n = start; n <= end; n += step)
    {
        file << n << " ";

        for (uint i = 0; i < samples; i++)
        {
            int *arr = new int[n];

            randomize_array(arr, n, limit);

            auto start = std::chrono::high_resolution_clock::now();

            algorithm(arr, n);

            auto time = std::chrono::high_resolution_clock::now() - start;

            file << time.count() << " ";

            delete[] arr;
        }

        file << std::endl;
    }

    file.close();
}

int main()
{
    uint start = 10000, end = 200000, step = 10000, samples = 5;
    // collect_data(selection_sort, "selection_sort.csv", start, end, step, samples);
    // collect_data(insertion_sort, "insertion_sort.csv", start, end, step, samples);

    start = 100000, end = 2000000, step = 100000, samples = 5;
    // collect_data(merge_sort, "merge_sort.csv", start, end, step, samples);

    return 0;
}
