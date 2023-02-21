#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        int right = 0, maxright = 0;
        for (int j = 0; j < n + 1; ++j) {
            for (int i = 0; i < n + 1; ++i) {
                if ((i - ranges[i]) < maxright || (i - ranges[i]) == maxright) {
                    if (right < i + ranges[i]) {
                        right = i + ranges[i];
                    }
                }
            }
            maxright = right;
            if (maxright > n || maxright == n) {
                return j + 1;
            }
        }
        return -1;
    }
};