#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <set>

size_t start_of_packet(size_t size)
{
    std::ifstream input("input.txt");
    if (!input) {
        std::cerr << "Cannot open the input.txt" << std::endl;
        exit(1);
    }

    std::string line;
    getline(input, line);
    
    for(size_t i = 0 ; i < line.size() - size; i++)
    {
        const auto subs = line.substr(i, size);
        std::set<char> s;
        bool cont{false};
        for(const auto& c : subs)
        {
            if(auto [_, b] = s.insert(c); !b)
            {
                cont = true;
                break;
            }
        }

        if(!cont)
        {
            return i+size;
        }
    }

    input.close();
    return 0;
}

void part_1()
{
    const auto t_start = std::chrono::high_resolution_clock::now();
    auto s = start_of_packet(4);
    const auto t_stop = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t_stop - t_start);

    std::cout << "Part 1: " << s << '\n';
    std::cout << "It took " << duration.count() << "us \n";
    return;
}

void part_2()
{
    const auto t_start = std::chrono::high_resolution_clock::now();
    auto b = start_of_packet(14);
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