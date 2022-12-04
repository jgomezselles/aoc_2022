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

size_t contains()
{
    std::ifstream input("input.txt");
    if (!input)
    {
        std::cerr << "Cannot open the input.txt" << std::endl;
        exit(1);
    }

    std::string line;
    size_t count{0};
    while (getline(input, line))
    {
        std::stringstream ss(line);

        std::string a, b, c, d;
        std::getline(ss, a, '-');
        std::getline(ss, b, ',');
        std::getline(ss, c, '-');
        std::getline(ss, d);

        auto ia{atoi(a.c_str())}, ib {atoi(b.c_str())}, ic {atoi(c.c_str())}, id {atoi(d.c_str())};

        count += (ia <= ic && ib >= id) || (ic <= ia && id >= ib);
    }
    input.close();

    return count;
}

void part_1()
{
    const auto t_start = std::chrono::high_resolution_clock::now();
    auto s = contains();
    const auto t_stop = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t_stop - t_start);

    std::cout << "Part 1: " << s << '\n';
    std::cout << "It took " << duration.count() << "us \n";
    return;
}

size_t overlap()
{
    std::ifstream input("input.txt");
    if (!input)
    {
        std::cerr << "Cannot open the input.txt" << std::endl;
        exit(1);
    }

    std::string line;
    size_t count{0};
    while (getline(input, line))
    {
        std::stringstream ss(line);

        std::string a, b, c, d;
        std::getline(ss, a, '-');
        std::getline(ss, b, ',');
        std::getline(ss, c, '-');
        std::getline(ss, d);

        auto ia{atoi(a.c_str())}, ib {atoi(b.c_str())}, ic {atoi(c.c_str())}, id {atoi(d.c_str())};

        count += (ib >= ic && ia <= ic) || (id >= ia && ic <= ia);
    }
    input.close();

    return count;
}

void part_2()
{
    const auto t_start = std::chrono::high_resolution_clock::now();
    auto b = overlap();
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