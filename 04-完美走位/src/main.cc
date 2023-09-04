#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include <cstddef>


int main()
{
    std::map<char, int> my_map;
    std::string input;
    getline(std::cin, input);
    my_map['W'] = 0;
    my_map['A'] = 0;
    my_map['S'] = 0;
    my_map['D'] = 0;
    for (int i = 0; i < input.size(); i++)
    {
        my_map[input[i]] += 1;
    }
    int num = input.size() / 4;
    int ans = 0;
    for (auto &it : my_map)
    {
        if (it.second > num)
        {
            ans += it.second - num;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}