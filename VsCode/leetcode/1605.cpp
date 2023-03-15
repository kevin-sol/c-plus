#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            M[i][0] = rowSum[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (M[i][0] == 0) {
                    break;
                }
                if (colSum[j] >= M[i][0]) {
                    M[i][j] = M[i][0];
                    colSum[j] = colSum[j] - M[i][0];
                    M[i][0] = 0;
                } else {
                    M[i][j] = colSum[j];
                    M[i][0] -= colSum[j];
                    colSum[j] = 0;
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    system("pause");
    return 0;
}