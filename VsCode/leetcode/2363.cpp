#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
    {
        map<int, int> v_w;
        for (const auto &it : items1) {
            v_w[it[0]] += it[1];
        }
        for (const auto &it : items2) {
            v_w[it[0]] += it[1];
        }
        vector<vector<int>> items;
        for (const auto &it : v_w) {
            items.push_back({it.first, it.second});
        }
        return items;
    }
};
