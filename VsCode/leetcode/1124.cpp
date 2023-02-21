#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int longestWPI(vector<int> &hours)
    {
        int h = 0, l = 0;
        for (int i = 0;; i++) {
            if (hours[i] > 8) {
                h++;
                continue;
            } else {
                l++;
                continue;
            }
        }
        // return maxl;
    }
};