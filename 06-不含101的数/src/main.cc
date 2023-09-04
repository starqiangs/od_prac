#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <cstddef>

std::vector<int> GetInput(std::string str)
{
    std::string number = "";
    std::vector<int> ans;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            int num = std::atoi(number.c_str());
            ans.push_back(num);
            number = "";
            continue;
        }
        else
        {
            number += str[i];
        }
    }
    if (!number.empty())
    {
        int num = std::atoi(number.c_str());
        ans.push_back(num);
    }
    return ans;
}

bool HasExist(const std::string &str)
{
    auto it = str.find("101");
    return it != std::string::npos;
}

int main()
{
    std::string input;
    std::getline(std::cin, input);
    int pre_start = 0;
    int start = GetInput(input)[0];
    pre_start = start;
    int end = GetInput(input)[1];
    int exist_number = 0;
    for (start; start <= end; start++)
    {
        std::string binary = std::bitset<32>(start).to_string();
        if (HasExist(binary))
        {
            exist_number++;
        }
    }
    int ans = end - pre_start + 1 - exist_number;
    std::cout << ans << std::endl;
    return 0;
}