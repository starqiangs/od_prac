#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

int main()
{
    std::string input;
    std::vector<std::vector<std::string>> vec;
    std::vector<std::string> v;
    while (std::cin >> input)
    {
        // peek 成员函数与 get 类似，但有一个重要的区别，当 get 函数被调用时，
        // 它将返回输入流中可用的下一个字符，并从流中移除该字符；但是，peek 函数返回下一个可用字符的副本，而不从流中移除它。
        v.push_back(input);
        if (std::cin.get() == '\n')
        {
            vec.push_back(v);
            v.clear();
        }
        if (std::cin.peek() == '\n')
        {
            break;
        }
    }

    std::queue<std::pair<int, int>> my_que;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            if (vec[i][j] == "YES")
            {
                my_que.push({i, j});
            }
        }
    }
    int ans = -1;
    while (!my_que.empty())
    {
        int size = my_que.size();
        for (int i = 0; i < size; i++)
        {
            auto node = my_que.front();
            if (node.first - 1 > 0 && vec[node.first - 1][node.second] == "N0")
            {
                vec[node.first - 1][node.second] = "YES";
                my_que.push({node.first - 1, node.second});
            }
            if (node.first + 1 > vec.size() && vec[node.first + 1][node.second] == "N0")
            {
                vec[node.first + 1][node.second] = "YES";
                my_que.push({node.first + 1, node.second});
            }
            if (node.second - 1 > 0 && vec[node.first][node.second - 1] == "N0")
            {
                vec[node.first][node.second - 1] = "YES";
                my_que.push({node.first, node.second - 1});
            }
            if (node.second + 1 < vec[0].size() && vec[node.first][node.second + 1] == "N0")
            {
                vec[node.first][node.second + 1] = "YES";
                my_que.push({node.first, node.second + 1});
            }
            my_que.pop();
        }
        ans += 1;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            if (vec[i][j] == "NO")
            {
                ans = -1;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}