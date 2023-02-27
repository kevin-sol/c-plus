#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int movesToMakeZigzag(vector<int> &nums)
    {
        int cnt1 = 0, cnt2 = 0;
        vector<int> nums2 = nums;
        for (int i = 0; i < nums.size(); i += 2) {
            if (i + 1 < nums.size() && nums[i] >= nums[i + 1]) {
                cnt1 += nums[i] - nums[i + 1] + 1;
                nums[i] = nums[i + 1] - 1;
            }
            if (i - 1 >= 0 && nums[i] >= nums[i - 1]) {
                cnt1 += nums[i] - nums[i - 1] + 1;
                nums[i] = nums[i - 1] - 1;
            }
        }
        for (int i = 1; i < nums2.size(); i += 2) {
            if (i + 1 < nums2.size() && nums2[i] >= nums2[i + 1]) {
                cnt2 += nums2[i] - nums2[i + 1] + 1;
                nums2[i] = nums2[i + 1] - 1;
            }
            if (i - 1 >= 0 && nums2[i] >= nums2[i - 1]) {
                cnt2 += nums2[i] - nums2[i - 1] + 1;
                nums2[i] = nums2[i - 1] - 1;
            }
        }
        return cnt1 > cnt2 ? cnt2 : cnt1;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums{10, 4, 4, 10, 10, 6, 2, 3};
    cout << s.movesToMakeZigzag(nums) << endl;
    system("pause");
    return 0;
}
