#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> maxlocal;
        for (int i = 1; i < n - 1; i++) {
            vector<int> row;
            for (int j = 1; j < n - 1; j++) {
                row.emplace_back(max({grid[i][j], grid[i][j - 1], grid[i][j + 1], grid[i - 1][j], grid[i + 1][j],
                                      grid[i - 1][j - 1], grid[i - 1][j + 1], grid[i + 1][j - 1], grid[i + 1][j + 1]}));
            }
            maxlocal.emplace_back(row);
        }
        return maxlocal;
    }
};