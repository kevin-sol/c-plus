#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int cnt = 0;
        int judge[101] = {0};
        for (int i = 0; i < nums.size(); i++) {
            judge[nums[i]] = 1;
        }
        for (int i = 1; i <= 100; i++) {
            if (judge[i] == 1) {
                cnt++;
            }
        }
        return cnt;
    }
};
/*class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int cnt = 0;
        int max = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.end(); i++) {
            if (nums[i] > max) {
                max = nums[i];
                cnt++;
            }
        }

        return cnt;
    }
};*/