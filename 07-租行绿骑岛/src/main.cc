#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <cstddef>

std::vector<int> GetInput(std::string str)
{
    std::string input = "";
    std::vector<int> ans;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            int num = std::atoi(input.c_str());
            ans.push_back(num);
            input = "";
            continue;
        }
        else
        {
            input += str[i];
        }
    }
    if (!input.empty())
    {
        int num = std::atoi(input.c_str());
        ans.push_back(num);
    }
    return ans;
}

int main()
{
    std::string input;
    std::getline(std::cin, input);

    int car_max_weight = GetInput(input)[0];
    int people_count = GetInput(input)[1];

    std::vector<int> people_list;

    int people_weight;
    while (people_count > 0)
    {
        std::cin >> people_weight;
        people_list.push_back(people_weight);
        people_count--;
    }
    std::sort(people_list.begin(), people_list.end());

    int start = 0;
    int end = people_list.size() - 1;
    int ans = 0;
    while (start <= end)
    {
        if (people_list[end] >= car_max_weight)
        {
            ans++;
            end--;
            continue;
        }
        else
        {
            if (start == end)
            {
                ans++;
                break;
            }
            if (people_list[end] + people_list[start] <= car_max_weight)
            {
                ans++;
                start++;
                end--;
                continue;
            }
            else
            {
                ans++;
                end--;
                continue;
            }
        }
    }
    std::cout << ans << std::endl;

    return 0;
}