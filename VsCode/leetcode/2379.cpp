#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.size();
        int res = INT_MAX;
        int w = 0;
        for (int i = 0, j = 0; i < n; i++) {
            w += (blocks[i] == 'W');
            if (i >= k - 1) {
                res = min({w, res});
                w -= blocks[j] == 'W';
                j++;
            }
        }
        return res;
    }
};
