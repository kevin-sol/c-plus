#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int j = (i + k) % n;
            res[j] = nums[i];
        }
        nums.assign(res.begin(), res.end());
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums({1, 2, 3, 4, 5, 6, 7});
    s.rotate(nums, 3);
    system("pause");
    return 0;
}