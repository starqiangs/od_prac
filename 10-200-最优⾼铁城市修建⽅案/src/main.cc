#include <iostream>
#include <map>
#include <set>
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
struct _road
{
    int begin;
    int end;
    int cost;
    bool status;
};

bool cmp(_road road1, _road road2)
{
    return road1.cost < road2.cost;
}

int main()
{
    std::string input;
    std::getline(std::cin, input);
    auto result = GetInput(input);
    int a = result[0];
    int b = result[1];
    int c = result[2];
    std::string city_road = "";
    std::string must_city_road = "";
    std::vector<_road> vec;

    for (int i = 0; i < b; i++)
    {
        std::getline(std::cin, city_road);
        auto it = GetInput(city_road);
        _road road;
        road.begin = it[0];
        road.end = it[1];
        road.cost = it[2];
        road.status = false;
        vec.push_back(road);
    }

    int ans = 0;
    for (int i = 0; i < c; i++)
    {
        std::getline(std::cin, must_city_road);
        auto it = GetInput(must_city_road);
        for (int j = 0; j < vec.size(); j++)
        {
            if (vec[j].begin == it[0] && vec[j].end == it[1])
            {
                vec[j].status = true;
            }
        }
    }

    std::sort(vec.begin(), vec.end(), cmp);
    std::set<int> my_set;
    for (auto x : vec)
    {
        if (x.status)
        {
            my_set.insert(x.end);
            ans += x.cost;
        }
    }
    for (auto x : vec)
    {
        if (!x.status)
        {
            auto it = my_set.find(x.end);
            if (it == my_set.end())
            {
                my_set.insert(x.end);
                ans += x.cost;
            }
            else
            {
                continue;
            }
        }
    }
    std::cout << ans << std::endl;

    return 0;
}