#include <iostream>
#include <vector>

struct Node
{
    std::string pre;
    int data;
    std::string next;
};

std::vector<std::string> GetString(std::string str)
{
    std::vector<std::string> ans;
    std::string input = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            ans.push_back(input);
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
        ans.push_back(input);
    }
    return ans;
}

std::string GetNextString(std::vector<Node> vec, std::string str)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].pre == str)
        {
           return vec[i].next;
        }
    }
    return "";
}

// 单向链表-01
int main()
{
    std::string input;
    std::getline(std::cin, input);
    std::vector<Node> vec;
    int flag = 0;

    std::string start_str = GetString(input)[0];
    std::string node_num_str = GetString(input)[1];

    int node_num = std::atoi(node_num_str.c_str());
    int num = node_num;
    std::string node;
    while (node_num > 0)
    {
        getline(std::cin, node);
        Node this_node;
        std::vector<std::string> result = GetString(node);
        this_node.pre = result[0];
        this_node.data = std::atoi(result[1].c_str());
        this_node.next = result[2];
        vec.push_back(this_node);
        node_num--;
    }
    int mid_index = num / 2;
    Node ans_node;
    while (mid_index > 0)
    {
        start_str = GetNextString(vec, start_str);
        mid_index--;
    }
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].pre == start_str)
        {
            ans_node = vec[i];
            break;
        }
    }
    std::cout << ans_node.data << std::endl;

    return 0;
}