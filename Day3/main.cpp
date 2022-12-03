#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <chrono>
#include <sstream>
#include <numeric>
#include <map>
#include <string_view>

uint64_t priorities()
{
    std::ifstream input("input.txt");
    if (!input)
    {
        std::cerr << "Cannot open the input.txt" << std::endl;
        exit(1);
    }
    /*std::cout << "Value of a " << (size_t)'a' << '\n';
    std::cout << "Value of z " << (size_t)'z' << '\n';
    std::cout << "Value of A " << (size_t)'A' << '\n';
    std::cout << "Value of Z " << (size_t)'Z' << '\n';

    std::cout << "Value of a " << (size_t)'a' - 96 << '\n';
    std::cout << "Value of z " << (size_t)'z' - 96 << '\n';
    std::cout << "Value of A " << (size_t)'A' - 38 << '\n';
    std::cout << "Value of Z " << (size_t)'Z' - 38 << '\n';*/
    std::string line;
    uint64_t prios{0};
    while (getline(input, line))
    {
        std::string first_half = line.substr(0, line.size() / 2);
        std::string second_half = line.substr(line.size() / 2, line.size() / 2);

        for (const auto &c : second_half)
        {
            if (first_half.find(c) != first_half.npos)
            {
                size_t n(c);
                prios += n > 96 ? n - 96 : n - 38;
                break;
            }
        }
    }
    input.close();

    return prios;
}

void part_1()
{
    const auto t_start = std::chrono::high_resolution_clock::now();
    auto s = priorities();
    const auto t_stop = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t_stop - t_start);

    std::cout << "Part 1: " << s << '\n';
    std::cout << "It took " << duration.count() << "us \n";
    return;
}

std::vector<std::set<char>> get_three_lines(std::ifstream &input)
{
    std::vector<std::set<char>> v;
    std::string s;
    for (size_t i : {0, 1, 2})
    {
        if (getline(input, s))
        {
            v.emplace_back(s.begin(), s.end());
        }
    }
    return v;
}

uint64_t badges()
{
    std::ifstream input("input.txt");
    if (!input)
    {
        std::cerr << "Cannot open the input.txt" << std::endl;
        exit(1);
    }

    uint64_t prios{0};
    auto v = get_three_lines(input);
    while (!v.empty())
    {
        for (const auto &c : v[0])
        {
            if (v[1].find(c) != v[1].end() && v[2].find(c) != v[2].end())
            {
                size_t n(c);
                prios += n > 96 ? n - 96 : n - 38;
                break;
            }
        }

        v = get_three_lines(input);
    }

    input.close();

    return prios;
}

void part_2()
{
    const auto t_start = std::chrono::high_resolution_clock::now();
    auto b = badges();
    const auto t_stop = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t_stop - t_start);

    std::cout << "Part 2: " << b << '\n';
    std::cout << "It took " << duration.count() << "us \n";
    return;
}

int main()
{
    part_1();
    part_2();
    return 0;
}