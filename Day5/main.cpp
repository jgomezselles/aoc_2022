#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <chrono>
#include <sstream>
#include <numeric>
#include <map>
#include <algorithm>

void mover(std::map<size_t, std::deque<char>> &stacks, size_t i_m, size_t i_f, size_t i_t, size_t model)
{
    if (model == 9000)
    {
        for (size_t move = 0; move < i_m; move++)
        {
            stacks.at(i_t).push_back(stacks.at(i_f).back());
            stacks.at(i_f).pop_back();
        }
    }
    else if (model == 9001)
    {
        std::deque<char> to_move;
        for (size_t move = 0; move < i_m; move++)
        {
            to_move.push_front(stacks.at(i_f).back());
            stacks.at(i_f).pop_back();
        }

        for (const auto &c : to_move)
        {
            stacks.at(i_t).push_back(c);
        }
    }
}

std::string crate_mover(const size_t model)
{
    std::ifstream input("input.txt");
    if (!input)
    {
        std::cerr << "Cannot open the input.txt" << std::endl;
        exit(1);
    }

    std::string line;
    std::map<size_t, std::deque<char>> stacks;

    while (getline(input, line))
    {

        if (line.empty() || line.at(1) == '1')
        {
            continue;
        }

        if (line.at(0) != 'm')
        {
            for (size_t i = 1, j = 1; i < line.size(); i += 4, j += 1)
            {
                if (!std::isspace(line.at(i)))
                {
                    stacks[j].push_front(line.at(i));
                }
            }
            continue;
        }

        std::stringstream ss(line);
        std::string s;
        size_t i_m, i_f, i_t;
        std::getline(ss, s, ' ');
        std::getline(ss, s, ' ');
        i_m = atoi(s.c_str());
        std::getline(ss, s, ' ');
        std::getline(ss, s, ' ');
        i_f = atoi(s.c_str());
        std::getline(ss, s, ' ');
        std::getline(ss, s);
        i_t = atoi(s.c_str());

        mover(stacks, i_m, i_f, i_t, model);
    }
    input.close();

    std::string result;
    for (const auto &[_, s] : stacks)
    {
        result.push_back(s.back());
    }

    return result;
}

void part_1()
{
    const auto t_start = std::chrono::high_resolution_clock::now();
    auto s = crate_mover(9000);
    const auto t_stop = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t_stop - t_start);

    std::cout << "Part 1: " << s << '\n';
    std::cout << "It took " << duration.count() << "us \n";
    return;
}

void part_2()
{
    const auto t_start = std::chrono::high_resolution_clock::now();
    auto b = crate_mover(9001);
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