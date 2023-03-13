#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*动态规划法*/
class Solution
{
public:
    int maxValue(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = max({dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]});
            }
        }
        return dp[m - 1][n - 1];
    }
};
int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
