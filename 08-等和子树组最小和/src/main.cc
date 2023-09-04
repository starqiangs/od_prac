#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <cstddef>

std::vector<int> GetTotalfactor(int value)
{
    int max_count = 0;
    std::vector<int> ans;
    for (int i = 2; i <= value / 2; i++)
    {
        if (value % i == 0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

bool Spilt(const std::vector<int> &vec, std::vector<int> &flag, int number, int index)
{
    for (int i = index; i >= 0; i--)
    {
        if (flag[i] == 1)
        {
            continue;
        }
        else
        {
            if (vec[i] == number)
            {
                flag[i] = 1;
                return true;
            }
            else if (vec[i] < number)
            {
                flag[i] = 1;
                if (!Spilt(vec, flag, number - vec[i], i))
                {
                    flag[i] = 0;
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool CanSpilt(const std::vector<int> &vec, std::vector<int> &flag, int number)
{
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        if (flag[i] == 1)
        {
            continue;
        }
        if (vec[i] == number)
        {
            flag[i] = 1;
            continue;
        }
        else
        {
            int value = number - vec[i];
            flag[i] = 1;
            if (!Spilt(vec, flag, value, i))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    std::vector<int> nums;
    int total = 0;
    int nums_number = 0;
    int nums_count = 0;
    std::cin >> nums_count;
    while (nums_count > 0)
    {
        std::cin >> nums_number;
        total += nums_number;
        nums.push_back(nums_number);
        nums_count--;
    }
    std::sort(nums.begin(), nums.end());
    std::vector<int> factor_list = GetTotalfactor(total);
    int ans = total;
    std::vector<int> flag;
    for (int i = 0; i < nums.size(); i++)
    {
        flag.push_back(0);
    }

    for (int i = factor_list.size() - 1; i >= 0; i--)
    {
        for (int i = 0; i < flag.size(); i++)
        {
            flag[i] = 0;
        }
        if (CanSpilt(nums, flag, factor_list[i]))
        {
            ans = std::min(ans, factor_list[i]);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}