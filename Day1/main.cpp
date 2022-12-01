#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <chrono>
#include <sstream>
#include <numeric>

uint64_t top_three()
{
    std::ifstream input("input.txt");
    if (!input)
    {
        std::cerr << "Cannot open the input.txt" << std::endl;
        exit(1);
    }

    std::string line;
    std::multiset<uint64_t> elfs;
    uint64_t elf{0};
    while (getline(input, line))
    {
        if(line.empty())
        {
            elfs.insert(elf);
            elf = 0;
            continue;
        }

        elf += stoi(line);
    }

    if(elf > 0)
    {
        elfs.insert(elf);
    }

    input.close();

    auto rb = elfs.rbegin();
    std::advance(rb, 3);
    return std::reduce(elfs.rbegin(), rb);
}

uint64_t max_cals()
{
    std::ifstream input("input.txt");
    if (!input)
    {
        std::cerr << "Cannot open the input.txt" << std::endl;
        exit(1);
    }

    std::string line;
    uint64_t partial_sum{0}, max_sum{0};
    while (getline(input, line))
    {
        if(line.empty())
        {
            max_sum = std::max(partial_sum, max_sum);
            partial_sum = 0;
            continue;
        }

        partial_sum += stoi(line);
    }

    max_sum = std::max(partial_sum, max_sum);
    input.close();

    return max_sum;
}

void part_1()
{
    const auto t_start = std::chrono::high_resolution_clock::now();
    auto max = max_cals();
    const auto t_stop = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t_stop - t_start);

    std::cout << "Part 1: " << max << '\n';
    std::cout << "It took " << duration.count() << "us \n";
    return;
}

void part_2()
{
    const auto t_start = std::chrono::high_resolution_clock::now();
    auto tt = top_three();
    const auto t_stop = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t_stop - t_start);

    std::cout << "Part 2: " << tt << '\n';
    std::cout << "It took " << duration.count() << "us \n";
    return;
}


int main()
{
    part_1();
    part_2();
    return 0;
}