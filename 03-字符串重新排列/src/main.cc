#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

std::string StringSort(std::string str)
{
    std::vector<char> vec;
    for (int i = 0; i < str.size(); i++)
    {
        vec.push_back(str[i]);
    }
    std::sort(vec.begin(), vec.end());
    std::string output;
    for (int i = 0; i < vec.size(); i++)
    {
        output += vec[i];
    }
    return output;
}

struct word
{
    int length;
    int num = 1;
    std::string str;
};

bool cmp(word word1, word word2)
{

    if (word1.num != word2.num)
    {
        return word1.num > word2.num;
    }
    else
    {
        if (word1.length != word2.length)
        {
            return word1.length < word2.length;
        }
        else
        {
            return !word1.str.compare(word2.str);
        }
    }
}

int main()
{
    std::string input;
    std::getline(std::cin, input);

    std::string str = "";
    std::vector<word> vec;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ' ')
        {
            word word;
            word.length = str.size();
            word.str = StringSort(str);
            vec.push_back(word);
            str = "";
            continue;
        }
        else
        {
            str += input[i];
        }
    }
    if (!str.empty())
    {
        word word;
        word.length = str.size();
        word.str = StringSort(str);
        vec.push_back(word);
    }
    std::unordered_map<std::string, int> my_map;
    for (auto word : vec)
    {
        auto it = my_map.find(word.str);
        if (it == my_map.end())
        {
            my_map[word.str] = 1;
        }
        else
        {
            my_map[word.str] += 1;
        }
    }
    for (auto &word : vec)
    {
        auto it = my_map.find(word.str);
        if (it != my_map.end())
        {
            word.num = it->second;
        }
    }

    std::sort(vec.begin(), vec.end(), cmp);

    for(auto x: vec)
    {
        std::cout<<x.str<<" ";
    }
    std::cout<<std::endl;
    return 0;
}