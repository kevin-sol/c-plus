#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int countTriplets(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cnt[nums[i] & nums[j]]++;
            }
        }
        int res = 0;
        for (const auto &i : cnt) {
            for (const auto &j : nums) {
                if ((i.first & j) == 0) {
                    res += i.second;
                }
            }
        }
        return res;
    }
};