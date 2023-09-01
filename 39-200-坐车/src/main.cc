#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
#include <cstddef>

int main()
{
    int number;
    std::string weight;
    std::vector<int> store_weight;
    store_weight.push_back(0);
    std::getline(std::cin, weight);
    std::cin >> number;

    std::stringstream ss(weight);
    std::string token;
    while (std::getline(ss, token, ','))
    {
        int num = std::stoi(token);
        store_weight.push_back(num);
    }

    int arr[store_weight.size()][number + 1] = {0};

    for (int i = 0; i < store_weight.size(); i++)
    {
        // 背包容量i 物品j
        for (int j = 0; j < number + 1; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (int i = 1; i < store_weight.size(); i++)
    {
        // 背包容量i 物品j
        for (int j = 1; j < number + 1; j++)
        {
            if (store_weight[i] > j)
            {
                arr[i][j] = arr[i - 1][j];
            }
            else
            {
                //不能重复取
                if (arr[i - 1][j - store_weight[i]] + store_weight[i] > arr[i - 1][j])
                {
                    arr[i][j] = arr[i - 1][j - store_weight[i]] + store_weight[i];
                }
                else
                {
                    arr[i][j] = arr[i - 1][j];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < store_weight.size(); i++)
    {
        // 背包容量i 物品j
        for (int j = 0; j < number + 1; j++)
        {
            if (arr[i][j] == number)
            {
                ans += 1;
            }
        }
    }
    std::cout << ans << std::endl;

    return 0;
}