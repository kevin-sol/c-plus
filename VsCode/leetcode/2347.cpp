#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string bestHand(vector<int> &ranks, vector<char> &suits)
    {
        if (flush(suits)) {
            return "Flush";
        } else if (threeORpair(ranks) > 2) {
            return "Three of a Kind";
        } else if (threeORpair(ranks) == 2) {
            return "Pair";
        } else {
            return "High Card";
        }
    }
    bool flush(vector<char> &suits)
    {
        char ch = suits[0];
        for (int i = 0; i < 5; i++) {
            if (suits[i] != ch) {
                return false;
            }
        }
        return true;
    }
    int threeORpair(vector<int> &ranks)
    {
        int cnt = 0;
        vector<int> nums(20);
        for (int i = 0; i < 5; i++) {
            nums[ranks[i]]++;
        }
        auto max = max_element(nums.begin(), nums.end());
        return *max;
    }
};