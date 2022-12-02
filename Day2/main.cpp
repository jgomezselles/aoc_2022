#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <chrono>
#include <sstream>
#include <numeric>
#include <map>

const std::map<char, uint64_t> selection_score
{
    {'X', 1}, //Rock
    {'Y', 2}, //Paper
    {'Z', 3}  //Scissors
};

const std::map<char, char> equals
{
    {'X', 'A'}, //Rock
    {'Y', 'B'}, //Paper
    {'Z', 'C'}  //Scissors
};

const std::map<char, char> wins
{
    {'X', 'C'},
    {'Y', 'A'},
    {'Z', 'B'}
};

uint64_t score_1()
{
    std::ifstream input("input.txt");
    if (!input)
    {
        std::cerr << "Cannot open the input.txt" << std::endl;
        exit(1);
    }

    std::string line;
    uint64_t score{0};
    while (getline(input, line))
    {
        char self = line.at(2);
        score += selection_score.at(self);
        char oponent = line.at(0);

        uint64_t to_add{0};
        if(equals.at(self) == oponent)
        {
            to_add = 3;
        }
        else if(wins.at(self) == oponent)
        {
            to_add = 6;
        }
        score += to_add;
    }
    input.close();

    return score;
}

void part_1()
{
    const auto t_start = std::chrono::high_resolution_clock::now();
    auto s = score_1();
    const auto t_stop = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t_stop - t_start);

    std::cout << "Part 1: " << s << '\n';
    std::cout << "It took " << duration.count() << "us \n";
    return;
}

const std::map<char, uint64_t> round_score
{
    {'X', 0},
    {'Y', 3},
    {'Z', 6}
};

const std::map<char, char> wins_2
{
    {'A', 'C'},
    {'B', 'A'},
    {'C', 'B'}
};

const std::map<char, char> lose
{
    {'A', 'B'},
    {'B', 'C'},
    {'C', 'A'}
};

const std::map<char, uint64_t> selection_score_2
{
    {'A', 1}, //Rock
    {'B', 2}, //Paper
    {'C', 3}  //Scissors
};

uint64_t score_2()
{
    std::ifstream input("input.txt");
    if (!input)
    {
        std::cerr << "Cannot open the input.txt" << std::endl;
        exit(1);
    }

    std::string line;
    uint64_t score{0};
    while (getline(input, line))
    {
        char res = line.at(2);
        score += round_score.at(res);
        char oponent = line.at(0);
        switch (res)
        {
        case 'X':
            score += selection_score_2.at(wins_2.at(oponent));
            break;
        case 'Y':
            score += selection_score_2.at(oponent);
            break;
        case 'Z':
            score += selection_score_2.at(lose.at(oponent));
            break;
        default:
            break;
        }
    }
    input.close();

    return score;
}

void part_2()
{
    const auto t_start = std::chrono::high_resolution_clock::now();
    auto s = score_2();
    const auto t_stop = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t_stop - t_start);

    std::cout << "Part 2: " << s << '\n';
    std::cout << "It took " << duration.count() << "us \n";
    return;
}


int main()
{
    part_1();
    part_2();
    return 0;
}