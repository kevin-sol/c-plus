#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<vector<bool>> conect(n, vector<bool>(n, false));
        vector<int> mp(n);
        for (auto &&i : roads) {
            conect[i[0]][i[1]] = true;
            conect[i[1]][i[0]] = true;
            mp[i[0]]++;
            mp[i[1]]++;
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int cnt = mp[i] + mp[j] - (conect[i][j] ? 1 : 0);
                ret = max(ret, cnt);
            }
        }
        return ret;
    }
};