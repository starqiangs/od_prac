#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include <cstddef>

int FindMapMaxCount(std::map<int, int> my_map, int max_count)
{
    int max_value = 0;
    for (auto it : my_map)
    {
        max_value = std::max(max_value, it.second);
    }
    return max_value;
}

int main()
{
    std::string input;
    int number = 0;

    std::vector<int> vec;
    std::map<int, int> my_map;
    std::getline(std::cin, input);

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] != ' ')
        {
            int num = input[i] - '0';
            vec.push_back(num);
        }
    }
    int max_count = 0;
    std::cin >> number;
    int start = 0;
    for (int end = 0; end < vec.size(); end++)
    {
        auto it = my_map.find(vec[end]);
        if (it == my_map.end())
        {
            my_map[vec[end]] = 1;
        }
        else
        {
            my_map[vec[end]] += 1;
        }
        if (end - start + 1 == number)
        {
            max_count = FindMapMaxCount(my_map, max_count);
            if (my_map[vec[start]] == 0)
            {
                my_map.erase(vec[start]);
            }
            else
            {
                my_map[vec[start]] -= 1;
            }
            start++;
        }
    }
    std::cout << max_count << std::endl;
    return 0;
}