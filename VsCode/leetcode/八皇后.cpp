#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    void searchQ(int n, int row, vector<int> &cur, vector<vector<string>> &rets)
    {
        if (row == n) {
            vector<string> ret(n, "");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (j == cur[i]) {
                        ret[i] += 'Q';
                    } else
                        ret[i] += '.';
                }
            }
            rets.push_back(ret);
        } else
            for (int i = 0; i < n; i++) {
                cur[row] = i;
                int f = 1;
                for (int j = 0; j < row; j++) {
                    if (cur[j] == i || j - cur[j] == row - cur[row] || j + cur[j] == row + cur[row]) {
                        f = 0;
                        break;
                    }
                }
                if (f == 1) {
                    searchQ(n, row + 1, cur, rets);
                }
            }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<int> cur(n);
        vector<vector<string>> rets;
        int cnt = 0;
        searchQ(n, 0, cur, rets);
        return rets;
    }
};
