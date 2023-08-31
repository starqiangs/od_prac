#include <iostream>
#include <vector>

// 处理器问题-01
int main()
{
    std::string array_str;
    int number;

    std::getline(std::cin, array_str);

    std::cin >> number;

    std::vector<int> vec;
    for (int i = 0; i < array_str.size(); i++)
    {
        int num = array_str[i] - '0';
        if (num >= 0 && num <= 7)
        {
            vec.push_back(num);
        }
    }
    std::vector<int> first_arr;
    std::vector<int> second_arr;
    std::vector<int> ans;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] >= 0 && vec[i] <= 3)
        {
            first_arr.push_back(vec[i]);
        }
        else
        {
            second_arr.push_back(vec[i]);
        }
    }
    int first_size = first_arr.size();
    int second_size = second_arr.size();
    switch (number)
    {
    case 1:
        if (first_size == 1)
        {
            ans = first_arr;
            break;
        }
        else if (second_size == 1)
        {
            ans = second_arr;
            break;
        }
        else if (first_size == 3)
        {
            ans = first_arr;
            break;
        }
        else if (first_size == 3)
        {
            ans = second_arr;
            break;
        }
        else if (first_size == 2)
        {
            ans = first_arr;
            break;
        }
        else if (first_size == 2)
        {
            ans = second_arr;
            break;
        }
        else if (first_size == 4)
        {
            ans = first_arr;
            break;
        }
        else if (first_size == 4)
        {
            ans = second_arr;
            break;
        }
    case 2:
        break;
    case 4:
        break;
    case 8:
        break;
    default:
        break;
    }

    std::cout << '[';
    for (int i = 0; i < ans.size(); i++)
    {
        if(i == ans.size()-1)
        {
            std::cout << ans[i];
            break;
        }
        std::cout << ans[i] << ',';
    }
    std::cout << ']' << std::endl;

    return 0;
}